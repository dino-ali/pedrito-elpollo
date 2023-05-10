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
            }
        }
        //cout << "verificacion ";
    }
    
    T pop(){
        if(head == nullptr){
            cout << "esta cola esta vacía, no podés sacarle cosas. " << endl;
        }else{
            Nodo<T>* cursor = head;
            for(int i = 0; i < size-1; i++){
                cursor = cursor->get_next();
            }
            tail->set_next(cursor);
        }
        
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
    }
    
};

int main() {
    cout << "[21:19, 09/05/2023] samu<3. : Los que debes de hacer el un cursor que busque desde head el penúltimo elemento y luego iguales tail a ese elemento" << endl << "[21:19, 09/05/2023] samu<3. : Y elimine el que estaba antes en tail" << endl;
    
    Cola<char> pata;
    pata.change_cap(10);
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
    cout << pata.empty();
    
    
    pata.print();
    return 0;
}
