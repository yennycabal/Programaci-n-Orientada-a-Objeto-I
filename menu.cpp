#include <iostream>
#include <cmath>
using namespace std;

class Cuadrado
{
public:
    float lado;

    void area()
    {
        cout<<"Area: "<<lado*lado<<endl;
    }

    void perimetro()
    {
        cout<<"Perimetro: "<<lado*4<<endl;
    }

    void dibujar()
    {
        cout<<"* * * *"<<endl;
        cout<<"*     *"<<endl;
        cout<<"*     *"<<endl;
        cout<<"* * * *"<<endl;
    }

    void valores()
    {
        cout<<"Ingrese lado: ";
        cin>>lado;
    }
    void todas()
    {
        area();
        perimetro();
        dibujar();
    }
};

class Rectangulo
{
public:
    float largo, ancho;

    void area()
    {
        cout<<"Area: "<<largo*ancho<<endl;
    }

    void perimetro()
    {
        cout<<"Perimetro: "<<2*(largo+ancho)<<endl;
    }

    void dibujar()
    {
        cout<<"*******"<<endl;
        cout<<"*     *"<<endl;
        cout<<"*******"<<endl;
    }

    void valores()
    {
        cout<<"Ingrese largo: ";
        cin>>largo;
        cout<<"Ingrese ancho: ";
        cin>>ancho;
    }
    void todas()
    {
        area();
        perimetro();
        dibujar();
    }
};

class Triangulo
{
public:
    float base, altura, lado;

    void area()
    {
        cout<<"Area: "<<(base*altura)/2<<endl;
    }

    void perimetro()
    {
        cout<<"Perimetro: "<<lado*3<<endl;
    }

    void dibujar()
    {
        cout<<"  *"<<endl;
        cout<<" ***"<<endl;
        cout<<"*****"<<endl;
    }

    void valores()
    {
        cout<<"Ingrese base: ";
        cin>>base;
        cout<<"Ingrese altura: ";
        cin>>altura;
        cout<<"Ingrese lado: ";
        cin>>lado;
    }
    void todas()
    {
        area();
        perimetro();
        dibujar();
    }
};

class circulo
{
public:
    float radio;

    void area()
    {
        cout<<"Area: "<<3.1416*radio*radio<<endl;
    }
     void perimetro()
    {
        cout<<"Perimetro: "<<2*3.1416*radio<<endl;
    }
   void dibujar()
{
    cout<<"   *****   "<<endl;
    cout<<" **     ** "<<endl;
    cout<<"*         *"<<endl;
    cout<<"*         *"<<endl;
    cout<<" **     ** "<<endl;
    cout<<"   *****   "<<endl;
}
    void valores()
    {
        cout<<"Ingrese radio: ";
        cin>>radio;
    }
    void todas()
    {
        area();
        perimetro();
        dibujar();
    }
};
class rombo 
{
    public:
    float Diagonalmayor;
    float Diagonalmenor;
    float lado;

    void area()
    {
        cout<<"Area: "<<(Diagonalmayor*Diagonalmenor)/2<<endl;
    }

    void perimetro()
    {
        cout<<"Perimetro: "<<lado*4<<endl;
    }

    void dibujar()
{
    cout<<"    *    "<<endl;
    cout<<"   ***   "<<endl;
    cout<<"  *****  "<<endl;
    cout<<" ******* "<<endl;
    cout<<"  *****  "<<endl;
    cout<<"   ***   "<<endl;
    cout<<"    *    "<<endl;
}

    void valores()
    {
        cout<<"ingrese la diagonal mayor ";
        cin>>Diagonalmayor;
        cout<<"ingrese la diagonal menor ";
        cin>>Diagonalmenor;
        cout<<"Ingrese lado: ";
        cin>>lado;
    }
    void todas()
    {
        area();
        perimetro();
        dibujar();
    }
    
};
class paralelogramo 
{
    public:
    float base,altura,ladolateral;

    void area()
    {
        cout<<"Area: "<<base*altura<<endl;
    }

