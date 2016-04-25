#include "Line.h"
#include "operat.h"
#include <glut.h>
#include <math.h>
#define PI acos(-1)
Line::Line()
{
    info=4;
}
void Line::print()
{
    if(info!=-1)
        draw_change();
}
void Line::add_change()
{
    x1+=change_x1;
    x2+=change_x1;
    y1+=change_y1;
    y2+=change_y1;
    change_x1=0;
    change_y1=0;
}
void Line::trans(int change_x,int change_y)
{
    this->change_x1=change_x;
    this->change_y1=change_y;
}
bool Line::is_in(int x,int y)
{
    int a1=max(x1,x2),a2=min(x1,x2);
    int b1=max(y1,y2),b2=min(y1,y2);
    if(x1-x2<=1e-6&&x1-x2>=-1e-6)
    {
        if(y<=b1&&y>=b2)
            return true;
    }
    else
    {
        float k=(y2-y1)/(x2-x1);
        float b=-k*x1+y1;
        float d=abs(x*k+b)/sqrt(1+k*k);
        if(d<=2&&d>=-2)
            return true;
    }
    return false;
}
void Line::print(int a,int x11,int y11,int x22,int y22)
{
    this->info=a;
    this->x1=x11;
    this->x2=x22;
    this->y1=y11;
    this->y2=y22;
    draw();
}
void Line::draw()
{
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}
int Line::load(int a)
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
void Line::draw_change()
{
    int x1=this->x1+change_x1,x2=this->x2+change_x1;
    int y1=this->y1+change_y1,y2=this->y2+change_y1;
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}
