#include <iostream>
using namespace std;

template<typename T>
class Nodo{
private:
    T dato;
    Nodo* next;

public:
    Nodo(T d){
        dato = d;
        next =  nullptr;
    }
    
    ~Nodo(){}
 
    T get_dato(){
        return dato;
    }
 
    void set_dato(T d){
        dato = d;
    }
 
    Nodo* get_next(){
        return next;
    }
    
    void set_next(Nodo* n){
        next = n;
    }
};

template <typename T>
class Pila{
private:
    Nodo<T>* peak;
    int size;
    int cap;

public:
    Pila(){
        peak = nullptr;
        size = 0;
        cap = 8;
    }
    
    Pila (int q){
        peak = nullptr;
        size = 0;
        cap = q;
    }
    
    ~Pila(){}
    
    int get_size(){
        return size;
    }
    
    int get_cap(){
        return cap;
    }
    
    void change_cap(int c){
        cap = c;
        cout << "nueva capacidad: " << cap << endl;
    }
    
    void push(T elem){
        Nodo<T>* nuedo = new Nodo<T>(elem);
        if (peak == nullptr){
            peak = nuedo;
            size++;
        }else{
            if(size < cap){
                nuedo->set_next(peak);
                peak = nuedo;
                size++;
            }
        }
    }
    
    T pop(){
        T dato;
        if(peak == nullptr){
            cout << "esta pila esta vacía, no podés sacarle cosas. " << endl;
        }else{
            dato = peak->get_dato();
            Nodo<T>* cursor = peak;
            peak = peak->get_next();
            delete cursor; 
            return dato;
        }
    }
    
    T peaak(){
        return peak->get_dato();
    }
    
    bool empty(){
        if(peak == nullptr){
            return true;
        }else{
            return false;
        }
    }
    
    void print(){
        Nodo<T>* cursor = peak;
        while(cursor != nullptr){
            cout << cursor->get_dato() << " ";
            cursor = cursor->get_next();
        }
        cout << endl;
    }

};

int main() {
    Pila<int> yoongi(11);
    cout << "pila original: " << endl;
    yoongi.push(12);
    yoongi.push(23);
    yoongi.push(34);
    yoongi.print();
    
    cout << "   " << endl;
    cout << "nueva pila: " << endl;
    yoongi.pop();
    yoongi.print();
    
    cout << "   " << endl;
    cout << "datos de la pila: " << endl;
    cout << "peak: " << yoongi.peaak() << endl;
    cout << "size: " << yoongi.get_size() << endl; 
    cout << "capacidad: " << yoongi.get_cap() << endl;
    cout << yoongi.empty() << endl;
    return 0;
}
