#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include ".\usv\USV\mavlink.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    server = new QTcpServer(this);

    //连接信号槽
    connect(server,&QTcpServer::newConnection,this,&MainWindow::server_New_Connect);

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MainWindow::simulateStep);
}

MainWindow::~MainWindow()
{
    server->close();
    server->deleteLater();
    delete ui;
}

void MainWindow::on_pushButton_listen_clicked()
{
    if(ui->pushButton_listen->text() == tr("侦听"))
       {
           //从输入框获取端口号
           int port = ui->lineEdit_port->text().toInt();

           //监听指定的端口
           if(!server->listen(QHostAddress::Any, port))
           {
               //若出错，则输出错误信息
               qDebug()<<server->errorString();
               return;
           }
           //修改按键文字
           ui->pushButton_listen->setText("取消侦听");
           qDebug()<< "Listen succeessfully!";
       }
       else
       {
//           //如果正在连接
//           if( socket->state() == QAbstractSocket::ConnectedState)
//           {
//               //关闭连接
//               socket->disconnectFromHost();
//           }
          // socket->abort();
           //取消侦听
           server->close();
           //修改按键文字
           ui->pushButton_listen->setText("侦听");
           //发送按键失能
          // ui->pushButton_Send->setEnabled(false);
       }
}

void MainWindow::server_New_Connect()
{
    //获取客户端连接
    socket = server->nextPendingConnection();
    //连接QTcpSocket的信号槽，以读取新数据
    QObject::connect(socket, &QTcpSocket::readyRead, this, &MainWindow::socket_Read_Data);
    //QObject::connect(socket, &QTcpSocket::disconnected, this, &MainWindow::socket_Disconnected);
    //发送按键使能
    //ui->pushButton_Send->setEnabled(true);

    qDebug() << "A Client connect!";
}

