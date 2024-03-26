#ifndef USV_H
#define USV_H
#include <QVector>

enum BAllCOLOR{red,blue,yellow,green,black};

class BALL{
public:
    BALL();
    BALL(double Lng,double Lat, BAllCOLOR Color):lng(Lng),lat(Lat),color(Color){}
    double lng,lat;
    double x,y;
    BAllCOLOR color;
};

class USV
{
public:
    USV();
    ~USV();
    QVector<BALL*> searchedBall;
    QVector<BALL*> balls;
    int ballCount;
    double home_lng,home_lat,home_course;
    double end_lng,end_lat;
    double lng,lat,x,y;
    float kp,ki,kd,course;
    bool runFlag;
    int desiredBallId=0;
    double desiredX,desiredY;
    double desired_course,distance_to_desiredPos;
    float cmdVel,cmdTurn;
    bool done = false;

    bool planFlag = false;
    int planCount;
    double* planX;
    double* planY;

    int stage = 1;
    void init();
    void simulate();
    void ballWgs84toxy();
    void getBalls(int ballId, double ballLng, double ballLat, int ballColor);

private:
    const double a = 6378137;
    const double e = 0.003352810664;
    const double critiacl_diatance = 3;
    const double searchDis = 20;
    double midx,midy;  //01绿球连线的中点
    void updateXY();
    void update_desired_point();
    void wgs84toxy(int id, double &x, double &y);
    void wgs84toxy(double lng,double lat, double &x, double &y);
    void update_distance_and_desired_course();
    void controller();
    void searchBall();
    void planPoint();
    void rbbPlan(BAllCOLOR);
};

#endif // USV_H
