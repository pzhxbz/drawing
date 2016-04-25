#ifndef ELLIPSE_H
#define ELLIPSE_H
#include"ShapeInfo.h"
class Ellipse:public ShapeInfo
{
    public:
        Ellipse(int x1,int x2);
        Ellipse();
        void print(int a,int x1,int y1,int x2,int y2);
        void print();
        void draw();
        void draw_change();
        int load(int a);
        bool is_in(int x,int y);
        void trans(int change_x,int change_y);
        void add_change();
    protected:
    private:
        int x1,y1;
        int x2,y2;
        int info;
        int change_x1=0,change_y1=0;
};
#endif