void MainWindow::socket_Read_Data()
{
    QByteArray buffer = socket -> readAll(); //读取数据
    mavlink_message_t msg;
    mavlink_status_t status;
    for (int i = 0;i<buffer.length();i++) {
        char c = buffer[i] ;
        if(mavlink_parse_char(MAVLINK_COMM_0,static_cast<unsigned char>(c),&msg,&status))
        {
            //qDebug()<<msg.msgid;
            switch (msg.msgid) {
            case MAVLINK_MSG_ID_USV_BALL:
            {
                int ballId = mavlink_msg_usv_ball_get_ball_id(&msg);
                double ballLng = mavlink_msg_usv_ball_get_ball_lon(&msg)/10000000.0;
                double ballLat = mavlink_msg_usv_ball_get_ball_lat(&msg)/10000000.0;
                int ballColorIndex = mavlink_msg_usv_ball_get_ball_color(&msg);
                qDebug()<<ballId;
                //usv.getBalls(ballId,ballLng,ballLat,ballColorIndex);
                if( ballId == usv.ballCount-1)
                {
                    if(usv.balls.length() == usv.ballCount)
                    {
                        mavlink_message_t msg;
                        unsigned char buf[25];
                        mavlink_msg_gcs_set_or_usv_ack_pack(2,2,&msg,1,0,0,0);
                        uint16_t len = mavlink_msg_to_send_buffer(buf,&msg);
                        socket -> write(reinterpret_cast<char*>(buf),len);
                        qDebug()<<"初始化完成，球接收完毕";
                    }
                }
            }
                break;
            case MAVLINK_MSG_ID_GCS_COMMOND:
            {
                usv.kp = mavlink_msg_gcs_commond_get_P(&msg);
                usv.ki = mavlink_msg_gcs_commond_get_I(&msg);
                usv.kd = mavlink_msg_gcs_commond_get_D(&msg);
                usv.runFlag = mavlink_msg_gcs_commond_get_Stop_flag(&msg);
                if(usv.runFlag)
                    timer->start(200);
                else {
                    timer->stop();
                }
            }
                break;
            case MAVLINK_MSG_ID_GCS_SIMULATION_STATUS:
            {
                usv.lng = mavlink_msg_gcs_simulation_status_get_ball_lon(&msg)/10000000.0;
                usv.lat = mavlink_msg_gcs_simulation_status_get_ball_lat(&msg)/10000000.0;
                usv.course = mavlink_msg_gcs_simulation_status_get_course(&msg);
            }
                break;
            case MAVLINK_MSG_ID_GCS_SET_OR_USV_ACK:
            {
                uint8_t type = mavlink_msg_gcs_set_or_usv_ack_get_type(&msg);
                switch (type) {
                case 1:
                {
                    //usv.ballCount = mavlink_msg_gcs_set_or_usv_ack_get_content0(&msg);
                    usv.init();
                    qDebug()<<QString("初始化开始，开始接收球，需接收%1个球").arg(usv.ballCount);
                }
                    break;
                case 2:
                {
                    usv.home_lng = mavlink_msg_gcs_set_or_usv_ack_get_content0(&msg)/10000000.0;
                    usv.home_lat = mavlink_msg_gcs_set_or_usv_ack_get_content1(&msg)/10000000.0;
                    usv. home_course = mavlink_msg_gcs_set_or_usv_ack_get_content2(&msg);
                    usv.lng = usv.home_lng;
                    usv.lat = usv.home_lat;
                    usv.course = usv.home_course;

                    mavlink_message_t msg;
                    unsigned char buf[25];
                    mavlink_msg_gcs_set_or_usv_ack_pack(2,2,&msg,2,0,0,0);
                    uint16_t len = mavlink_msg_to_send_buffer(buf,&msg);
                    socket -> write(reinterpret_cast<char*>(buf),len);

                    qDebug()<<QString("设置原点：%1,%2,%3").arg(usv.home_lng,0,'f',7).arg(usv.home_lat,0,'f',7).arg(usv.home_course);
                }
                    break;
                case 3:
                {
                    usv.end_lng = mavlink_msg_gcs_set_or_usv_ack_get_content0(&msg)/10000000.0;
                    usv.end_lat = mavlink_msg_gcs_set_or_usv_ack_get_content1(&msg)/10000000.0;
                    mavlink_message_t msg;
                    unsigned char buf[25];
                    mavlink_msg_gcs_set_or_usv_ack_pack(2,2,&msg,3,0,0,0);
                    uint16_t len = mavlink_msg_to_send_buffer(buf,&msg);
                    socket -> write(reinterpret_cast<char*>(buf),len);

                    qDebug()<<QString("设置终点：%1,%2").arg(usv.end_lng,0,'f',7).arg(usv.end_lat,0,'f',7);
                }
                    break;
                default:
                    break;
                }
            }
                break;
            default:
                break;
            }
        }
    }
}

void MainWindow::simulateStep()
{
    static int searchedCount = usv.searchedBall.length();
    usv.simulate();
    if(usv.done)
        timer->stop();
    qDebug()<<usv.stage<<usv.desiredX<<usv.desiredY<<usv.x<<usv.y<<usv.lng<<usv.lat<<usv.desired_course<<usv.cmdTurn;
    mavlink_message_t msg;
    unsigned char buf[25];
    mavlink_msg_usv_simulation_commond_pack(2,2,&msg,usv.desiredBallId,usv.cmdVel,usv.cmdTurn);
    uint16_t len = mavlink_msg_to_send_buffer(buf,&msg);
    socket -> write(reinterpret_cast<char*>(buf),len);
    if(searchedCount != usv.searchedBall.length())
    {
        mavlink_msg_usv_ball_pack(2,2,&msg,usv.searchedBall.length()-1,usv.searchedBall.last()->color,usv.searchedBall.last()->lat*10000000,usv.searchedBall.last()->lng*10000000);
        len = mavlink_msg_to_send_buffer(buf,&msg);
        socket -> write(reinterpret_cast<char*>(buf),len);
        searchedCount = usv.searchedBall.length();
        qDebug()<<"send ball";
    }
}
