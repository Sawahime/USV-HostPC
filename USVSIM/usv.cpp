#include "usv.h"
#include <QtMath>
#include <QDebug>

USV::USV()
{

}
USV::~USV()
{
    delete [] planX; planX = nullptr;
    delete [] planY; planY = nullptr;
}

void USV::updateXY(){
    double b = lat/180*M_PI;
    double dB = lat-home_lat;
    double dL = lng-home_lng;
    x = a*(1-pow(e,2))/pow(1-pow(e,2)*pow(sin(b),2),1.5)*M_PI/180*dB;
    y = a*cos(b)/sqrt(1-pow(e,2)*pow(sin(b),2))*M_PI/180*dL;
}

void USV::update_desired_point()
{
    static double last_distance;
    if(desiredBallId == 0)
    {
        //wgs84toxy(desiredBallId,desiredX,desiredY);
        desiredX = planX[desiredBallId];
        desiredY = planY[desiredBallId];
    }
    if(last_distance >= critiacl_diatance && distance_to_desiredPos <= critiacl_diatance)
    {
        if(desiredBallId < planCount-1)
        {
            desiredBallId++;
            desiredX = planX[desiredBallId];
            desiredY = planY[desiredBallId];
        }
        else {  //跑完了该航程最后一个规划点
            if(stage == 6)
            {
                done = true;
            }
            else {
                stage++;
                desiredBallId = 0;
                planFlag = false;
            }
        }
        //wgs84toxy(desiredBallId%searchedBall.length(),desiredX,desiredY);
    }
    //wgs84toxy(end_lng,end_lat,desiredX,desiredY);
    last_distance = distance_to_desiredPos;
}

void USV::wgs84toxy(int id, double &x, double &y) //将任务航点84坐标转化为xy
{
    if(ballCount > 0 && balls.length() == ballCount)
    {
        double b = balls.at(id)->lat/180*M_PI;
        double dB = balls.at(id)->lat-home_lat;
        double dL = balls.at(id)->lng-home_lng;
        x = a*(1-pow(e,2))/pow(1-pow(e,2)*pow(sin(b),2),1.5)*M_PI/180*dB; //X坐标（向北为正，单位米）
        y = a*cos(b)/sqrt(1-pow(e,2)*pow(sin(b),2))*M_PI/180*dL; //Y坐标（向东为正，单位米）
    }
}
void USV::wgs84toxy(double lng,double lat, double &x, double &y)
{
    double b = lat/180*M_PI;
    double dB = lat-home_lat;
    double dL = lng-home_lng;
    x = a*(1-pow(e,2))/pow(1-pow(e,2)*pow(sin(b),2),1.5)*M_PI/180*dB; //X坐标（向北为正，单位米）
    y = a*cos(b)/sqrt(1-pow(e,2)*pow(sin(b),2))*M_PI/180*dL; //Y坐标（向东为正，单位米）
}

void USV::update_distance_and_desired_course()
{
    double dx = desiredX-x;
    double dy = desiredY-y;
    desired_course = atan2(dy,dx)/M_PI*180;
    if(desired_course < 0)
    {
        desired_course +=360;
    }
    distance_to_desiredPos= sqrt(pow(desiredX-x,2)+pow(desiredY-y,2));
    //lateral_distance = ((current_desired_y - last_desired_y) * boat_X + (last_desired_x - current_desired_x) * boat_Y - last_desired_x * current_desired_y + current_desired_x * last_desired_y) / sqrt(pow(current_desired_x-last_desired_x,2) + pow(current_desired_y-last_desired_y,2));
}

void USV::controller()
{
    double course_err = desired_course-static_cast<double>(course);
    static double integral_err = 0;
    static double last_err = 0;
    if(course_err >180)
        course_err = course_err - 360;
    if(course_err < -180)
        course_err = course_err + 360;
    integral_err += course_err*0.2;
    if(integral_err>50)
        integral_err = 50;
    if(integral_err<-50)
        integral_err = -50;
    cmdTurn = kp*course_err+ki*integral_err+kd*(course_err-last_err)/0.2;
    if(cmdTurn>1.0)
        cmdTurn = 1.0f;
    if(cmdTurn<-1.0)
        cmdTurn = -1.0f;
    last_err = course_err;

    cmdVel = distance_to_desiredPos/10;
    if(cmdVel>1)
    cmdVel = 1.0f;
}

