#include "Circle.h"
#include "operat.h"
#include <glut.h>
#include <math.h>
#define PI acos(-1)
Circle::Circle()
{
    info=1;
}
void Circle::print()
{
    if(info!=-1)
        draw_change();
}
void Circle::add_change()
{
    x1+=change_x1;
    x2+=change_x1;
    y1+=change_y1;
    y2+=change_y1;
    change_x1=0;
    change_y1=0;
}
void Circle::trans(int change_x,int change_y)
{
    this->change_x1=change_x;
    this->change_y1=change_y;
}
bool Circle::is_in(int x,int y)
{
    float circle_x=(x1+x2)/2;
    float circle_y=(y1+y2)/2;
    float R=sqrt((x2-x1)*(x2-x1)+(y1-y2)*(y1-y2))/2;
    float d=sqrt((x-circle_x)*(x-circle_x)+(y-circle_y)*(y-circle_y));
    if(d<=R)
        return true;
    return false;;;
}
void Circle::print(int a,int x11,int y11,int x22,int y22)
{
    this->info=a;
    this->x1=x11;
    this->x2=x22;
    this->y1=y11;
    this->y2=y22;
    draw();
}
void Circle::draw()
{
    float circle_x=(x1+x2)/2;
    float circle_y=(y1+y2)/2;
    float R=sqrt((x2-x1)*(x2-x1)+(y1-y2)*(y1-y2))/2;
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<72;++i)
    {
        glVertex2f(circle_x+R*cos(2*PI/72*i),circle_y+R*sin(2*PI/72*i));
    }
    glEnd();
}
int Circle::load(int a)
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
void Circle::draw_change()
{
    int x1=this->x1+change_x1,x2=this->x2+change_x1;
    int y1=this->y1+change_y1,y2=this->y2+change_y1;
    float circle_x=(x1+x2)/2;
    float circle_y=(y1+y2)/2;
    float R=sqrt((x2-x1)*(x2-x1)+(y1-y2)*(y1-y2))/2;
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<72;++i)
    {
        glVertex2f(circle_x+R*cos(2*PI/72*i),circle_y+R*sin(2*PI/72*i));
    }
    glEnd();
}
