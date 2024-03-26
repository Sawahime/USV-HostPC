#include "usv.h"
#include <QtMath>
#include <QDebug>

BALL::BALL()
{

}


USV::USV()
{

}

USV::~USV(){
}

void USV::calculate_xy(){
    static int dt = 200;  //步长
    static QTime lastTime = QTime::currentTime();
    velocity = cmd_vel*5;  //cmd_vel(-1,1),最大航速5m/s，假设简单线性映射
    double yaw_rate = static_cast<double>(cmd_turn)*50;  //cmd_turn(-1(l),1(r)),假设最大转速收率30°/s，线性映射

    double mean_course = current_course + yaw_rate*dt/2000.0;
    if(mean_course > 360)
        mean_course -=360;
    if(mean_course < 0)
        mean_course += 360;
    mean_course = mean_course/180*M_PI;
    double vx = static_cast<double>(velocity)*cos(mean_course);
    double vy = static_cast<double>(velocity)*sin(mean_course);
    current_x += vx*dt/1000.0;
    current_y += vy*dt/1000.0;

    current_course += yaw_rate*dt/1000.0;
    if(current_course > 360)
        current_course -=360;
    if(current_course < 0)
        current_course += 360;


    lastTime = QTime::currentTime();
    //qDebug()<<vx<<vy<<current_x<<current_y<<cmd_turn<<yaw_rate<<current_course;
    //qDebug()<<"usv.x="<<current_x<<"usv.y="<<current_y;
    qDebug()<<"usv.x="<<current_lng<<"usv.y="<<current_lat;
}

void USV::xytowgs84(){
    static double last_lat = home_lat/180*M_PI;
    double b = 1-pow(e*sin(last_lat),2);
    double dLat = pow(b,1.5)/(a*(1-e*e))*current_x*180/M_PI;
    double dLng = sqrt(b)/(a*cos(last_lat))*current_y*180/M_PI;
    current_lat = dLat+home_lat;
    current_lng = dLng+home_lng;
}

void USV::setHome(double lng, double lat, double course){
    home_lng = lng;
    home_lat = lat;
    home_course = course;
}
