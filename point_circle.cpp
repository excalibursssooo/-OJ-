#include <bits/stdc++.h>
using namespace std;

class Point {
private:
    double x, y;

public:
    Point() {
        x = 0;
        y = 0;
    }
    Point(double x,double y){
        this->x = x;
        this->y = y;
    }
    double getX(){
        return x;
    }
    double getY(){
        return y;
    }
    void setX(double x){
        this->x = x;
    }
    void setY(double y){
        this->y = y;
    }
    double getDisTo(Point &p){
        double x_dis = (p.x-x)*(p.x-x);
        double y_dis = (p.y-y)*(p.y-y);
        return sqrt(x_dis+y_dis);
    }
    ~Point(){

    }
};


class Circle{
private:
    Point centre;
    double r;
public:
    Circle(){
        centre = Point();
        r = 1;
    }
    Circle(double x,double y,double r){
        centre = Point(x,y);
        this->r = r;
    }
    double getArea(){
        return 3.14*r*r;
    }
    void moveCentreTo(double x1,double y1){
        centre = Point(x1,y1);
    }
    int contain(Point &p){
        if(p.getDisTo(centre)<=r) return 1;
        else return 0;
    }
};

int main(){
    Circle c;
    double c_x,c_y,c_r;
    cin>>c_x>>c_y>>c_r;
    c = Circle(c_x,c_y,c_r);
    int n;
    cin>>n;
    Point *p = new Point[n];
    for(int i = 0;i<n;i++){
        double x,y;
        cin>>x>>y;
        p[i].setX(x);
        p[i].setY(y);
    }
    for(int i = 0;i<n;i++){
        if(c.contain(p[i]) == 0) cout<<"outside"<<endl;
        else cout<<"inside"<<endl;
    }
    cout<<"after move the centre of circle:"<<endl;
    cin>>c_x>>c_y;
    c.moveCentreTo(c_x,c_y);
    for(int i = 0;i<n;i++){
        if(c.contain(p[i]) == 0) cout<<"outside"<<endl;
        else cout<<"inside"<<endl;
    }
}