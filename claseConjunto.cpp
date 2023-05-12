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
class Conjunto{
private:
    int size;
    int cap;
    Nodo<T>* elemento;

public:
    Conjunto(){
        size = 0;
        cap = 10;
        elemento = nullptr;
    }
    
    Conjunto(int c){
        size = 0;
        cap = c;
        elemento = nullptr;
    }
    
    ~Conjunto(){}
    
    int get_size(){
        return size;
    }
    
    int get_cap(){
        return cap;
    }
    
    bool contains(int x){
        Nodo<T>* cursor = elem;
        while(cursor->get_next() != nullptr){
            if(cursor->get_dato() == x){
                return true;
            }
            cursor = cursor->get_next();
        }
        return false;
    }
    
    bool empty(){
        
        
    }
};



int main() {
    // Write C++ code here
    std::cout << "Hello world!";

    return 0;
}
