// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include<string>
#include <math.h> 

using namespace std;

template<typename T>
class Card {

//Atributos
    T val;
  
public:
    
    //Constructores
    Card(T val1) {
        val = val1;
       
    }

    Card() {
        val = 0;
        
    }
    
    ~Card(){}

    //M�todos
    
   
    //Getters
    T getVal() {
        return val;
    }

    void setVal(T v) {
        val = v;
    }
    
    Card& operator=(const Card& f) { 
		setVal(f.val);
		return *this; 
	}
	
	string to_string() {
		//return std::to_string(val);
		string s = "";
		s+=val;
		return s;
	}


	friend std::ostream& operator<<(std::ostream& os, Card& b) {
		return os << b.to_string();
	}

};

template <typename T>
class Nodo{
  
  Card<T>* dato;
  Nodo* pointer;
  
public:
  
  Nodo(){
      dato = NULL;
      pointer = NULL;
  }
  
  ~Nodo(){
      delete dato;
  }
  
  Nodo(Card<T>* d){
      dato = d;
      pointer = NULL;
  }
    
  Card<T>* getDato(){
      return dato;
  }
  
  void setDato(Card<T>* d){
      dato = d;
  }
  
  Nodo* getNext(){
      return pointer;
  }
  
  void setNext(Nodo* p){
      pointer = p;
  }
    
    string to_string() {
		return getDato()->to_string();
	}


	friend std::ostream& operator<<(std::ostream& os, Nodo& b) {
		return os << b.to_string();
	}
    
};


class Pila{
    
    Nodo<char>* ptr;
    Nodo<char>* first;
    int n;
    int size;

public:  

    Pila(){
        ptr = NULL;
        first = NULL;
        size = 0;
        n = 10;
    }
    
    Pila(int nc){
        ptr = NULL;
        first = NULL;
        size = 0;
        n = nc;
    }
    
    ~Pila(){
        Nodo<char>* t = ptr;
        Nodo<char>* n;
        while(t->getNext() != NULL){
            n = t;
            t = t->getNext();    
            delete n;
        }
        delete t;
    }
    
    void push(Card<char>* d){
        
        if(size == 0){
            cout<<"Entre0"<<endl;
            ptr = new Nodo<char>(d);
            first = ptr;
            size++;
        }else{
            cout<<"Entre1"<<endl;
            Nodo<char>* t = ptr;
            Nodo<char>* tn = new Nodo<char>(d);
            tn->setNext(t);
            ptr = tn;
            
            if(size < n){
                size++;
            }else{
                cout<<"Entre2"<<endl;
                t = ptr;
                tn = first;
                for(int i=0; i<n-1; i++){
                    t = t->getNext();
                }
                cout<<"Penultimo nodo: "<<(*t)<<endl;
                first = t;
                first->setNext(NULL);
                delete tn;
            }
            
        }
        
    }
    
    Card<char>* pop(){
        Nodo<char>* t = ptr;
        Card<char>* c = new Card<char>(t->getDato()->getVal());
        ptr = ptr->getNext();
        size--;
        delete t;
        return c;
    }
    
    void add(Card<char>* c){
        push(c);
    }
    
    void deshacer(){
        Card<char>* c = pop();
    }
    
    Card<char>* peek(){
        if(ptr != NULL)
            return ptr->getDato();
        return new Card<char>();
    }
    
    int getSize(){
        return size;
    }
    
    void print(){
        if(size == 0){
            cout<<"La lista está vacía"<<endl;
        }else{
            Nodo<char>* t = ptr;
            do{
                cout<<(*t)<<", ";
                t = t->getNext();
                
            }while(t != NULL);
            cout<<endl;
        }
    }
    
    
};


int main()
{
   
   Pila l = Pila(7);
   l.add(new Card<char>('H'));
   l.add(new Card<char>('o'));
   l.add(new Card<char>('l'));
   l.add(new Card<char>('a'));
   l.add(new Card<char>(' '));
   l.add(new Card<char>('m'));
   l.add(new Card<char>('u'));
   l.add(new Card<char>('n'));
   l.add(new Card<char>('d'));
   l.add(new Card<char>('o'));
   l.print();
   l.deshacer();
   l.deshacer();
   l.deshacer();
   l.deshacer();
   l.add(new Card<char>('a'));
   l.add(new Card<char>('m'));
   l.add(new Card<char>('a'));
   l.print();
   
   
   return 0;
}
