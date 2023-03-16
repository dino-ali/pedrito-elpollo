#include <iostream>
using namespace std;

//La lista secundaria, por cada persona, tiene una lista de puntos (x,y) que almacena ubicaciones en dónde una persona ha estado.
class Ubicacion{
private:
    float x;
    float y;
    Ubicacion* next;
    
public:
    Ubicacion(){
        x = 0;
        y = 0;
        next = nullptr;
    }
    
    Ubicacion(float a, float b){
        x = a;
        y = b;
        next = nullptr;
    }
    
    float get_x(){
        return x;
    }
    
    float get_y(){
        return y;
    }
    
    void set_x(float a){
        x = a;
    }
    
    void set_y(float b){
        y = b;
    }
    
    void print(){
        cout << get_x() << ", " << get_y() << endl;
    }
};

class Persona{
private:
    int id;
    Persona* next_p;
    Ubicacion* next_s;
public:
    Persona(int a){
        id = a;
        next_p = nullptr;
        next_s = nullptr;
    }
    
    float get_id(){
        return id;
    }
    
};

class Sistema{
private:
    Persona* persona1;
    int num_personas;
public:
    
};

int main(){
    Ubicacion pata = Ubicacion(6, 8);
    pata.print();
    pata.set_x(5);
    pata.set_y(4);
    cout << "nuevas coordenadas: ";
    pata.print();
    
    return 0;
}
/*Construyan una estructura de datos que modele una base de datos de seguimiento geográfico a personas. La lista principal almacena a las personas y tiene un identificador único. Esta lista está ordenada.       
    La lista secundaria, por cada persona, tiene una lista de puntos (x,y) que almacena ubicaciones en dónde una persona ha estado.     
    El sistema debe permitir añadir personas, añadir puntos a una persona, buscar a una persona (búsqueda binaria) y buscar todas las personas que hayan estado en una área rectangular definida (pedir esquina superior izquierda y esquina inferior derecha).*/