    void perimetro()
    {
        cout<<"Perimetro: "<<2*(ladolateral+base)<<endl;
    }

    void dibujar()
{
    cout<<"    ******"<<endl;
    cout<<"   ******"<<endl;
    cout<<"  ******"<<endl;
    cout<<" ******"<<endl;
}

    void valores()
    {
        cout<<"ingrse la base del paralelogramo : ";
        cin>>base;
        cout<<"ingrese la altura del paralelogramo : ";
        cin>>altura;
        cout<<"ingrese el lado lateral del paralelogramo : ";
        cin>>ladolateral;
    }
    void todas()
    {
        area();
        perimetro();
        dibujar();
    }
};
class trapecio 
{
  public:
    float Basemayor,Basemenor,altura,ladoizquierdo,ladoderecho;

    void area()
    {
        cout<<"Area: "<<(Basemayor+Basemenor)*altura/2<<endl;
    }

    void perimetro()
    {
        cout<<"Perimetro: "<<Basemayor+Basemenor+ladoizquierdo+ladoderecho<<endl;
    }

   void dibujar()
{
    cout<<"    ****    "<<endl;
    cout<<"   ******   "<<endl;
    cout<<"  ********  "<<endl;
    cout<<" ********** "<<endl;
}

    void valores()
    {
        cout<<"ingrese la base mayor : ";
        cin>>Basemayor;
        cout<<"ingrese la base menor : ";
        cin>>Basemenor;
        cout<<"ingrese la altura  : ";
        cin>>altura;
        cout<<"Ingrese lado izquierdo : ";
        cin>>ladoizquierdo;
        cout<<"ingrese el lado derecho ; ";
        cin>>ladoderecho;
    }  
    void todas()
    {
        area();
        perimetro();
        dibujar();
    }
};
class pentagono 
{
   public:
    float lado,apotema;

    void area()
    {
        cout<<"Area: "<<5*lado*apotema/2<<endl;
    }

    void perimetro()
    {
        cout<<"Perimetro: "<<5*lado<<endl;
    }

    void dibujar()
{
    cout<<"    ****    "<<endl;
    cout<<"   *    *   "<<endl;
    cout<<"  *      *  "<<endl;
    cout<<" *        * "<<endl;
    cout<<"************"<<endl;
}

    void valores()
    {
        cout<<"ingrese lado: ";
        cin>>lado;
        cout<<"ingrese la apotema : ";
        cin>>apotema;
    } 
    void todas()
    {
        area();
        perimetro();
        dibujar();
    }
};
class hexagono 
{
  public:
    float lado,apotema;

    void area()
    {
        cout<<"Area: "<<6*lado*apotema/2<<endl;
    }

    void perimetro()
    {
        cout<<"Perimetro: "<<lado*6<<endl;
    }

   void dibujar()
{
    cout<<"   ******   "<<endl;
    cout<<"  *      *  "<<endl;
    cout<<" *        * "<<endl;
    cout<<" *        * "<<endl;
    cout<<"  *      *  "<<endl;
    cout<<"   ******   "<<endl;
}

    void valores()
    {
        cout<<"Ingrese lado: ";
        cin>>lado;
        cout<<"ingrese la apotema :";
        cin>>apotema;
    }  
    void todas()
    {
        area();
        perimetro();
        dibujar();
    }
};
class heptagono 
{
    public:
    float lado,apotema;

    void area()
    {
        cout<<"Area: "<<7*lado*apotema/2<<endl;
    }

    void perimetro()
    {
        cout<<"Perimetro: "<<lado*7<<endl;
    }

    void dibujar()
{
    cout<<"    ******    "<<endl;
    cout<<"   *      *   "<<endl;
    cout<<"  *        *  "<<endl;
    cout<<" *          * "<<endl;
    cout<<"*            *"<<endl;
    cout<<"*            *"<<endl;
    cout<<" ************ "<<endl;
}

