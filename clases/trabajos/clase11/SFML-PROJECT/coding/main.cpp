#include<iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include<math.h>

#define PI 3.14159265358979323846

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

double AnguloDeInclinacion(double x, double y,double dx, double dy){

double pendiente = (dy-y) / (dx-x);

double grados = (atan(pendiente)*180)/PI ;


return grados;
}


////////////////////////////////////////////////////////////////////////////////////////////////

sf::RenderWindow window(sf::VideoMode(1900, 1000), "punto");



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

}


void point::hide(){
    
    punto1.color = sf::Color::Transparent;

}

void point::move(int dxx, int dyy){

    punto1.position = sf::Vector2f(x+dxx,y+dyy);

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

}


void tline::hide(){

    punto1.color = sf::Color::Transparent;
    punto2.color = sf::Color::Transparent;

}


void tline::move(int mxx, int myy){

    punto1.position = sf::Vector2f(x+mxx,y+myy);
    punto2.position = sf::Vector2f(dx+mxx,dy+myy);

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
    sf::Transform transform5;

public: 

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

    
window.draw(ppunto1,transform5);
window.draw(ppunto2,transform);
window.draw(ppunto3,transform2);
window.draw(ppunto4,transform4);

    

}

void square::hide(){

    punto1.color = sf::Color::Transparent;
    punto2.color = sf::Color::Transparent;

}

void square::move(int mxx,int myy){

    transform.rotate(-90, sf::Vector2f(x,y));
    transform2 = transform;
    transform3 = transform;
    transform4 = transform;

    x+=mxx;
    y+=myy;
    dx+=mxx;
    dy+=myy; 
    

    punto1.position = sf::Vector2f(x,y);
    punto2.position = sf::Vector2f(dx,dy);

    
    
    transform.rotate(90, sf::Vector2f(x,y));
    transform2.rotate(-90, sf::Vector2f(dx,dy));
    transform4.rotate(-90, sf::Vector2f(x,y));
    transform3.rotate(90, sf::Vector2f(dx,dy));
    transform4.combine(transform3);


}



void square::rotate(double fi){

transform5.rotate(fi,sf::Vector2f(x,y));
transform = transform5;
transform2 = transform5;
transform3 = transform5;
transform4 = transform5;




transform.rotate(90, sf::Vector2f(x,y));
transform2.rotate(-90, sf::Vector2f(dx,dy));
transform3.rotate(-90, sf::Vector2f(dx,dy));
transform4 = transform3;
transform4.rotate(-90,sf::Vector2f(x,y));


}




////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////




class romb : public square{

//добавляется double alfa;
protected:

    double alfa;

public:
    romb();
    romb(int xx, int yy , int dxx, int dyy, double al);
    romb(int xx, int yy, int dxx, int dyy, double al, int c);
    ~romb(){};


    void draw();
    void hide();
    void move(int mxx, int myy);
    void rotate(double fi);



};

romb::romb() : square(){

alfa = 70;

ppunto1.setPrimitiveType(sf::Lines);
ppunto1.resize(2);

ppunto2.setPrimitiveType(sf::Lines);
ppunto2.resize(2);

ppunto3.setPrimitiveType(sf::Lines);
ppunto3.resize(2);

ppunto4.setPrimitiveType(sf::Lines);
ppunto4.resize(2);

transform = transform5;
transform2 = transform5;
transform3 = transform5;
transform4 = transform5;


transform.rotate(alfa, sf::Vector2f(x,y));
transform2.rotate(-180+alfa, sf::Vector2f(dx,dy));
transform3.rotate(-alfa, sf::Vector2f(x,y));
transform4.rotate(-180 + alfa,sf::Vector2f(dx,dy));
transform4.combine(transform3);


}


romb::romb(int xx, int yy , int dxx, int dyy, double al) : square(xx, yy , dxx, dyy){

alfa = al;

ppunto1.setPrimitiveType(sf::Lines);
ppunto1.resize(2);

ppunto2.setPrimitiveType(sf::Lines);
ppunto2.resize(2);

ppunto3.setPrimitiveType(sf::Lines);
ppunto3.resize(2);

ppunto4.setPrimitiveType(sf::Lines);
ppunto4.resize(2);

transform = transform5;
transform2 = transform5;
transform3 = transform5;
transform4 = transform5;


transform.rotate(alfa, sf::Vector2f(x,y));
transform2.rotate(-180+alfa, sf::Vector2f(dx,dy));
transform3.rotate(-alfa, sf::Vector2f(x,y));
transform4.rotate(-180 + alfa,sf::Vector2f(dx,dy));
transform4.combine(transform3);

}

