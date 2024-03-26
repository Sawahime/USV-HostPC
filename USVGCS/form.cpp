#include "form.h"
#include "ui_form.h"
#include <QDebug>

#include <chart.h>
#include <QChartView>
#include <QLineSeries>
#include <QFile>
#include <QTextStream>


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    timer1 = new QTimer(this);
    timer1 -> setSingleShot(false);//设置成非单发计时器，否则只触发一次
    //connect(timer1,SIGNAL(timeout()),this,SLOT(slotTimeout()));
    connect(this->timer1, &QTimer::timeout, this, [=](){slotTimeout();});

    //connect(ui->StartAndStop,SIGNAL(clicked(bool)),this,SLOT(on_Start_clicked()),Qt::UniqueConnection);

    initChart();
}

Form::~Form()
{
    delete ui;
    timer1->stop();
}


//  设置参数******************************************************
void Form::setX(double x)
{
    this->x=x;
}

void Form::setY(double y)
{
    this->y=y;
}

void Form::setVelocity(float velocity)
{
    this->velocity=double(velocity);
}

void Form::setCourse(float course)
{
    this->course=course;
}

void Form::setVel(float cmd_vel)
{
    this->cmd_vel=cmd_vel;
}

void Form::setTurn(float cmd_turn)
{
    this->cmd_turn=cmd_turn;
}
//***************************************************************


void Form::initChart()
{
    // 创建横纵坐标轴并设置显示范围
    m_axisX = new QValueAxis();
    m_axisY = new QValueAxis();
    m_axisX->setTitleText("X");
    m_axisY->setTitleText("Y");
    m_axisX->setMin(AXIS_MIN_X);
    m_axisY->setMin(AXIS_MIN_Y);
    m_axisX->setMax(AXIS_MAX_X);
    m_axisY->setMax(AXIS_MAX_Y);

    m_lineSeries = new QLineSeries();                             // 创建曲线绘制对象
    m_lineSeries->setPointsVisible(true);                         // 设置数据点可见
    m_lineSeries->setName("Y-X曲线 ");                            // 图例名称

    m_chart = new QChart();                                        // 创建图表对象
    m_chart->addAxis(m_axisY, Qt::AlignLeft);                      // 将Y轴添加到图表上
    m_chart->addAxis(m_axisX, Qt::AlignBottom);                    // 将X轴添加到图表上
    m_chart->addSeries(m_lineSeries);                              // 将曲线对象添加到图表上
    m_chart->setAnimationOptions(QChart::SeriesAnimations);        // 动画：能使曲线绘制显示的更平滑，过渡效果更好看

    m_lineSeries->attachAxis(m_axisX);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后
    m_lineSeries->attachAxis(m_axisY);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后

    ui->graphicsView->setChart(m_chart);                           // 将图表对象设置到graphicsView上进行显示
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
}


void Form::on_StartAndStop_clicked()
{
    if(timer1->isActive())
    {
        //qDebug()<<"timer1 is"<<timer1->isActive();
        timer1->stop();
        qDebug()<<"timer1 stop";
        ui->StartAndStop->setText("Start");
    }else
    {
        //pointCount = 0;
        timer1->start(200);
        qDebug()<<"timer1 start";
        ui->StartAndStop->setText("Stop");
    }
    //qDebug()<<"Start";
}


void Form::on_Clear_clicked()
{
    m_lineSeries->clear();
    m_chart->axisX()->setMin(0);
    m_chart->axisX()->setMax(AXIS_MAX_X);
    pointCount = 0;
    m_time=0;
    qDebug()<<"Clear";
}


void Form::slotTimeout()
{
    if(*virX > *AXIS_MAX_virX)
    {
        //m_lineSeries->remove(0);
        //m_chart->axisX()->setMin(x - AXIS_MAX_X);
        m_chart->axisX()->setMax(*virX+10);                    // 更新X轴范围
    }
    if(*virY > *AXIS_MAX_virY)
    {
        //m_lineSeries->remove(0);
        //m_chart->axisY()->setMin(y - AXIS_MAX_Y);
        m_chart->axisY()->setMax(*virY+10);                    // 更新y轴范围
    }
    //qDebug()<<"chart.x="<<x<<"chart.y="<<y;
    m_lineSeries->append(QPointF(*virX, *virY));
    pointCount++;
    m_time++;   //m_time每200ms加1
    t=m_time/5; //m_time除5=秒
    //qDebug()<<"Timeout"<<pointCount-1;

}