    void valores()
    {
        cout<<"ingrese la apotema : " ;
        cin>>apotema;
        cout<<"Ingrese lado: ";
        cin>>lado;
    }
    void todas()
    {
        area();
        perimetro();
        dibujar();
    }
};
class Esfera
{
public:
    float radio;

    void area()
    {
        cout<<"Area: "<<4*3.1416*radio*radio<<endl;
    }

    void volumen()
    {
        cout<<"Volumen: "<<(4.0/3)*3.1416*radio*radio*radio<<endl;
    }

    void valores()
    {
        cout<<"Ingrese radio: ";
        cin>>radio;
    }
    void todas()
    {
        area();
        volumen();
    }
};
class cilindro
{
public:
    float radio,altura;

    void area()
    {
        cout<<"Area: "<<2*3.1416*radio*(altura +radio)<<endl;
    }

    void volumen()
    {
        cout<<"Volumen: "<<3.1416*radio*radio*altura<<endl;
    }

    void valores()
    {
        cout<<"Ingrese radio: ";
        cin>>radio;
        cout<<"ingrese la altura : ";
        cin>>altura;
    }
    void todas()
    {
      area();
        volumen();
    }
};
class cono
{
public:
    float radio,generatriz,altura;

    void area()
    {
        cout<<"Area: "<<3.1416*radio*(radio+generatriz)<<endl;
    }

    void volumen()
    {
        cout<<"Volumen: "<<(1.0/3)*3.1416*radio*radio*altura<<endl;
    }

    void valores()
    {
        cout<<"Ingrese radio: ";
        cin>>radio;
         cout<<"ingrese la generatriz : ";
        cin>>generatriz;
        cout<<"ingrese la altura : ";
        cin>>altura;
    }
    void todas()
    {
        area();
        volumen();
    }
};
class cubo
{
public:
    float lado;

    void area()
    {
            cout<<"Area: "<<6*lado*lado<<endl;
    }

    void volumen()
    {
        cout<<"Volumen: "<<lado*lado*lado<<endl;
    }

    void valores()
    {
        cout<<"Ingrese lado: ";
        cin>>lado;
    }
    void todas ()
    {
        area();
        volumen();
    }
};
class piramide 
{
public:
    float lado,apotema,altura;

    void area()
    {
        cout<<"Area: "<<lado*lado+2*lado*apotema<<endl;
    }

    void volumen()
    {
        cout<<"Volumen: "<<(1.0/3)*lado*lado*altura<<endl;
    }

    void valores()
    {
        cout<<"Ingrese lado: ";
        cin>>lado;
        cout<<"ingrese la apotema : ";
        cin>>apotema;
        cout<<"ingrese la altura : ";
        cin>>altura;
    }
    void todas()
    {
        area();
        volumen();
    }
    
};

void menuCuadrado(Cuadrado &c)
{
    int op;
c.valores();
    do
    {
        cout<<"\n=== CUADRADO ==="<<endl;
        cout<<"1. Area"<<endl;
        cout<<"2. Perimetro"<<endl;
        cout<<"3. Dibujar"<<endl;
        cout<<"4.todas "<<endl;
        cout<<"5. Volver"<<endl;
        cin>>op;

        switch(op)
        {
            case 1: c.area(); break;
            case 2: c.perimetro(); break;
            case 3: c.dibujar(); break;
            case 4: c.todas(); break;
            case 5: break;
            default: cout<<"Opcion incorrecta"<<endl;
        }

    }while(op!=5);
}


void menuRectangulo(Rectangulo &r)
{
    int op;
r.valores();
    do
    {
        cout<<"\n=== RECTANGULO ==="<<endl;
        cout<<"1. Area"<<endl;
        cout<<"2. Perimetro"<<endl;
        cout<<"3. Dibujar"<<endl;
        cout<<"4.todas "<<endl;
        cout<<"5. Volver"<<endl;
        cin>>op;

        switch(op)
        {
            case 1: r.area(); break;
            case 2: r.perimetro(); break;
            case 3: r.dibujar(); break;
           case 4: r.todas(); break;
            case 5: break;
            default: cout<<"Opcion incorrecta"<<endl;
        }

    }while(op!=5);
}


