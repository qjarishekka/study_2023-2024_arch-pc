#include<graphics.h>
#include<iostream>

class point{

protected:
        int x; int y; int color;
public:
       
        point();
        point(int xx,int yy);
        ~point();
        void draw();
        void line();
        void move(int xx; int yy);
        void rotate(double fi);
}

class tline{

        tline();
        tline(int xx, int yy, int dxx, int dyy);
        ~tline();
        void draw();
        void line();
        void move(int xx; int yy);
        void rotate(double fi);
}

tline::tline(int xx, int yy, int dxx, int dyy):point(xx,yy){

dx = dxx; dy = dyy;


}

int main{

cout<<"hola"<<endl;

}