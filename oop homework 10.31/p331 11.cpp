//
// Created by DELL on 2020/10/18.
//
#include <bits/stdc++.h>

using namespace std;
struct Point{
    int x;
    int y;
};
class ClosedShape {
public:
    void moveOff (int xoff,int yoff);
    double getArea ();
    double getPerimeter();
    void show();
};
class Circle : public ClosedShape{
public:
    Point p;//圆心
    int r;
private:
    Circle(int x,int y,int r);
};
class Rectangle : public ClosedShape{
public:
    Point topLeft;
    int wide;
    int high;
private:
    Rectangle(int x,int y,int wide ,int high);
};
class Triangle : public ClosedShape{
public:
    Point vertexes[3];
private:
    Triangle(int x0,int y0,int x1,int y1,int x2,int y2);
};
int main() {
    return 0;
}
