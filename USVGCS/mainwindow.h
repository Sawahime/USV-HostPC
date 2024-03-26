#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif

#include <QMainWindow>
#include <QWebEnginePage>
#include <QWebChannel>
#include <QTcpSocket>
#include <QButtonGroup>
#include <QSerialPort>
#include "usv.h"
#include "form.h"
#include <QTimer>
#include <QString>
#include <QStringList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(QString transStatus MEMBER isOut)

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //**********************************************************
    double get_usv_current_x();
    double get_usv_current_y();

    void write_csv(QString string);
    void write_csv_data(QString string);

    void updataChart(double current_x,double current_y,double velocity,double current_course,double cmd_vel,double cmd_turn);
    void updataTrackLabel(double x,double y,double lng,double lat,double velocity,double course,double vel,double turn);

    QString isOut;
    //**********************************************************

public slots:
    void getMousePoint(QString lng, QString lat);
    void getBalls(int ballId, double ballLng, double ballLat, int ballColor);
    void whetherOut(const QString &msg);
    void getCsvName(const QString &Y,const QString &M,const QString &D,const QString &h,const QString &m,const QString &s);

private slots:
    void readTcpData();

    void showTcpError(QAbstractSocket::SocketError socketError);

    void on_pushButton_addBall_clicked();

    void on_pushButton_connect_clicked();

    void on_pushButton_sendCommond_clicked();

    void on_pushButton_clearMap_clicked();

    void on_pushButton_showoverlays_clicked();

    void on_pushButton_test_clicked();

    void on_actionReload_Map_triggered();

    void on_actionRuler_triggered();

    void on_pushButton_simulatorInit_clicked();

    void on_pushButton_setHome_clicked();

    void on_pushButton_simulatorStart_clicked();

    void on_pushButton_setEnd_clicked();

    void on_pushButton_serial_search_clicked();

    void on_pushButton_serial_open_clicked();

    void on_pushButton_trackBack_clicked();

    void slotTimeout();

    void on_pushButton_getCsvFile_clicked();

private:
    Ui::MainWindow *ui;
    QWebChannel *channel;
    QWebEnginePage *page;
    QTcpSocket *tcpClinet;
    QButtonGroup *runOrStopGroup;
    USV usv;
    QSerialPort *serial;

    //************************************************************************
    QString csv_name;
    QString mapPath="F:/Qt/Projects/WGS84/bdmap/map.html";

    Form my_chart;

    QString trackFilePath;
    QStringList rows,cols;
    QTimer *trackTimer;
    int row_i=0;
    bool isFileError=false;
    //************************************************************************

    void updateLabel();
    void sendSimUSVStatus();

};

#endif // MAINWINDOW_H