void Form::on_showXY_clicked()
{
    if(AXIS_MAX_virY!=&AXIS_MAX_Y)
    {
        m_lineSeries->clear();
        m_axisX->setTitleText("X");
        m_axisY->setTitleText("Y");
        m_axisX->setMin(AXIS_MIN_X);
        m_axisY->setMin(AXIS_MIN_Y);
        m_axisX->setMax(AXIS_MAX_X);
        m_axisY->setMax(AXIS_MAX_Y);
        m_lineSeries->setName("Y-X曲线 ");

        virX=&x;
        virY=&y;
        AXIS_MAX_virX=&AXIS_MAX_X;
        AXIS_MAX_virY=&AXIS_MAX_Y;
    }
}


void Form::on_showVelocity_clicked()
{
    if(AXIS_MAX_virY!=&AXIS_MAX_velocity)
    {
        m_lineSeries->clear();
        m_axisX->setTitleText("t");
        m_axisY->setTitleText("Velocity");
        m_axisX->setMin(AXIS_MIN_t);
        m_axisY->setMin(AXIS_MIN_velocity);
        m_axisX->setMax(AXIS_MAX_t);
        m_axisY->setMax(AXIS_MAX_velocity);
        m_lineSeries->setName("Velocity-t曲线 ");

        virX=&t;
        virY=&velocity;
        AXIS_MAX_virX=&AXIS_MAX_t;
        AXIS_MAX_virY=&AXIS_MAX_velocity;
    }
}


void Form::on_showCourse_clicked()
{
    if(AXIS_MAX_virY!=&AXIS_MAX_Course)
    {
        m_lineSeries->clear();
        m_axisX->setTitleText("t");
        m_axisY->setTitleText("Course");
        m_axisX->setMin(AXIS_MIN_t);
        m_axisY->setMin(AXIS_MIN_Course);
        m_axisX->setMax(AXIS_MAX_t);
        m_axisY->setMax(AXIS_MAX_Course);
        m_lineSeries->setName("Course-t曲线 ");

        virX=&t;
        virY=&course;
        AXIS_MAX_virX=&AXIS_MAX_t;
        AXIS_MAX_virY=&AXIS_MAX_Course;
    }
}


void Form::on_showVel_clicked()
{
    if(AXIS_MAX_virY!=&AXIS_MAX_vel)
    {
        m_lineSeries->clear();
        m_axisX->setTitleText("t");
        m_axisY->setTitleText("cmd_vel");
        m_axisX->setMin(AXIS_MIN_t);
        m_axisY->setMin(AXIS_MIN_vel);
        m_axisX->setMax(AXIS_MAX_t);
        m_axisY->setMax(AXIS_MAX_vel);
        m_lineSeries->setName("cmd_vel-t曲线 ");

        virX=&t;
        virY=&cmd_vel;
        AXIS_MAX_virX=&AXIS_MAX_t;
        AXIS_MAX_virY=&AXIS_MAX_vel;
    }
}


void Form::on_showTurn_clicked()
{
    if(AXIS_MAX_virY!=&AXIS_MAX_turn)
    {
        m_lineSeries->clear();
        m_axisX->setTitleText("t");
        m_axisY->setTitleText("cmd_turn");
        m_axisX->setMin(AXIS_MIN_t);
        m_axisY->setMin(AXIS_MIN_turn);
        m_axisX->setMax(AXIS_MAX_t);
        m_axisY->setMax(AXIS_MAX_turn);
        m_lineSeries->setName("cmd_turn-t曲线 ");

        virX=&t;
        virY=&cmd_turn;
        AXIS_MAX_virX=&AXIS_MAX_t;
        AXIS_MAX_virY=&AXIS_MAX_turn;
    }
}

