#ifndef USV_H
#define USV_H
#include <QVector>
#include <QTime>

enum BAllCOLOR{red,blue,yellow,green,black};

class BALL{
public:
    BALL();
    BALL(double Lng,double Lat, BAllCOLOR Color):lng(Lng),lat(Lat),color(Color){}
    double lng,lat;
    BAllCOLOR color;
};

class USV
{
public:
    USV();
    ~USV();
    QVector<BALL*> balls;
    uint8_t stage;
    double current_x,current_y;
    double current_lng,current_lat;
    double current_course;
    float velocity,cmd_vel,cmd_turn;

    void setHome(double lng, double lat, double course);
    void calculate_xy();
    void xytowgs84();

private:
    const double e = 0.003352810664;
    const double a = 6378137;
    uint cal_index;
    double home_lng,home_lat,home_course;
};

#endif // USV_H
