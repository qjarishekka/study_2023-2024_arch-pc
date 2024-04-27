#include<iostream>


/*
лаб. 3 наследование

точка   //Gr object
  |
линия 
  |
квадрат
 |     \
ромб   прямоугольник
 |       /
паралелограм
*/
/////////////////////
class point{

protected:
    int x;
    int y;
    int color;
    int visable;

public:
    point();
    point(int xx, int yy);
    point(int xx, int yy, int c);
    ~point();
    virtual void draw();
    virtual void hide();
    virtual void move(int dxx, int dyy);
};

/////////////////////////////////
class tline : public point{

protected: 
    int dx;
    int dy;    

public:
    tline();
    tline(int xx, int yy, int dxx, int dyy);
    tline(int xx, int yy, int dxx, int dyy, int c);
    ~tline();

    void draw();
    void hide();
    void move(int dxx, int dyy);
    void rotate(double fi);

};

tline :: tline(int xx, int yy, int dxx, int dyy) : point(xx , yy){

    dx = dxx;
    dy = dyy;

}


//////////////////////////////////////
class square : public tline{

public: 
    //escrbir 3 constructores + destructor;
    square();
    square(int xx, int yy, int dxx, int dyy, double bb);
    square(int xx, int yy, int dxx, int dyy, double bb, int c);


    void draw();
    void hide();
    void move();
    void rotate(double fi);

};

////////////////////////////////
class romb : public square{

//добавляется double alfa;
protected:
    double alfa;

public:
    romb();
    romb(int xx, int yy , int dxx, int dyy, double al);
    romb(int xx, int yy, int dxx, int dyy, double al, int c);


    void draw();
    void hide();
    void move();
    void rotate(double fi);






};


/////////////////////////////////
class rect : public square{

protected: 
    double b;
    //3 constructor + 1 destructor;

public:

    rect();
    rect(int xx, int yy, int dxx, int dyy, double bb);
    rect(int xx, int yy, int dxx, int dyy, double bb, int c);

    void draw();
    void hide();
    void move(int dxx, int dyy);
    void rotate(double fi);

};


//////////////////////////////////////////////////////////////////
class parallelepipedo : public romb, rect{

public:

        //3 constructor + 1 destructor

        parallelepipedo (int xx, int yy, int dxx ,int dyy, double al, double bb, int c);

        void draw();
        void hide();
        void move(int dxx, int dyy);
        void rotate(double fi);



};


parallelepipedo :: parallelepipedo (int xx, int yy, int dxx ,int dyy, double al, double bb, int c): romb(xx, yy, dxx, dyy, al, c),rect(xx,yy,dxx,dyy,bb,c){



}



