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
    
    ~Vector(){
        delete[] v;
    }
    
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
    
    void add (T val){
        if(size == cap){
            cap = cap*2;
            w = new T[cap];
            for (int i; i < cap; i++){
                w[i] = v[i];
                cout << w[i] <<  " ";
            }
            w[size] = val;
        }else{
            v[size] = val;
        }
        size++;
    }
    
    void print(){
        for (int i = 0; i < size; i++){
            cout << v[i] << "  ";
        }
    }
    /*void remove(T a){
        if (v[a] > v[size]){
            cout << "la posición sale del vector";
        }else{
            
        }
    }*/
};

int main() {
    srand (time(NULL));
    Vector<int> pata = Vector<int>();
    //cout << pata.get_size() << "\n";
    //cout << pata.get_cap();
    //int mmm = ;
    
    for (int i = 0; i < 10; i++){
        pata.add(rand()%25+1);
        
    }
    pata.print();
    return 0;
}