void USV::ballWgs84toxy()
{
    for (int i=0;i<balls.length();i++) {
        wgs84toxy(i,balls[i]->x,balls[i]->y);
    }
}

void USV::searchBall()
{
    static int searchedBallsCount = 0;
    switch (stage) {
    case 1:
    {
        double dis0=sqrt(pow(x-balls.at(0)->x,2)+pow(y-balls.at(0)->y,2));
        double dis1 = sqrt(pow(x-balls.at(1)->x,2)+pow(y-balls.at(1)->y,2));
        if(searchedBall.length() == 0)
        {
            if(dis0<searchDis)
            {
                searchedBall.append(balls[0]);
                qDebug()<<"searched0"<<searchedBall.at(0)->x<<searchedBall.at(0)->y<<balls.at(0)->x<<balls.at(0)->y;
            }
            if(dis1<searchDis)
            {
                 searchedBall.append(balls[1]);
                 qDebug()<<"searched1"<<searchedBall.at(0)->x<<searchedBall.at(0)->y<<balls.at(1)->x<<balls.at(1)->y;
            }
        }
        else if(searchedBall.length() == 1)
        {
            if(dis0<searchDis)
                if((pow(searchedBall.at(0)->x-balls.at(0)->x,2)+pow(searchedBall.at(0)->y-balls.at(0)->y,2))>10)
                {
                    searchedBall.append(balls.at(0));
                    qDebug()<<"searched0"<<searchedBall.at(1)->x<<searchedBall.at(1)->y<<balls.at(0)->x<<balls.at(0)->y;
                }

            if(dis1<searchDis)
                if((pow(searchedBall.at(0)->x-balls.at(1)->x,2)+pow(searchedBall.at(0)->y-balls.at(1)->y,2))>10)
                {
                    searchedBall.append(balls.at(1));
                    qDebug()<<"searched1"<<searchedBall.at(1)->x<<searchedBall.at(1)->y<<balls.at(1)->x<<balls.at(1)->y;
                }

        }
        qDebug()<<"dis"<<dis0<<dis1;
    }
        break;
    case 2:
    {
        if(searchedBall.length() == 2)
        {
            double dis2 = sqrt(pow(x-balls.at(2)->x,2)+pow(y-balls.at(2)->y,2));
            if(dis2<searchDis)
            {
                searchedBall.append(balls.at(2));
                qDebug()<<"searched2"<<searchedBall.at(2)->x<<searchedBall.at(2)->y<<balls.at(2)->x<<balls.at(2)->y;
            }
            qDebug()<<"dis2"<<dis2;
        }
    }
        break;
    case 3:
    {
        if(searchedBall.length() == 3)
        {
            double dis3 = sqrt(pow(x-balls.at(3)->x,2)+pow(y-balls.at(3)->y,2));
            if(dis3<20)
            {
                searchedBall.append(balls.at(3));
                qDebug()<<"searched3"<<searchedBall.at(3)->x<<searchedBall.at(3)->y<<balls.at(3)->x<<balls.at(3)->y;
            }
            qDebug()<<"dis3"<<dis3;
        }

    }
        break;
    case 4:
    {
        if(searchedBall.length() == 4)
        {
            double dis4 = sqrt(pow(x-balls.at(4)->x,2)+pow(y-balls.at(4)->y,2));
            if(dis4<searchDis)
            {
                searchedBall.append(balls.at(4));
                qDebug()<<"searched4"<<searchedBall.at(4)->x<<searchedBall.at(4)->y<<balls.at(4)->x<<balls.at(4)->y;
            }
            qDebug()<<"dis4"<<dis4;
        }
    }
        break;
    case 5:
    {
        double dis5= sqrt(pow(x-balls.at(5)->x,2)+pow(y-balls.at(5)->y,2));
        double dis6 = sqrt(pow(x-balls.at(6)->x,2)+pow(y-balls.at(6)->y,2));
        if(searchedBall.length() == 5)
        {
            if(dis5<searchDis)
            {
                searchedBall.append(balls[5]);
                qDebug()<<"searched5"<<searchedBall.at(5)->x<<searchedBall.at(5)->y<<balls.at(5)->x<<balls.at(5)->y;
            }
            if(dis6<searchDis)
            {
                 searchedBall.append(balls[6]);
                 qDebug()<<"searched6"<<searchedBall.at(6)->x<<searchedBall.at(6)->y<<balls.at(6)->x<<balls.at(6)->y;
            }
        }
        else if(searchedBall.length() == 6)
        {
            if(dis5<searchDis)
                if((pow(searchedBall.at(5)->x-balls.at(5)->x,2)+pow(searchedBall.at(5)->y-balls.at(5)->y,2))>10)
                {
                    searchedBall.append(balls.at(5));
                    qDebug()<<"searched5"<<searchedBall.at(6)->x<<searchedBall.at(6)->y<<balls.at(5)->x<<balls.at(5)->y;
                }

            if(dis6<searchDis)
                if((pow(searchedBall.at(5)->x-balls.at(6)->x,2)+pow(searchedBall.at(5)->y-balls.at(6)->y,2))>10)
                {
                    searchedBall.append(balls.at(6));
                    qDebug()<<"searched6"<<searchedBall.at(6)->x<<searchedBall.at(6)->y<<balls.at(6)->x<<balls.at(6)->y;
                }
        }
        qDebug()<<"dis"<<dis5<<dis6;
    }
        break;
    default:
        break;
    }
    if(searchedBallsCount != searchedBall.length())
    {
        qDebug()<<searchedBall.length();
        planFlag = false;
        searchedBallsCount = searchedBall.length();  //每次搜到新球规划一次
    }
}

