#include<iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
 

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
////////////////////////////////////////////////////////////////////////////////////////////////

sf::RenderWindow window(sf::VideoMode(800, 1000), "punto");



////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

class point{

protected:
    int x;
    int y;
    int color;
    int visable;
    sf::CircleShape circulo;
    

public:
    point();
    point(int xx, int yy);
    point(int xx, int yy, int c);
    ~point(){};
    virtual void draw();
    virtual void hide();
    virtual void move(int dxx, int dyy);
};

point :: point(){
    
    x = 100;
    y = 100;
    color = 255;
    visable = 100;
    circulo.setRadius(10);
    circulo.setPosition(x,y);
    circulo.setFillColor(sf::Color(color*visable,255*visable,255*visable));

}

point :: point(int xx, int yy){

    x = xx;
    y = yy;
    color = 255;
    visable = 100;

    circulo.setRadius(10);
    circulo.setPosition(x,y);
    circulo.setFillColor(sf::Color(color*visable,255*visable,255*visable));


}

point :: point(int xx, int yy, int c){

    x = xx;
    y = yy;
    color = c;
    visable = 1;

    circulo.setRadius(10);
    circulo.setPosition(x,y);
    circulo.setFillColor(sf::Color(color*visable,255*visable,255*visable));

}


void point::draw(){

    window.draw(circulo);

}

void point::hide(){
    window.display();
}

void point::move(int dxx, int dyy){

    circulo.move(dxx,dyy);

}





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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



/*
//////////////////////////////////////
class square : public tline{

public: 
    //escrbir 3 constructores + destructor;
    square();
    square(int xx, int yy, int dxx, int dyy, double bb);
    square(int xx, int yy, int dxx, int dyy, double bb, int c);
    ~square();


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
    ~romb();


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
    ~rect();

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
        ~parallelepipedo();

        void draw();
        void hide();
        void move(int dxx, int dyy);
        void rotate(double fi);



};


parallelepipedo :: parallelepipedo (int xx, int yy, int dxx ,int dyy, double al, double bb, int c): romb(xx, yy, dxx, dyy, al, c),rect(xx,yy,dxx,dyy,bb,c){



}

*/

main(){

while(window.isOpen()){

    sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

    point punto1;

    point punto2(100,200);

    point punto3(100,300,100);


    window.clear();

    punto1.draw();
    punto2.draw();
    punto3.draw();
    window.display();





}

    return 0;
}