romb::romb(int xx, int yy , int dxx, int dyy, double al, int c) : square(xx, yy , dxx, dyy, c){

alfa = al;

ppunto1.setPrimitiveType(sf::Lines);
ppunto1.resize(2);

ppunto2.setPrimitiveType(sf::Lines);
ppunto2.resize(2);

ppunto3.setPrimitiveType(sf::Lines);
ppunto3.resize(2);

ppunto4.setPrimitiveType(sf::Lines);
ppunto4.resize(2);


transform = transform5;
transform2 = transform5;
transform3 = transform5;
transform4 = transform5;


transform.rotate(alfa, sf::Vector2f(x,y));
transform2.rotate(-180+alfa, sf::Vector2f(dx,dy));
transform3.rotate(-alfa, sf::Vector2f(x,y));
transform4.rotate(-180 + alfa,sf::Vector2f(dx,dy));
transform4.combine(transform3);

}

void romb::draw(){


    ppunto1[0] = punto1;
    ppunto1[1] = punto2;

    ppunto2[0] = punto1;
    ppunto2[1] = punto2;

    ppunto3[0] = punto1;
    ppunto3[1] = punto2;

    ppunto4[0] = punto1;
    ppunto4[1] = punto2;



window.draw(ppunto1,transform5);

window.draw(ppunto2,transform);

window.draw(ppunto3,transform2);

window.draw(ppunto4,transform4);

}


void romb::hide(){

    punto1.color = sf::Color::Transparent;
    punto2.color = sf::Color::Transparent;

}


void romb::move(int mxx, int myy){

    transform.rotate(-alfa, sf::Vector2f(x,y));
    transform2 = transform;
    transform3 = transform;
    transform4 = transform;


    x+=mxx;
    y+=myy;
    dx+=mxx;
    dy+=myy; 
    

    punto1.position = sf::Vector2f(x,y);
    punto2.position = sf::Vector2f(dx,dy);


transform.rotate(alfa, sf::Vector2f(x,y));
transform2.rotate(-180+alfa, sf::Vector2f(dx,dy));
transform3.rotate(-alfa, sf::Vector2f(x,y));
transform4.rotate(-180 + alfa,sf::Vector2f(dx,dy));
transform4.combine(transform3);



}

void romb::rotate(double fi){

transform5.rotate(fi,sf::Vector2f(x,y));
transform = transform5;
transform2 = transform5;
transform3 = transform5;
transform4 = transform5;

transform.rotate(alfa, sf::Vector2f(x,y));
transform2.rotate(-180+alfa, sf::Vector2f(dx,dy));
transform3.rotate(-180+alfa, sf::Vector2f(dx,dy));
transform4 = transform3;
transform4.rotate(-alfa,sf::Vector2f(x,y));



}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////


class rect : public square{

protected: 
    double b;

    sf::RectangleShape rectangulo;

    sf::Vertex punto3;
    sf::Vertex punto4;
    sf::Vertex punto5;
    sf::Vertex punto6;

    sf::Transform transform6;

    //3 constructor + 1 destructor;

public:

    rect();
    rect(int xx, int yy, int dxx, int dyy, double bb);
    rect(int xx, int yy, int dxx, int dyy, double bb, int c);
    ~rect(){};

    void draw();
    void hide();
    void move(int mxx, int myy);
    void rotate(double fi);

};

rect::rect(): square(){

b = 50;

rectangulo.setSize(sf::Vector2f(pow( (pow(dx-x, 2)) + ( pow(dy-y, 2)), 0.5) ,b));

rectangulo.setRotation(AnguloDeInclinacion(x,y,dx,dy));

rectangulo.setPosition(sf::Vector2f(100,100));

rectangulo.setFillColor(sf::Color::Transparent);

rectangulo.setOutlineThickness(1);

}


rect::rect(int xx, int yy, int dxx, int dyy, double bb): square(xx, yy, dxx, dyy){

b =  bb;

rectangulo.setSize(sf::Vector2f(pow( (pow(dx-x, 2)) + ( pow(dy-y, 2)), 0.5) ,b));

rectangulo.setRotation(AnguloDeInclinacion(x,y,dx,dy));

rectangulo.setPosition(sf::Vector2f(x,y));

rectangulo.setFillColor(sf::Color::Transparent);

rectangulo.setOutlineThickness(1);

}