void USV::planPoint(){
    if(!planFlag)  //每次搜到新球或着航程切换规划一次
    {
        qDebug()<<"plan";
        if(planX != nullptr)
        {
            delete [] planX;planX = nullptr;
            delete [] planY;planX = nullptr;
        }
        switch (stage) {
        case 1:
            planCount = 1;
            planX = new double[1];
            planY = new double[1];
            if(searchedBall.length() == 0)
                wgs84toxy(end_lng,end_lat,planX[0],planY[0]);
            else if(searchedBall.length() == 1)
            {
                planX[0] = searchedBall.at(0)->x;
                planY[0] = searchedBall.at(0)->y;
            }
            else if(searchedBall.length() == 2)
            {
                planX[0] = (searchedBall.at(0)->x+searchedBall.at(1)->x)/2;
                planY[0] = (searchedBall.at(0)->y+searchedBall.at(1)->y)/2;
                midx = planX[0];
                midy = planY[0];
            }
            break;
        case 2:
            if(searchedBall.length() == 2)
            {
                planCount = 1;
                planX = new double[1];
                planY = new double[1];
                wgs84toxy(end_lng,end_lat,planX[0],planY[0]);
            }
            else if (searchedBall.length() == 3)
                rbbPlan(searchedBall.last()->color);
            break;
        case 3:
            if(searchedBall.length() == 3)
            {
                planCount = 1;
                planX = new double[1];
                planY = new double[1];
                wgs84toxy(end_lng,end_lat,planX[0],planY[0]);
            }
            else if (searchedBall.length() == 4)
                rbbPlan(searchedBall.last()->color);
            break;
        case 4:
            if(searchedBall.length() == 4)
            {
                planCount = 1;
                planX = new double[1];
                planY = new double[1];
                wgs84toxy(end_lng,end_lat,planX[0],planY[0]);
            }
            else if (searchedBall.length() == 5)
                rbbPlan(searchedBall.last()->color);
            break;
        case 5:
            planCount = 1;
            planX = new double[1];
            planY = new double[1];
            if(searchedBall.length() == 5)
                wgs84toxy(end_lng,end_lat,planX[0],planY[0]);
            else if(searchedBall.length() == 6)
            {
                planX[0] = searchedBall.at(5)->x;
                planY[0] = searchedBall.at(5)->y;
            }
            else if(searchedBall.length() == 7)
            {
                planX[0] = (searchedBall.at(5)->x+searchedBall.at(6)->x)/2;
                planY[0] = (searchedBall.at(5)->y+searchedBall.at(6)->y)/2;
            }
            break;
        case 6:
            planCount = 1;
            planX = new double[1];
            planY = new double[1];
            wgs84toxy(end_lng,end_lat,planX[0],planY[0]);
            break;
        default:
            break;
        }
        planFlag = true;
        qDebug()<<planX[0]<<planY[0];
    }
}

