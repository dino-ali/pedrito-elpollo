#include <iostream>
#include <ctime>
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
    
    int binary_s(int n, int x){
        int ini = 0;
        int fin = n-1;
        while(ini <= fin){
            int i = (fin+ini)/2;
            if(v[i] == x){
                return i;
            }
            else{
                if(v[i]>x){
                    fin = i-1;
                }
                else{
                    ini = i+1;
                }
            }    
        }
        return -1;
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
    Vector<int> pata = Vector<int>(50);
    for(int i = 0; i < pata.get_cap(); i++){
        pata.add(i*3);
    }
    pata.print();

    double start = double(clock()) / CLOCKS_PER_SEC;
    pata.binary_s(10, 18);
    double finish = double(clock()) / CLOCKS_PER_SEC;
    double elapsed = finish - start;
    
    cout << pata.get_size() << ":  " << elapsed << endl;

    return 0;
}
