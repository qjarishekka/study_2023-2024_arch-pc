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

sf::RenderWindow window(sf::VideoMode(1000, 800), "punto");



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
    sf::Vertex punto1;
    
    

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
    visable = 1;

    punto1.position = sf::Vector2f(x,y);
    punto1.color = sf::Color(color*visable,255*visable,255*visable);


}

point :: point(int xx, int yy){

    x = xx;
    y = yy;
    color = 255;
    visable = 1;

    punto1.position = sf::Vector2f(x,y);
    punto1.color = sf::Color(color*visable,255*visable,255*visable);



}

point :: point(int xx, int yy, int c){

    x = xx;
    y = yy;
    color = c;
    visable = 1;

    punto1.position = sf::Vector2f(x,y);
    punto1.color = sf::Color(color*visable,255*visable,255*visable);

}


void point::draw(){ 

    sf::VertexArray ppunto(sf::Lines,2);

    ppunto[0] = punto1;
    ppunto[1] = sf::Vector2f(x+1,y+1);

    window.draw(ppunto);


    return;
}

void point::hide(){
    window.display();
    return;
}

void point::move(int dxx, int dyy){

    punto1.position = sf::Vector2f(x+dxx,y+dyy);

    return;
}





/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

class tline : public point{

protected: 
    int dx;
    int dy;    
    sf::Vertex punto2;
    sf::Transform transform;


public:
    tline();
    tline(int xx, int yy, int dxx, int dyy);
    tline(int xx, int yy, int dxx, int dyy, int c);
    ~tline();

    void draw();
    void hide();
    void move(int mxx, int myy);
    void rotate(double fi);

};

tline :: tline() : point(){

    dx = 200;
    dy = 100;

    punto1.position = sf::Vector2f(x,y);
    punto1.color = sf::Color(color*visable,255*visable,255*visable);
    punto2.position = sf::Vector2f(dx,dy);
    punto2.color = sf::Color(color*visable,255*visable,255*visable);


}

tline :: tline(int xx, int yy, int dxx, int dyy) : point(xx , yy){

    dx = dxx;
    dy = dyy;
    
    punto1.position = sf::Vector2f(x,y);
    punto1.color = sf::Color(color*visable,255*visable,255*visable);
    punto2.position = sf::Vector2f(dx,dy);
    punto2.color = sf::Color(color*visable,255*visable,255*visable);
    

}

tline :: tline(int xx, int yy, int dxx, int dyy, int c) : point(xx, yy, c){

    dx = dxx;
    dy = dyy;

    punto1.position = sf::Vector2f(x,y);
    punto1.color = sf::Color(color*visable,255*visable,255*visable);
    punto2.position = sf::Vector2f(dx,dy);
    punto2.color = sf::Color(color*visable,255*visable,255*visable);

}

tline:: ~tline(){}

void tline::draw(){


    sf::VertexArray ppunto(sf::Lines,2);

    ppunto[0] = punto1;
    ppunto[1] = punto2;

    window.draw(ppunto,transform);


return;
}

void tline::hide(){

    window.display();
return;
}


void tline::move(int mxx, int myy){

    punto1.position = sf::Vector2f(x+mxx,y+myy);
    punto2.position = sf::Vector2f(dx+mxx,dy+myy);
    
    
return;
}

void tline::rotate(double fi){

    transform.rotate(fi, sf::Vector2f(x,y));

    sf::VertexArray ppunto(sf::Lines,2);
    ppunto[0] = punto1;
    ppunto[1] = punto2;

}


////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
class square : public tline{

protected:

    sf::VertexArray ppunto1;
    sf::VertexArray ppunto2;
    sf::VertexArray ppunto3;
    sf::VertexArray ppunto4;

    sf::Transform transform2;
    sf::Transform transform3;
    sf::Transform transform4;

public: 
    //escrbir 3 constructores + destructor;

    square();
    square(int xx, int yy, int dxx, int dyy);
    square(int xx, int yy, int dxx, int dyy, int c);
    ~square(){};


    void draw();
    void hide();
    void move(int mxx, int myy);
    void rotate(double fi);

};

square::square() : tline(){

ppunto1.setPrimitiveType(sf::Lines);
ppunto1.resize(2);

ppunto2.setPrimitiveType(sf::Lines);
ppunto2.resize(2);

ppunto3.setPrimitiveType(sf::Lines);
ppunto3.resize(2);

ppunto4.setPrimitiveType(sf::Lines);
ppunto4.resize(2);

transform.rotate(90, sf::Vector2f(x,y));
transform2.rotate(-90, sf::Vector2f(dx,dy));


transform3.rotate(-90, sf::Vector2f(x,y));
transform4.rotate(-90,sf::Vector2f(dx,dy));

transform4.combine(transform3);


}