rect::rect(int xx, int yy, int dxx, int dyy, double bb, int c): square(xx, yy, dxx, dyy, c){

b =  bb;

double temp = sin((90 + AnguloDeInclinacion(x,y,dx,dy))*PI/180) * b;
double temp2 = cos((90 + AnguloDeInclinacion(x,y,dx,dy))*PI/180) * b;


std::cout<<temp << std:: endl<< temp2 << std::endl;

transform = transform5;
transform2 = transform5;
transform3 = transform5;
transform4 = transform5;

transform.rotate(90+AnguloDeInclinacion(x,y,dx,dy),sf::Vector2f(x,y));
transform2.rotate(AnguloDeInclinacion(x,y,dx,dy),sf::Vector2f(dx,dy));


transform4.translate(temp2,temp);




    punto3.position = sf::Vector2f(x,y);
    punto3.color = sf::Color(color*visable,255*visable,255*visable);
    punto4.position = sf::Vector2f(x+b,y);
    punto4.color = sf::Color(color*visable,255*visable,255*visable);
    punto5.position = sf::Vector2f(dx,dy);
    punto5.color = sf::Color(color*visable,255*visable,255*visable);
    punto6.position = sf::Vector2f(dx,dy+b);
    punto6.color = sf::Color(color*visable,255*visable,255*visable);








/*
rectangulo.setSize(sf::Vector2f(pow( (pow(dx-x, 2)) + ( pow(dy-y, 2)), 0.5) ,b));

rectangulo.setRotation(AnguloDeInclinacion(x,y,dx,dy));

rectangulo.setPosition(sf::Vector2f(x,y));

rectangulo.setFillColor(sf::Color::Transparent);

rectangulo.setOutlineThickness(1);

rectangulo.setOutlineColor(sf::Color(color*visable,255*visable,255*visable));


*/

}



void rect::draw(){



    ppunto1[0] = punto1;
    ppunto1[1] = punto2;

    ppunto2[0] = punto3;
    ppunto2[1] = punto4;

    ppunto3[0] = punto5;
    ppunto3[1] = punto6;

    ppunto4[0] = punto1;
    ppunto4[1] = punto2;



window.draw(ppunto1,transform5);

window.draw(ppunto2,transform);

window.draw(ppunto3,transform2);

window.draw(ppunto4,transform4);



window.draw(rectangulo);

}



void rect::hide(){

rectangulo.setOutlineColor(sf::Color::Transparent);


}


void rect::move(int mxx, int myy){

rectangulo.move(x+mxx,y+myy);

}


void rect::rotate(double fi){

rectangulo.rotate(fi);

transform.rotate(fi,sf::Vector2f(x,y));
transform2.rotate(fi,sf::Vector2f(x,y));





}





////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

class parallelepipedo : public romb, rect{

public:

        //3 constructor + 1 destructor
        parallelepipedo();
        parallelepipedo(int xx, int yy, int dxx ,int dyy, double al, double bb);

        parallelepipedo (int xx, int yy, int dxx ,int dyy, double al, double bb, int c);
        
        ~parallelepipedo();

        void draw();
        void hide();
        void move(int dxx, int dyy);
        void rotate(double fi);



};

parallelepipedo::parallelepipedo() : romb() , rect(){




}



parallelepipedo :: parallelepipedo (int xx, int yy, int dxx ,int dyy, double al, double bb, int c): 
romb(xx, yy, dxx, dyy, al, c),rect(xx,yy,dxx,dyy,bb,c){



}

*/

int main(){

    int counter = 0;


    point punto1;
    point punto2(100,200);
    point punto3(500,500,50);

    tline linea1;
    tline linea2(100, 200, 400 , 200);
    tline linea3(100, 300, 400, 300,0);

    square cuadrado1;
    square cuadrado2(300, 200, 800, 100);
    square cuadrado3(800, 600, 1100, 300, 50);

    romb rombo1;
    romb rombo2(800, 600, 1000, 400, 100, 50);

    rect rectangulo1;
    rect rectangulo2(800,600,1000,400,100,250);

    rect rectangulo3(600,300,800,200,50,50);





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

        cuadrado1.move(100,100);
        cuadrado3.move(-100,-100);

        cuadrado1.rotate(100);
        cuadrado3.rotate(45);

        //rombo1.hide();
        //rombo2.move(-100,100);
        rombo2.rotate(-70);

        rectangulo1.hide();
       // rectangulo3.hide();



        counter++;
    }

    //punto1.draw();
    //punto2.draw();
    //punto3.draw();

    //linea1.draw();
    //linea2.draw();
    //linea3.draw();
    //rombo2.rotate(-0.1);

    //cuadrado1.draw();
    //cuadrado2.draw();
    //cuadrado3.draw();

    //rombo1.draw();
    //rombo2.draw();

    rectangulo1.draw();
    rectangulo2.draw();
    rectangulo3.draw();
    rectangulo3.rotate(0.01);
    //rectangulo2.rotate(0.01);




    window.display();


}

    return 0;
}