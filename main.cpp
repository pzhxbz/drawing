#include <windows.h>
#include <glut.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ShapeInfo.h"
#include "Line.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
#include "Ellip.h"
#define SQUARE 0
#define CIRCLE 1
#define TRIANGLE 2
#define ELLIPSE 3
#define LINE 4
#define FREEDOM 5
#define PI acos(-1)
#define GRAPH 9
#define ERASER 6
#define SAVE 7
#define OPEN 8
#define MOVE 250
//GLubyte *PixelData_move,*PxielData_change;
int x0,y0;
int x1,y1;
int x2,y2;
int x3,y3;
int width;
int height=500;
int first=500;
int winWidth=800,winHeight=600;     //窗口的宽度和高度
bool button_judge;
int shape=0;
int move_flag=0;
ShapeInfo *data[1000];
ShapeInfo *move_save;
int num=0;//图形数量
static float cur_size=5.0;
bool drag_judge;
void display();
void build(int i);
void drag()
{
    int change_x=x2-x0,change_y=y2-y0;
    if(move_flag==0)
    {
        if(num==0)
        {
            return;
        }
        for(int i=num-1;i>=0;i--)
        {
            drag_judge=data[i]->is_in(x0,y0);
            if(drag_judge)
            {
                move_save=data[i];
                move_flag=1;
                break;
            }
            if(i==0)
                return;
        }
    }
    move_save->trans(change_x,change_y);
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i=0;i<num;i++)
    {
        if(data[i]==move_save)
        {
            move_save->draw_change();
        }
        else
        {
            data[i]->print();
        }
    }
    glFlush();
}
void open()
{
    for(int i=0;i<num;i++)
    {
        delete(data[i]);
    }
    glClear(GL_COLOR_BUFFER_BIT);
    FILE *open;
    open=fopen("save.txt","r");
    fscanf(open,"%d",&num);
    for(int i=0;i<num;i++)
    {
        int info,x11,y11,x22,y22;
        fscanf(open,"%d %d %d %d %d",&shape,&x11,&y11,&x22,&y22);
        build(i);
        data[i]->print(info,x11,y11,x22,y22);
        glFlush();
    }
    fclose(open);
}
void save()
{
    FILE *save;
    save=fopen("save.txt","w+");
    fprintf(save,"%d\n",num);
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<=4;j++)
        {
            fprintf(save,"%d ",data[i]->load(j));
        }
        fprintf(save,"\n");
    }
    fclose(save);
    exit(0);
}
void drawing()
{
    data[num]->print(shape,x0,y0,x2,y2);
    if(shape==MOVE)
    {
        drag();
    }
    glEnd();
    glFlush();
    glPointSize(1.0);
}
void build()
{
    switch(shape)
    {
        case SQUARE:
            data[num]=new Square();
            break;
        case CIRCLE:
            data[num]=new Circle();
            break;
        case TRIANGLE:
            data[num]=new Triangle();
            break;
        case ELLIPSE:
            data[num]=new Ellip();
            break;
        case LINE:
            data[num]=new Line();
            break;
    }
}
void build(int i)
{
    switch(shape)
    {
        case SQUARE:
            data[i]=new Square();
            break;
        case CIRCLE:
            data[i]=new Circle();
            break;
        case TRIANGLE:
            data[i]=new Triangle();
            break;
        case ELLIPSE:
            data[i]=new Ellip();
            break;
        case LINE:
            data[i]=new Line();
            break;
    }
}
void mouse(int button,int state, int x,int y)
{
    glEnable(GL_LOGIC_OP);
    if(button==GLUT_RIGHT_BUTTON&& state == GLUT_DOWN)
    {
        button_judge=false;
    }
    else
    {
        button_judge=true;
    }
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        build();
        x1=x2=x3=x0=x;
        y1=y2=y3=y0=height-y;
        glColor3f(0.0,1.0,0.0);
        if(shape==ERASER)
        {
            glColor3b(1.0,1.0,1.0);
        }
        if(shape!=FREEDOM&&shape!=ERASER)
        {
            glLogicOp(GL_XOR);
        }
        first=0;
    }
    if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        drawing();
        x2 = x;
        y2 = height-y;
        x1 = x0;
        y1 = y2;
        x3 = x;
        y3 = y0;
        glFlush();
        glColor3f(0.0,0.0,1.0);
        glLogicOp(GL_COPY);
        drawing();
        if(shape==MOVE)
        {
            move_flag=0;
            move_save->add_change();
        }
        num++;
    }
}
void move(int x,int y)
{
    if(!button_judge)
    {
        return;
    }
    if(first == 1)
    {
       drawing();
    }
    x2 = x;
    y2 = height-y;
    x1 = x0;
    y1 = y2;
    x3 = x;
    y3 = y0;
    drawing();
    first = 1;
}
void display()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glEnable(GL_COLOR_LOGIC_OP);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glFlush();
}
void myReshape(int w,int h)
{
    glClearColor(1.0,1.0,1.0,1.0);
    glViewport(0,0,w,h);
    width=w;
    height=h;
    glMatrixMode(GL_PROJECTION);//投影矩阵
    glLoadIdentity();
    gluOrtho2D(0.0,(GLfloat)w,0.0,(GLfloat)h);
    glMatrixMode(GL_MODELVIEW);//矩阵堆栈
}
void processMenuEvents(int option)
{
    if(option==SAVE)
    {
        save();
        shape=0;
        return;
    }
    if(option==OPEN)
    {
        open();
        shape=0;
        return;
    }
    shape=option;
}
void processSubMenuEvents(int option)
{
    shape=option;
}
void size_choose(int potion)
{
    cur_size=potion;
}
void creat_menu()
{
    int menu,submenu,SizeMenu;
    submenu=glutCreateMenu(processSubMenuEvents);
    glutAddMenuEntry("矩形",SQUARE);
    glutAddMenuEntry("圆",CIRCLE);
    glutAddMenuEntry("三角形",TRIANGLE);
    glutAddMenuEntry("椭圆",ELLIPSE);
    glutAddMenuEntry("直线",LINE);
    SizeMenu=glutCreateMenu(size_choose);
    for(int i=1;i<=20;i++)
    {
        char j=char(i+64);
        char *p=&j;
        glutAddMenuEntry(p,i);
    }
    menu=glutCreateMenu(processMenuEvents);
    glutAddSubMenu("图形",submenu);
    glutAddSubMenu("自由绘画and橡皮擦大小",SizeMenu);
    glutAddMenuEntry("自由绘画(暂不支持)",FREEDOM);
    glutAddMenuEntry("橡皮擦（暂不支持）",ERASER);
    glutAddMenuEntry("拖动",MOVE);
    glutAddMenuEntry("保存",SAVE);
    glutAddMenuEntry("打开",OPEN);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);//初始化
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);//显示方式
    glutInitWindowSize(800,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("画矩形");
    glutReshapeFunc(myReshape);//窗口改变的时候调用的函数，在这个里面可以根据缩放后的窗口重新设置
    creat_menu();
    glutDisplayFunc(display);//画图
    glutMotionFunc(move);
    glutMouseFunc(mouse);
    glutMainLoop();//窗口结束关闭
    return 0;
}