void menuTriangulo(Triangulo &t)
{
    int op;
t.valores();
    do
    {
        cout<<"\n=== TRIANGULO ==="<<endl;
        cout<<"1. Area"<<endl;
        cout<<"2. Perimetro"<<endl;
        cout<<"3. Dibujar"<<endl;
        cout<<"4.todas "<<endl;
        cout<<"5. Volver"<<endl;
        cin>>op;

        switch(op)
        {
            case 1: t.area(); break;
            case 2: t.perimetro(); break;
            case 3: t.dibujar(); break;
            case 4: t.todas(); break;
            case 5: break;
            default: cout<<"Opcion incorrecta"<<endl;
        }

    }while(op!=5);
}
void menucirculo(circulo &c)
{
    int op;
c.valores();
    do
    {
        cout<<"\n=== TRIANGULO ==="<<endl;
        cout<<"1. Area"<<endl;
        cout<<"2. Perimetro"<<endl;
        cout<<"3. Dibujar"<<endl;
        cout<<"4.todas "<<endl;
        cout<<"5. Volver"<<endl;
        cin>>op;

        switch(op)
        {
            case 1: c.area(); break;
            case 2: c.perimetro(); break;
            case 3: c.dibujar(); break;
           case 4: c.todas(); break;
            case 5: break;
            default: cout<<"Opcion incorrecta"<<endl;
        }

    }while(op!=5);
}

void menurombo(rombo &r)
{
    int op;
r.valores();
    do
    {
        cout<<"\n=== TRIANGULO ==="<<endl;
        cout<<"1. Area"<<endl;
        cout<<"2. Perimetro"<<endl;
        cout<<"3. Dibujar"<<endl;
        cout<<"4.todas "<<endl;
        cout<<"5. Volver"<<endl;
        cin>>op;

        switch(op)
        {
            case 1: r.area(); break;
            case 2: r.perimetro(); break;
            case 3: r.dibujar(); break;
           case 4: r.todas(); break;
            case 5: break;
            default: cout<<"Opcion incorrecta"<<endl;
        }

    }while(op!=5);
}
void menuparalelogramo(paralelogramo &p)
{
    int op;
p.valores();
    do
    {
        cout<<"\n=== TRIANGULO ==="<<endl;
        cout<<"1. Area"<<endl;
        cout<<"2. Perimetro"<<endl;
        cout<<"3. Dibujar"<<endl;
        cout<<"4.todas "<<endl;
        cout<<"5. Volver"<<endl;
        cin>>op;

        switch(op)
        {
            case 1: p.area(); break;
            case 2: p.perimetro(); break;
            case 3: p.dibujar(); break;
           case 4: p.todas(); break;
            case 5: break;
            default: cout<<"Opcion incorrecta"<<endl;
        }

    }while(op!=5);
}
void menutrapecio(trapecio &t)
{
    int op;
t.valores();
    do
    {
        cout<<"\n=== TRIANGULO ==="<<endl;
        cout<<"1. Area"<<endl;
        cout<<"2. Perimetro"<<endl;
        cout<<"3. Dibujar"<<endl;
        cout<<"4.todas "<<endl;
        cout<<"5. Volver"<<endl;
        cin>>op;

        switch(op)
        {
            case 1: t.area(); break;
            case 2: t.perimetro(); break;
            case 3: t.dibujar(); break;
           case 4: t.todas(); break;
            case 5: break;
            default: cout<<"Opcion incorrecta"<<endl;
        }

    }while(op!=5);
}
void menupentagono(pentagono &p)
{
    int op;
p.valores();
    do
    {
        cout<<"\n=== TRIANGULO ==="<<endl;
        cout<<"1. Area"<<endl;
        cout<<"2. Perimetro"<<endl;
        cout<<"3. Dibujar"<<endl;
       cout<<"4.todas "<<endl;
        cout<<"5. Volver"<<endl;
        cin>>op;

        switch(op)
        {
            case 1: p.area(); break;
            case 2: p.perimetro(); break;
            case 3: p.dibujar(); break;
           case 4: p.todas(); break;
            case 5: break;
            default: cout<<"Opcion incorrecta"<<endl;
        }

    }while(op!=5);
}
void menuhexagono(hexagono &h)
{
    int op;
h.valores();
    do
    {
        cout<<"\n=== TRIANGULO ==="<<endl;
        cout<<"1. Area"<<endl;
        cout<<"2. Perimetro"<<endl;
        cout<<"3. Dibujar"<<endl;
       cout<<"4.todas "<<endl;
        cout<<"5. Volver"<<endl;
        cin>>op;

        switch(op)
        {
            case 1: h.area(); break;
            case 2: h.perimetro(); break;
            case 3: h.dibujar(); break;
            case 4: h.todas(); break;
            case 5: break;
            default: cout<<"Opcion incorrecta"<<endl;
        }

    }while(op!=5);
}
void menuheptagono(heptagono &h)
{
    int op;
h.valores();
    do
    {
        cout<<"\n=== TRIANGULO ==="<<endl;
        cout<<"1. Area"<<endl;
        cout<<"2. Perimetro"<<endl;
        cout<<"3. Dibujar"<<endl;
       cout<<"4.todas "<<endl;
        cout<<"5. Volver"<<endl;
        cin>>op;

        switch(op)
        {
            case 1: h.area(); break;
            case 2: h.perimetro(); break;
            case 3: h.dibujar(); break;
            case 4: h.todas(); break;
            case 5: break;
            default: cout<<"Opcion incorrecta"<<endl;
        }

    }while(op!=5);
}



