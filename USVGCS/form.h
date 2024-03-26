#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QtCharts/QChartGlobal>
#include <QtCharts/QChart>
#include <chart.h>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    void initChart();
    void setX(double x);
    void setY(double y);
    void setVelocity(float velocity);
    void setCourse(float course);
    void setVel(float cmd_vel);
    void setTurn(float cmd_turn);


private slots:
    void on_StartAndStop_clicked();


    void on_Clear_clicked();


    void slotTimeout();


    void on_showVelocity_clicked();


    void on_showXY_clicked();


    void on_showCourse_clicked();


    void on_showVel_clicked();


    void on_showTurn_clicked();


private:
    Ui::Form *ui;

    QValueAxis *m_axisX;
    QValueAxis *m_axisY;
    QLineSeries *m_lineSeries;
    QChart *m_chart;
    QTimer *timer1;
    int pointCount=0;
    double m_time=0;
    double t=0;

//**各种坐标轴范围***************************************
    int AXIS_MAX_X=20,AXIS_MIN_X=-5;
    int AXIS_MAX_Y=100,AXIS_MIN_Y=-5;

    int AXIS_MAX_velocity=7.5,AXIS_MIN_velocity=0;
    int AXIS_MAX_Course=360,AXIS_MIN_Course=0;
    int AXIS_MAX_vel=3,AXIS_MIN_vel=0;
    int AXIS_MAX_turn=2.5,AXIS_MIN_turn=-2.5;
    int AXIS_MAX_t=60,AXIS_MIN_t=0;
//**各种坐标轴范围***************************************

    double x=0,y=0;
    double velocity=0,course=0,cmd_vel=0,cmd_turn=0;
    double *virX=&x,*virY=&y;

    int *AXIS_MAX_virX=&AXIS_MAX_X,*AXIS_MIN_virX=&AXIS_MIN_X;
    int *AXIS_MAX_virY=&AXIS_MAX_Y,*AXIS_MIN_virY=&AXIS_MIN_Y;
};

#endif // FORM_H
