#include "Square.h"
#include "operat.h"
#include <glut.h>
#include <math.h>
#define PI acos(-1)
Square::Square()
{
    info=0;
}
void Square::print()
{
    if(info!=-1)
        draw_change();
}
void Square::add_change()
{
    x1+=change_x1;
    x2+=change_x1;
    y1+=change_y1;
    y2+=change_y1;
    change_x1=0;
    change_y1=0;
}
void Square::trans(int change_x,int change_y)
{
    this->change_x1=change_x;
    this->change_y1=change_y;
}
bool Square::is_in(int x,int y)
{
    int a1=max(x1,x2),a2=min(x1,x2);
    int b1=max(y1,y2),b2=min(y1,y2);
    if(x<=a1&&x>=a2&&y>=b2&&y<=b1)
        return true;
    return false;
}
void Square::print(int a,int x11,int y11,int x22,int y22)
{
    this->info=a;
    this->x1=x11;
    this->x2=x22;
    this->y1=y11;
    this->y2=y22;
    draw();
}
void Square::draw()
{
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1,y1);
    glVertex2f(x1,y2);
    glVertex2f(x2,y2);
    glVertex2f(x2,y1);
    glEnd();
}
int Square::load(int a)
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
void Square::draw_change()
{
    int x1=this->x1+change_x1,x2=this->x2+change_x1;
    int y1=this->y1+change_y1,y2=this->y2+change_y1;
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1,y1);
    glVertex2f(x1,y2);
    glVertex2f(x2,y2);
    glVertex2f(x2,y1);
    glEnd();
}