void USV::rbbPlan(BAllCOLOR col){
    double ang,dx,dy;
    switch (col) {
    case red:  //左侧通过
        planCount = 3;
        planX = new double[3];
        planY = new double[3];
        ang = atan2(searchedBall.last()->y-midy,searchedBall.last()->x-midx);
        if(ang < 0)
            ang = ang +2*M_PI;
        dx = 10*cos(ang);
        dy = 10*sin(ang);
        planX[0] = searchedBall.last()->x - dx;
        planY[0] = searchedBall.last()->y - dy;
        planX[2] = searchedBall.last()->x + dx;
        planY[2] = searchedBall.last()->y + dy;
        ang -= M_PI_2;
        if(ang < 0)
            ang = ang +2*M_PI;
        dx = 10*cos(ang);
        dy = 10*sin(ang);
        planX[1] = searchedBall.last()->x + dx;
        planY[1] = searchedBall.last()->y + dy;
        break;
    case black:
        planCount = 7;
        planX = new double[7];
        planY = new double[7];
        ang = atan2(searchedBall.last()->y-midy,searchedBall.last()->x-midx);
        if(ang < 0)
            ang = ang +2*M_PI;
        dx = 10*cos(ang);
        dy = 10*sin(ang);
        planX[0] = searchedBall.last()->x - dx;
        planY[0] = searchedBall.last()->y - dy;
        planX[4] = planX[0];
        planY[4] = planY[0];
        planX[2] = searchedBall.last()->x + dx;
        planY[2] = searchedBall.last()->y + dy;
        planX[6] = planX[2];
        planY[6] = planY[2];
        ang -= M_PI_2;
        if(ang < 0)
            ang = ang +2*M_PI;
        dx = 10*cos(ang);
        dy = 10*sin(ang);
        planX[1] = searchedBall.last()->x + dx;
        planY[1] = searchedBall.last()->y + dy;
        planX[5] = planX[1];
        planY[5] = planY[1];
        planX[3] = searchedBall.last()->x - dx;
        planY[3] = searchedBall.last()->y - dy;
        break;
    case blue:
        planCount = 3;
        planX = new double[3];
        planY = new double[3];
        ang = atan2(searchedBall.last()->y-midy,searchedBall.last()->x-midx);
        if(ang < 0)
            ang = ang +2*M_PI;
        dx = 10*cos(ang);
        dy = 10*sin(ang);
        planX[0] = searchedBall.last()->x - dx;
        planY[0] = searchedBall.last()->y - dy;
        planX[2] = searchedBall.last()->x + dx;
        planY[2] = searchedBall.last()->y + dy;
        ang -= M_PI_2;
        if(ang < 0)
            ang = ang +2*M_PI;
        dx = 10*cos(ang);
        dy = 10*sin(ang);
        planX[1] = searchedBall.last()->x - dx;
        planY[1] = searchedBall.last()->y - dy;
        break;
    default:
        break;
    }
}

void USV::simulate()
{
    updateXY();
    searchBall();
    planPoint();
    update_desired_point();
    update_distance_and_desired_course();
    controller();
}

void USV::init()
{
    desiredBallId = 0;
    stage = 1;
    planFlag = false;
    done = false;
    searchedBall.clear();
    balls.clear();
    balls.append(new BALL(113.6102846,22.3797306,green));
    balls.append(new BALL(113.6102846,22.3796306,green));
    balls.append(new BALL(113.6107846,22.3796806,red));
    balls.append(new BALL(113.6112846,22.3796806,black));
    balls.append(new BALL(113.6117846,22.3796806,blue));
    balls.append(new BALL(113.6122846,22.3797306,green));
    balls.append(new BALL(113.6122846,22.3796306,green));
    ballCount = 7;
    ballWgs84toxy();
    end_lng = 113.6127;
    end_lat = 22.3796;
    if(planX != nullptr)
    {
        qDebug() << planX << planY;
        //delete [] planX;
        planX = nullptr;
        //delete [] planY;
        planY = nullptr;
    }
}

void USV::getBalls(int ballId, double ballLng, double ballLat, int ballColor)
{
    if(ballId == 0)
    {
        if(balls.length() != 0)
        {
             balls.clear();
        }
    }
    switch (ballColor) {
    case 0: balls.append(new BALL(ballLng,ballLat,red));break;
    case 1: balls.append(new BALL(ballLng,ballLat,blue)); break;
    case 2: balls.append(new BALL(ballLng,ballLat,yellow));break;
    case 3: balls.append(new BALL(ballLng,ballLat,green));break;
    case 4: balls.append(new BALL(ballLng,ballLat,black));break;
    default: break;
    }
    qDebug()<<QString("%1,%2,%3,%4").arg(ballId).arg(ballLng,0,'f',7).arg(ballLat,0,'f',7).arg(ballColor);
}
