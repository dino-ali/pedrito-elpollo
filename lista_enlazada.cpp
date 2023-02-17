#include <iostream>
using namespace std;

template <typename T>
class Nodo{
private:
    T dato;
    Nodo* next;
public:
    Nodo(T d){
        dato = d;
        next = nullptr;
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
class Lista{
private:
    Nodo<T>* ptr;
    int size;
public:
    Lista(){
        ptr = nullptr;
        size = 0;
    }
    
    ~Lista(){
        Nodo<T>* temp = ptr;
        if(ptr != nullptr){
            Nodo<T>* temp_next = ptr->get_next();
            while(temp_next != nullptr){
                delete temp;
                temp = temp_next;
                temp_next = temp->get_next();
            }
            delete temp; // borra el ultimo nodo.
        }
    }
    
    void add(T d){
        Nodo<T>* nodo = new Nodo<T>(d);
        if (ptr == nullptr){
            ptr = nodo; //lista vacia
        }else{
            Nodo<T>* temp = ptr;
            while(temp -> get_next() != nullptr){
                temp = temp -> get_next();
            }
            temp -> set_next(nodo);
        }
        size++;
    }
    
    void print(){
         if (ptr == nullptr){
            cout << "lista vacia" << endl;
        }else{
            Nodo<T>* temp = ptr;
            while(temp -> get_next() != nullptr){
                cout << temp -> get_dato() << "\t";
                temp = temp -> get_next();
            }
            cout << endl;
        }
    }
    
    
};

// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
int main() {
    Lista<int> listita;
    listita.print();
    
    for (int i = 0; i < 10; i++){
        listita.add(i);
    }
        
    listita.print();
    return 0;
}
