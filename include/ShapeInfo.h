#ifndef SHAPEINFO_H
#define SHAPEINFO_H
class ShapeInfo
{
    public:
        ShapeInfo();
        virtual ~ShapeInfo();
        virtual void print(int a,int x1,int y1,int x2,int y2){};
        virtual void print(){};
        virtual void draw(){};
        virtual void draw_change(){};
        virtual int load(int a){return 0;};
        virtual bool is_in(int x,int y){return false;};
        virtual void trans(int change_x,int change_y){};
        virtual void add_change(){};
    protected:
    private:
};

#endif // SHAPEINFO_H
