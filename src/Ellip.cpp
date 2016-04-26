#include "Ellip.h"
#include "operat.h"
#include <glut.h>
#include <math.h>
#define PI acos(-1)
Ellip::Ellip()
{
    info=3;
}
Ellip::Ellip(int x1,int x2)
{

}
void Ellip::print()
{
    if(info!=-1)
        draw_change();
}
void Ellip::add_change()
{
    x1+=change_x1;
    x2+=change_x1;
    y1+=change_y1;
    y2+=change_y1;
    change_x1=0;
    change_y1=0;
}
void Ellip::trans(int change_x,int change_y)
{
    this->change_x1=change_x;
    this->change_y1=change_y;
}
bool Ellip::is_in(int x,int y)
{
    float center_x=(x1+x2)/2,center_y=(y1+y2)/2;
    float a=(x1-x2)/2,b=(y1-y2)/2;
    if((x-center_x)*(x-center_x)/a/a+(y-center_y)*(y-center_y)/b/b<=1)
        return true;
    return false;
}
void Ellip::print(int a,int x11,int y11,int x22,int y22)
{
    this->info=a;
    this->x1=x11;
    this->x2=x22;
    this->y1=y11;
    this->y2=y22;
    draw();
}
void Ellip::draw()
{
    float center_x=(x1+x2)/2,center_y=(y1+y2)/2;
    float a=(x1-x2)/2,b=(y1-y2)/2;
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<72;++i)
    {
        glVertex2f(center_x+a*cos(2*PI/72*i),center_y+b*sin(2*PI/72*i));
    }
    glEnd();
}
int Ellip::load(int a)
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
void Ellip::draw_change()
{
    int x1=this->x1+change_x1,x2=this->x2+change_x1;
    int y1=this->y1+change_y1,y2=this->y2+change_y1;
    float center_x=(x1+x2)/2,center_y=(y1+y2)/2;
    float a=(x1-x2)/2,b=(y1-y2)/2;
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<72;++i)
    {
        glVertex2f(center_x+a*cos(2*PI/72*i),center_y+b*sin(2*PI/72*i));
    }
    glEnd();
}



