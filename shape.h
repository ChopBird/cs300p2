
#ifndef _shape_h
#define _shape_h

#include <string> 
#include "gwindow.h"




class Shape {
public: 

void setLocation(double x, double y);

void move(double x, double y);

void setColor (std::string color);

virtual void draw(GWindow & gw) = 0;

virtual bool contains(double x, double y);

protected:

Shape();
std::string color;
double x, y; 


};

class Line : public Shape{

Line(double x1, double y1, double x2, double y2);

virtual void draw(Gwindow & gw);

private:

double dx, dy;
};

class Rect : public Shape{
public:

Rect(double x, double y, double width, double height);

virtual void draw(GWindow & gw);

private:
    double width, height;
};

class Square : public Rect{
    Square(double x, double y, double length);
}

class Oval : public Shape{
Oval(double x, double y, double width, double height);

virtual void draw(GWindow & gw);

private:
    double width, height;
};

class Circle : public Oval{
    Circle(double x, double y,double r);
}

#endif


