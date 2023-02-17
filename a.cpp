#include <iostream>
#include <math.h>
using namespace std;

template<typename T>
class Vector{ //nombre de la clase siempre va en mayúscula.
private: //no puede tener acceso por fuera, lo protege.
    int size;
    int cap;
    T* v; //vector con dato genérico.
    T* w;
    
public:
    //constructor
    Vector(){
        size = 0;
        cap = 5;
        v = new T[cap];
    }
    
    //sobrecarga.
    Vector(int n){
        size = 0;
        cap = n;
        v = new T[cap];
    }
    
    //destructor.
    ~Vector(){
        delete[] v;
    }
    
    //get "mondá".
    int get_size(){
        return size;
    }
    
    int get_cap(){
        return cap;
    }
    
    //retorna el valor en i posición.
    T get (int i){
        if(i >= 0 and i < size){
            return v[i];
        }else{
            return NULL;
        }
    }
    
    //add = push_back, same shit.
    void add (T val){
        if(size == cap){
            int vieja = cap;
            cout << "incrementando capacidad... " << endl;
            int nueva = cap*2;
            w = new T[nueva];
            cout << "nueva capacidad: " << nueva << endl;
            for (int i = 0; i < vieja; i++){
                w[i] = v[i];
                //cout << w[i] <<  " ";
            }
            w[size] = val;
            delete[] v;
            v = new T[nueva];
            for (int i = 0; i < nueva; i++){
                v[i] = w[i];
                //cout << w[i] <<  " ";
            }
        }else{
            v[size] = val;
        }
        size++;
    }
    
    void print(){
        for (int i = 0; i < size; i++){
            cout << v[i] << "  ";
        }
        cout << endl;
    }
    
    void remove_(T a){
       if(a < size){
           for (int i = a; i < size; i++){
               v[a] = v[a+1];
           }
       }else{
           cout << "la posición sale del vector. " << endl;
       }
    }
};


int main() {
    //srand (time(NULL));
    Vector<int> pata = Vector<int>();
    //cout << pata.get_size() << "\n";
    //cout << pata.get_cap();
    pata.add(1);
    pata.add(5);
    pata.add(3);
    pata.add(5);
    pata.add(2);
    pata.add(6);
    /*pata.add(7);*/

    pata.print();
    
    /*pata.remove_(9);
    pata.print();*/
    return 0;
}
 