square::square(int xx, int yy, int dxx, int dyy) : tline(xx,yy,dxx,dyy){

ppunto1.setPrimitiveType(sf::Lines);
ppunto1.resize(2);

ppunto2.setPrimitiveType(sf::Lines);
ppunto2.resize(2);

ppunto3.setPrimitiveType(sf::Lines);
ppunto3.resize(2);

ppunto4.setPrimitiveType(sf::Lines);
ppunto4.resize(2);

transform.rotate(90, sf::Vector2f(x,y));
transform2.rotate(-90, sf::Vector2f(dx,dy));

transform3.rotate(-90, sf::Vector2f(x,y));
transform4.rotate(-90,sf::Vector2f(dx,dy));

transform4.combine(transform3);

}

square::square(int xx, int yy, int dxx, int dyy,int c) : tline(xx,yy,dxx,dyy,c){

ppunto1.setPrimitiveType(sf::Lines);
ppunto1.resize(2);

ppunto2.setPrimitiveType(sf::Lines);
ppunto2.resize(2);

ppunto3.setPrimitiveType(sf::Lines);
ppunto3.resize(2);

ppunto4.setPrimitiveType(sf::Lines);
ppunto4.resize(2);

transform.rotate(90, sf::Vector2f(x,y));
transform2.rotate(-90, sf::Vector2f(dx,dy));

transform3.rotate(-90, sf::Vector2f(x,y));
transform4.rotate(-90,sf::Vector2f(dx,dy));

transform4.combine(transform3);





}

void square::draw(){


    ppunto1[0] = punto1;
    ppunto1[1] = punto2;

    ppunto2[0] = punto1;
    ppunto2[1] = punto2;

    ppunto3[0] = punto1;
    ppunto3[1] = punto2;

    ppunto4[0] = punto1;
    ppunto4[1] = punto2;

    
window.draw(ppunto1);

    
window.draw(ppunto2,transform);

   
window.draw(ppunto3,transform2);

    
window.draw(ppunto4,transform4);

    

}

void square::hide(){

}

void square::move(int mxx,int myy){

    transform.rotate(-90, sf::Vector2f(x,y));
    transform2.rotate(90, sf::Vector2f(dx,dy));
    
    transform4.rotate(90, sf::Vector2f(dx,dy));
    transform3.rotate(-90, sf::Vector2f(dx,dy));
    transform4.combine(transform3);


    x+=mxx;
    y+=myy;
    dx+=mxx;
    dy+=myy; 
    

    punto1.position = sf::Vector2f(x,y);
    punto2.position = sf::Vector2f(dx,dy);

    


    transform.rotate(90, sf::Vector2f(x,y));
    transform2.rotate(-90, sf::Vector2f(dx,dy));
    transform3.rotate(-90, sf::Vector2f(x,y));
    transform4.rotate(-90,sf::Vector2f(dx,dy));

    transform4.combine(transform3);





}

void square::rotate(double fi){

}



/*
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


parallelepipedo :: parallelepipedo (int xx, int yy, int dxx ,int dyy, double al, double bb, int c): 
romb(xx, yy, dxx, dyy, al, c),rect(xx,yy,dxx,dyy,bb,c){



}

*/

int main(){

    int counter = 0;


    point punto1;
    point punto2(100,200);
    point punto3(100,300,100);

    tline linea1;
    tline linea2(100, 200, 400 , 200);
    tline linea3(100, 300, 400, 300,0);

    square cuadrado1;
    square cuadrado2(300, 200, 800, 100);
    square cuadrado3(300, 400, 400, 100, 50);







while(window.isOpen()){

    sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();    
        }

    


    window.clear();

    

    


    if(counter == 0){

        linea1.rotate(90);
        linea2.rotate(-45);
        linea3.rotate(45);
        cuadrado1.move(10,0);




        counter++;
    }

    //punto1.draw();
    //punto2.draw();
    //punto3.draw();

    //linea1.draw();
    //linea2.draw();
    //linea3.draw();
    
    cuadrado1.draw();
    cuadrado2.draw();
    cuadrado3.draw();


    window.display();





}

    return 0;
}