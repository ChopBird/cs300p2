#include <string>
#include "shape.h"
#include <math.h>
#include "gwindow.h"
using namespace std;

Shape::Shape() {
    setColor("BLACK");
}
void Shape::setLocation(double x, double y) {
    this ->x = x;
    this->y = y;
}

void Shape::move(double dx, double dy){
    x += dx;
    y += dy;
}

void Shape::setColor(string color){
    this->color = color;
}

void virtual Shape::contains(double x, double y);

//Line 

Line::Line(double x1,double y1,, double x2, double y2){
    this->x = x1;
    this->y = y1;
    this->dx = x2-x1;
    this->dy = y2-y1;

}

void Line::draw(GWindow & gw){
gw.setColor(color);
gw.drawLine(x,y,x+dx,y+dy);
}

bool Line::contains(double x, double y){
    double x1 = this->x;
    double y1 = this->y;
    double x2 = this->x + dx;
    double y2 = this->y + dy;
    //return true if point is within .5px of endpoints
    double dist1 = sqrt((pow(x-x1,2))+(pow(y-y1,2)));
    double dist2 = sqrt((pow(x-x2,2))+(pow(y-y2,2)));

    if (dist1<=.5||dist2 <=5) return true
    
    //return true if point is within .5 of the line
    double disttotal = dist1+dist2 
    if (disttotal <= sqrt(pow(dx,2)+pow(dy,2)) + .5)return true

    return false;
    //is the geometry wrong on this idk

}

//Rect
Rect::Rect(double x, double y, double width, double height){
this->x = x;
this->y = y;
this->width = width;
this->height = height;
}

void Rect::draw(GWindow & gw){
    gw.setColor(color);
    gw.fillRect(x,y,width,height);
}
bool Rect::contains(double x,double y){
double x1 = this-> x;
double y1 = this->y;
double y2 = this->y + height;
double x2 = this->x + width;

if (x<x2 && x>x1 && y >y1 && y < y2) return true;
return false;
}


Square::Square(double x, double y, double length)
    :Rect(x,y,length,length);

Oval::Oval(double x,double y, double width, double height){
    this->x = x;
    this->y= y;
    this->width = width;
    this->height = height;
}

void Oval::draw(GWindow & gw){
    gw.setColor(color);
    gw.fillOval(x,y,width,height);

}

bool Oval::contains(double x,double y){
return (pow(x-this->x,2)/pow(width,2)) + pow(y-this->y,2)/pow(height,2) <=1;

}

void Circle::Circle(double x, double y ,double r)
            :Oval(x-r,y-r,2*r,2*r){

        }


    