void menuEsfera(Esfera &e)
{
    int op;
e.valores();
    do
    {
        cout<<"\n=== ESFERA ==="<<endl;
        cout<<"1. Area"<<endl;
        cout<<"2. Volumen"<<endl;
        cout<<"3.todas"<<endl;
        cout<<"4. Volver"<<endl;
        cin>>op;

        switch(op)
        {
            case 1: e.area(); break;
            case 2: e.volumen(); break;
            case 3: e.todas(); break;
            case 4: break;
            default: cout<<"Opcion incorrecta"<<endl;
        }

    }while(op!=4);
}
void menucilindro(cilindro &c)
{
    int op;
c.valores();
    do
    {
        cout<<"\n=== ESFERA ==="<<endl;
        cout<<"1. Area"<<endl;
        cout<<"2. Volumen"<<endl;
        cout<<"3.todas"<<endl;
        cout<<"4. Volver"<<endl;
        cin>>op;

        switch(op)
        {
            case 1: c.area(); break;
            case 2: c.volumen(); break;
            case 3: c.todas(); break;
            case 4: break;
            default: cout<<"Opcion incorrecta"<<endl;
        }

    }while(op!=4);
}
void menucono(cono &c)
{
    int op;
c.valores();
    do
    {
        cout<<"\n=== ESFERA ==="<<endl;
        cout<<"1. Area"<<endl;
        cout<<"2. Volumen"<<endl;
        cout<<"3.todas"<<endl;
        cout<<"4. Volver"<<endl;
        cin>>op;

        switch(op)
        {
            case 1: c.area(); break;
            case 2: c.volumen(); break;
            case 3: c.todas(); break;
            case 4: break;
            default: cout<<"Opcion incorrecta"<<endl;
        }

    }while(op!=4);
}
void menucubo(cubo &c)
{
    int op;
c.valores();
    do
    {
        cout<<"\n=== ESFERA ==="<<endl;
        cout<<"1. Area"<<endl;
        cout<<"2. Volumen"<<endl;
        cout<<"3.todas"<<endl;
        cout<<"4. Volver"<<endl;
        cin>>op;

        switch(op)
        {
            case 1: c.area(); break;
            case 2: c.volumen(); break;
            case 3: c.todas(); break;
            case 4: break;
            default: cout<<"Opcion incorrecta"<<endl;
        }

    }while(op!=4);
}
void menupiramide(piramide &p)
{
    int op;
p.valores();
    do
    {
        cout<<"\n=== ESFERA ==="<<endl;
        cout<<"1. Area"<<endl;
        cout<<"2. Volumen"<<endl;
        cout<<"3.todas"<<endl;
        cout<<"4. Volver"<<endl;
        cin>>op;

        switch(op)
        {
            case 1: p.area(); break;
            case 2: p.volumen(); break;
            case 3: p.todas(); break;
            case 4: break;
            default: cout<<"Opcion incorrecta"<<endl;
        }

    }while(op!=4);
}


