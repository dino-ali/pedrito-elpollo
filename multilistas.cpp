#include<iostream>
using namespace std; 
	

template<typename T, typename T2>
class NodoS{
private:
    T dato;
    NodoS* next;
    T2* l;
    
public:
    NodoS(T d){
         dato = d;
         next =  NULL;
         l =  new T2();
     }
     
     ~NodoS(){}
     
     void add(T d){
         l->add(d);
     }
     
     T get_dato(){
         return dato;
     }
     
     void set_dato(T d){
         dato = d;
     }
     
     NodoS* get_next(){
         return next;
     }
     
     T2* get_lista(){
         return l;
     }
     
    void set_next(NodoS* n){
         next = n;
     }
    
    void print(){
        cout<<dato<<" ";
        l.print();
    }
    
    string to_string() {
	    return std::to_string(dato);
	}

	friend std::ostream& operator<<(std::ostream& os, NodoS<T,T2>& b) {
		return os << b.to_string();
	}
};

template<typename T>
class Lista{
private:
    NodoS<T,Lista>* ptr;
    int size;
    
public:
    Lista(){
        ptr = NULL;
        size = 0;
    }
    
    void add(T d){
        NodoS<T,Lista>* nodo = new NodoS<T,Lista>(d);
        if(ptr == NULL){//La lista está vacía
            ptr  = nodo;
        }else{//La lista no está vacía
            NodoS<T,Lista>* temp =  ptr;
            while(temp->get_next() != NULL){
                temp = temp->get_next();
            }
            temp->set_next(nodo);
        }
        size++;
    }
    
    void print(){
        if(ptr == NULL){//La lista está vacía
            cout<<"La lista está vacía"<<endl;
        }else{//La lista no está vacía
            NodoS<T,Lista>* temp =  ptr;
            while(temp != NULL){
                //cout<<temp->get_dato()<<","<<temp->get_next()<<"\t";
                cout<<temp->get_dato()<<"\n";
                temp->get_lista()->print();
                temp = temp->get_next();
            }
            cout<<endl;
        }
    }
    
    NodoS<T,Lista>* get(int i){
        if(i>=0 && i<size){
          int j=0;
          NodoS<T,Lista>* temp = ptr;
          while(j<i){
              temp = temp->get_next();
              j++;
          }
          return temp;
        }
        return NULL;
    }
};

template <typename T>
class NodoP{
private:
    int id;
    Lista<T> sapo;
    NodoP* next;
public:
    NodoP(){
        d = id;
        o = new Lista<
    }
};

int main(){
    Lista<int> l;
    
    for(int i=0; i<10; i++){
        l.add(i);
        for(int j=0; j<5; j++){
            l.get(i)->add(i*5+j);
        }
    }
    
    l.print();
    
    return 0;
}
