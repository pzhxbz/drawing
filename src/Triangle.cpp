#include "Triangle.h"
#include "operat.h"
#include <glut.h>
#include <math.h>
#define PI acos(-1)
Triangle::Triangle()
{
    info=2;
}
void Triangle::print()
{
    if(info!=-1)
        draw_change();
}
void Triangle::add_change()
{
    x1+=change_x1;
    x2+=change_x1;
    y1+=change_y1;
    y2+=change_y1;
    change_x1=0;
    change_y1=0;
}
void Triangle::trans(int change_x,int change_y)
{
    this->change_x1=change_x;
    this->change_y1=change_y;
}
bool Triangle::is_in(int x,int y)
{
    float peak_x=(x1+x2)/2;
    float peak_y=y1;
    float down_y=y2;
    float down_x1=x1,down_x2=x2;
    float k1=(peak_y-down_y)/(peak_x-down_x1);
    float k2=(peak_y-down_y)/(peak_x-down_x2);
    if(x-down_x1<=1e-6&&x-down_x1>=-1e-6)
        return false;
    if(x-down_x2<=1e-6&&x-down_x2>=-1e-6)
        return false;
    float kx1=(y-down_y)/(x-down_x1);
    float kx2=(y-down_y)/(x-down_x2);
    if(abs(kx1)<=abs(k1)&&abs(kx2)<=abs(k2)&&fuhao(kx1,k1)&&fuhao(kx2,k2))
        return true;
    return false;
}
void Triangle::print(int a,int x11,int y11,int x22,int y22)
{
    this->info=a;
    this->x1=x11;
    this->x2=x22;
    this->y1=y11;
    this->y2=y22;
    draw();
}
void Triangle::draw()
{
    float peak_x=(x1+x2)/2;
    float peak_y=y1;
    glBegin(GL_LINE_LOOP);
    glVertex2f(peak_x,peak_y);
    glVertex2f(x2,y2);
    glVertex2f(x1,y2);
    glEnd();
}
int Triangle::load(int a)
{
    switch (a)
    {
        case 0:return this->info;
        case 1:return this->x1;
        case 2:return this->y1;
        case 3:return this->x2;
        case 4:return this->y2;
    }
}
void Triangle::draw_change()
{
    int x1=this->x1+change_x1,x2=this->x2+change_x1;
    int y1=this->y1+change_y1,y2=this->y2+change_y1;
    float peak_x=(x1+x2)/2;
    float peak_y=y1;
    glBegin(GL_LINE_LOOP);
    glVertex2f(peak_x,peak_y);
    glVertex2f(x2,y2);
    glVertex2f(x1,y2);
    glEnd();
}
