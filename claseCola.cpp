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
class Cola{
private:
    int size;
    int cap;
    Nodo<T>* head;
    Nodo<T>* tail;
public:
    //constructor.
    Cola(){
        size = 0;
        cap = 4;
        head = nullptr;
        tail = nullptr;
    }
    
    //constructor sobrecargado.
    Cola(int z){
        size = 0;
        cap = z;
        head = nullptr;
        tail = nullptr;
    }
    
    ~Cola(){}
    
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
        if (head == nullptr){
            Nodo<T>* nuedo = new Nodo<T>(elem);
            head = nuedo;
            tail = head;
            size++;
        }else{
            if(size < cap){
                Nodo<T>* cursor = head;
                while(cursor->get_next() != nullptr){
                    cursor = cursor->get_next();
                }
                Nodo<T>* nuebo = new Nodo<T>(elem);
                cursor->set_next(nuebo);
                size++;
                tail = cursor->get_next();
            }
        }
    }
    
    T pop(){
        T dato;
        if(head == nullptr){
            cout << "esta cola esta vacía, no podés sacarle cosas. " << endl;
        }else{
            dato = head->get_dato();
            Nodo<T>* cursor = head;
            head = head->get_next();
            delete cursor; 
        }
        return dato;
    }
    
    T front(){
        return head->get_dato();
    }
    
    T back(){
        return tail->get_dato();
    }
    
    bool empty(){
        if(head == nullptr){
            return true;
        }else{
            return false;
        }
    }
    
    void print(){
        Nodo<T>* cursor = head;
        while(cursor != nullptr){
            cout << cursor->get_dato();
            cursor = cursor->get_next();
        }
        cout << endl;
    }
};

int main() {
    Cola<char> pata(7);
    pata.change_cap(20);
    pata.push('a');
    pata.push('g');
    pata.push('u');
    pata.push('a');
    pata.push('p');
    pata.push('a');
    pata.push('n');
    pata.push('e');
    pata.push('l');
    pata.push('a');
    pata.print();
    
    pata.pop();
    pata.print();
    cout << pata.front() << "   " << pata.back() << "   " << pata.get_size()  << "   " << pata.get_cap() << endl;
    cout << pata.empty() << endl;

    return 0;
}