int main()
{
    Cuadrado cuadrado;
    Rectangulo rectangulo;
    Triangulo triangulo;
    circulo circulo;
    rombo rombo;
   paralelogramo paralelogramo;
    trapecio trapecio;
    pentagono pentagono;
    hexagono hexagono;
    heptagono heptagono;
    Esfera esfera;
    cilindro cilindro;
    cono cono;
    cubo cubo;
    piramide piramide;

    int op, op2;

    do
    {
        cout<<"\n========================"<<endl;
        cout<<"     MENU PRINCIPAL"<<endl;
        cout<<"========================"<<endl;
        cout<<"1. Figuras 2D"<<endl;
        cout<<"2. Figuras 3D"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>op;

        switch(op)
        {
            case 1:

                do
                {
                    cout<<"\n=== FIGURAS 2D ==="<<endl;
                    cout<<"1. Cuadrado"<<endl;
                    cout<<"2. Rectangulo"<<endl;
                    cout<<"3. Triangulo"<<endl;
                    cout<<"4. circulo"<<endl;
                    cout<<"5.rombo"<<endl;
                    cout<<"6.paralelogramo"<<endl;
                    cout<<"7.trapecio"<<endl;
                    cout<<"8. pentagono "<<endl;
                    cout<<"9.hexagono "<<endl;
                    cout<<"10.heptagono"<<endl;
                    cout<<"11. Volver"<<endl;
                    cout<<"Opcion: ";
                    cin>>op2;

                    switch(op2)
                    {
                        case 1:
                            menuCuadrado(cuadrado);
                            break;

                        case 2:
                            menuRectangulo(rectangulo);
                            break;

                        case 3:
                            menuTriangulo(triangulo);
                            break;
                         case 4:
                            menucirculo(circulo);
                            break;
                         case 5:
                            menurombo(rombo);
                            break;
                         case 6:
                            menuparalelogramo(paralelogramo);
                            break;
                         case 7:
                            menutrapecio(trapecio);
                            break;
                         case 8:
                            menupentagono(pentagono);
                            break;
                         case 9:
                            menuhexagono(hexagono);
                            break;
                         case 10:
                            menuheptagono(heptagono);
                            break;

                        case 11:
                            break;

                        default:
                            cout<<"Opcion incorrecta"<<endl;
                    }

                }while(op2!=11);

                break;


            case 2:

                do
                {
                    cout<<"\n=== FIGURAS 3D ==="<<endl;
                    cout<<"1. Esfera"<<endl;
                    cout<<"2. cilindro"<<endl;
                     cout<<"3. cono"<<endl;
                     cout<<"4. cubo"<<endl;
                     cout<<"5.piramide"<<endl;
                    cout<<"6. Volver"<<endl;
                    cout<<"Opcion: ";
                    cin>>op2;

                    switch(op2)
                    {
                        

                        case 1:
                            menuEsfera(esfera);
                            break;
                        case 2:
                            menucilindro(cilindro);
                            break;
                        case 3:
                            menucono(cono);
                            break;
                        case 4:
                            menucubo(cubo);
                            break;
                        case 5:
                            menupiramide(piramide);
                            break;

                        case 6:
                            break;

                        default:
                            cout<<"Opcion incorrecta"<<endl;
                    }

                }while(op2!=6);

                break;


            case 3:
                cout<<"Fin del programa"<<endl;
                break;

            default:
                cout<<"Opcion incorrecta"<<endl;
        }

    }while(op!=3);

    return 0;
}