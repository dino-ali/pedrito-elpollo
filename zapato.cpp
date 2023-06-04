#include<iostream>
using namespace std;

template<typename T>
class Nodo{
private:
    T dato;
    Nodo* izq;
    Nodo* der;
    
public:
    Nodo(T d){
        dato = d;
        izq =  NULL;
        der =  NULL;
    }
     
    ~Nodo(){
    }
     
    T get_dato(){
        return dato;
    }
     
    void set_dato(T d){
        dato = d;
    }
     
    Nodo* get_izq(){
        return izq;
    }
     
    Nodo* get_der(){
        return der;
    }
     
    void set_izq(Nodo* n){
        izq = n;
    }
     
    void set_der(Nodo* n){
        der = n;
    }
     
    bool is_hoja(){
        return (der == NULL && izq == NULL);
    }
    
};

template<typename T>
class Arbol{
private:
  Nodo<T>* raiz;

public:
    Arbol(){
        raiz = NULL;
    }
  
    ~Arbol(){
        
    }
    
    void add(T d){
        add(d, raiz);
    }
    
    void add(T d, Nodo<T>* r){
        if(r == NULL){//El árbol está vacío
            raiz  = new Nodo<T>(d);
        }else{
            if(r->get_dato() > d){
                if(r->get_izq() == NULL){
                   r->set_izq(new Nodo<T>(d)); 
                }else{
                    add(d, r->get_izq());
                }
            }else{
                if(r->get_der() == NULL){
                   r->set_der(new Nodo<T>(d)); 
                }else{
                    add(d, r->get_der());
                }
            }
        }
        
    }
    
    Nodo<T>* get_raiz(){
        return raiz;
    }
    
    void print(){
        print(raiz);
    }
    
    void print2(){
        print2(raiz);
    }
    
    void print(Nodo<T>* r){
        if(r != NULL){
            print(r->get_izq());
            print(r->get_der());
            cout<<r->get_dato()<<"\t";
        }
    }
    
    void print2(Nodo<T>* r){
        if(r != NULL){
            print2(r->get_izq());
            cout<<r->get_dato()<<"\t";
            print2(r->get_der());
        }
    }
    
    int altura(){
        return altura(raiz);
    }

    int altura(Nodo<T>* r){
        if(r->is_hoja()){
            return 0;
        }else{
            int max = -1;
            if(r->get_izq() != NULL){
                max = altura(r->get_izq());
            }
            if(r->get_der() != NULL){
                int temp = altura(r->get_der());
                if(max < temp){
                    max = temp;
                }
            }
            return max+1;
        }
    }
    
    void max_level(){
        max_level(raiz);
    }

    void max_level(Nodo<T>* r){
        if(r != NULL and altura(r) == 2){
            print2(r->get_izq());
            cout<<r->get_dato()<<"\t";
            print2(r->get_der());
        }else{
            max_level(r->get_izq());
            cout<< endl;
            max_level(r->get_der());
        }
    }

    void print3(Nodo<T>* r, int i){
        if(r != NULL and i <= 2){
            i++;
            print3(r->get_izq(), i);
            cout<<r->get_dato()<<"\t";
            print3(r->get_der(), i);
        }
    }
    
    void espejito(Nodo<T>* n){
        if (n == NULL){
            return;
        }else{
            Nodo<T>* temp = new Nodo<T>(0);
            espejito(n->get_izq());
            espejito(n->get_der());
    
            temp = n->get_izq();
            n->set_izq(n->get_der());
            n->set_der(temp);
        }
    }
};

template <typename T>
Arbol<T> espejitoo(Arbol<T> arbol){
    arbol.espejito(arbol.get_raiz());
    return arbol;
}


int main(){
    Arbol<int> arbolito;
    srand(1234);
    arbolito.add(9);
    arbolito.add(7);
    arbolito.add(5);
    arbolito.add(3);
    arbolito.add(8);
    arbolito.add(12);
    arbolito.add(10);
    arbolito.add(11);
    arbolito.print();
    cout<<endl;
    arbolito.print2();
    cout<<endl;
    
    cout << "punto 1:  " << endl; 
    Arbol<int> arbolote;
    arbolote = espejitoo(arbolito);
    arbolote.print2();
    
    cout << "punto 2:  " << endl;
    //arbolito.max_level();
    cout<<endl;
    arbolito.print3(arbolito.get_raiz(), 0);
    cout<<endl;
    cout<<"La altura del arbol es: "<<to_string(arbolito.altura())<<endl<<endl;
   
    
    return 0;
}
