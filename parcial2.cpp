#include<iostream>
using namespace std;

template<typename T>
class Nodo{
private:
  T dato;
  Nodo* next;

public:

 Nodo(T d){
     dato = d;
     next =  NULL;
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

class Tarjeta{
private:
    int color;
    int numero;
    
public:
    Tarjeta(){
        color = 0;
        numero = 0;
    }
    
    Tarjeta(int c, int n){
        color = c;
        numero = n;
    }
    
    int get_color(){
        return color;
    }
    
    int get_numero(){
        return numero;
    }
    
    int get_valor(){
        int val;
        if (numero == 0){
            val = 20;
        }else{
            val = numero;
        }
        return val;
    }
    
    string to_string(){
        return "("+std::to_string(color)+","+std::to_string(numero)+")";
    }
    
    Tarjeta& operator=(const Tarjeta& f) { 
		color = f.color;
		numero = f.numero;
		return *this;
	}
    
    void print(){
        cout<<to_string();
    }
    
    friend std::ostream& operator<<(std::ostream& os, Tarjeta& b) {
		return os << b.to_string();
	}
	
	friend std::ostream& operator<<(std::ostream& os, Tarjeta* b) {
		return os << b->to_string();
	}
    
};

class Jugador{
private:
    int id;
    Nodo<Tarjeta*>* ptrc;
public:
    Jugador(){
        id = 0;
        ptrc = NULL;
    }
    
    Jugador(int n){
        id = n;
        ptrc = NULL;
    }
    
    ~Jugador(){
        Nodo<Tarjeta*>* temp = ptrc;
        if(ptrc != NULL){
            Nodo<Tarjeta*>* temp_next = ptrc->get_next();
            while(temp_next != NULL){
                delete temp;
                temp = temp_next;
                temp_next = temp->get_next();
            }
            delete temp; //Borrar el Ãºltimo nodo
        }
    }
    
    void add(Tarjeta* c){
        Nodo<Tarjeta*>* card = new Nodo<Tarjeta*>(c);
        if(ptrc == NULL){  //lista vacía.
            ptrc = card;
        }else{  //lista vacían't.
            Nodo<Tarjeta*>* temp =  ptrc;
            while(temp->get_next() != NULL){
                temp = temp->get_next();
            }
            temp->set_next(card);
        }
    }
    
    int calc_points(){ //Recorra la lista de tarjetas y sume los números de las tarjetas
        int sum = 0;
         Nodo<Tarjeta*>* ini =  ptrc;
            while(ini->get_next() != NULL){
                sum += ini->get_valor();
                ini = ini->get_next();
            }
        return sum;
    }
    
    
    int get_id(){
        return id;
    }
    
    void sort(){
	//Ordenar las cartas de un jugador, primero por color y luego por numero
        /*for(int i = 0; i <){
            
        }*/
    }

    string to_string(){
        string s = std::to_string(id)+" -> ";
        //Recorrer la lista y concatenar en la cadena s las informaciÃ³n de las tarjetas, de acuerdo con la salida del programa
        Nodo<Tarjeta*>* temp = ptrc;
        while (temp != NULL){
            s = s+temp->get_dato()->to_string()+" , ";
            temp = temp->get_next();
        }
        if(ptrc == NULL){
            s =  s + "La lista secundaria estÃ¡ vacÃ­a uwun't. ";
        }
        return s;
    }
    
    Jugador& operator=(const Jugador& f) { 
		id = f.id;
		ptrc = f.ptrc;
		return *this;
	}
    
    void print(){
        cout<<to_string();
    }
    
    friend std::ostream& operator<<(std::ostream& os, Jugador& b) {
		return os << b.to_string();
	}
	
	friend std::ostream& operator<<(std::ostream& os, Jugador* b) {
		return os << b->to_string();
	}

};

template<typename T>
class Lista{
private:
  Nodo<T>* ptr;
  int size;

public:
    Lista(){
        ptr = NULL;
        size = 0;
    }
  
    ~Lista(){
        Nodo<T>* temp = ptr;
        if(ptr != NULL){
            Nodo<T>* temp_next = ptr->get_next();
            while(temp_next != NULL){
                delete temp;
                temp = temp_next;
                temp_next = temp->get_next();
            }
            delete temp; //Borrar el Ãºltimo nodo
        }
    }
    
    void add(T d){
        Nodo<T>* nodo = new Nodo<T>(d);
        if(ptr == NULL){//La lista estÃ¡ vacÃ­a
            ptr  = nodo;
        }else{//La lista no estÃ¡ vacÃ­a
            Nodo<T>* temp =  ptr;
            while(temp->get_next() != NULL){
                temp = temp->get_next();
            }
            temp->set_next(nodo);
        }
        size++;
    }
    
    void insert(T d, int i){
        if(i<=size && i>=0 && ptr != NULL){
            Nodo<T>* nodo = new Nodo<T>(d);
            if(i == 0){
                nodo->set_next(ptr);
                ptr = nodo;
            }else{
                int j = 0;
                Nodo<T>* temp =  ptr;
                while(j<i-1){
                    temp = temp->get_next();
                    j++;
                }
                nodo->set_next(temp->get_next());
                temp->set_next(nodo);
            }
            size++;
        }else{//Si el Ã­ndice es incorrecto o la lista estÃ¡ vacÃ­a, se aÃ±ade al final
            add(d);
        }
        
    }
    
    void print(){
        if(ptr == NULL){//La lista estÃ¡ vacÃ­a
            cout<<"La lista estÃ¡ vacÃ­a"<<endl;
        }else{//La lista no estÃ¡ vacÃ­a
            Nodo<T>* temp =  ptr;
            while(temp != NULL){
                //cout<<temp->get_dato()<<","<<temp->get_next()<<"\t";
                cout<<temp->get_dato()->to_string()<<endl;
                temp = temp->get_next();
            }
            cout<<endl;
        }
    }
    
    Nodo<T>* get(int i){
        if(i>=0 && i<size){
          int j=0;
          Nodo<T>* temp = ptr;
          while(j<i){
              temp = temp->get_next();
              j++;
          }
          return temp;
        }
        return NULL;
    }
    
    Nodo<T>* get_last(){
        Nodo<T>* temp = ptr;
        if(ptr != NULL){
            while(temp->get_next() != NULL){
                temp = temp->get_next();
            }
        }else{
            return NULL;
        }
        return temp;
    }
    
};

class Uno{
private:
    Lista<Jugador*> l;

public:
    Uno(){
        
    }
    
    ~Uno(){}
    
    void addJugador(Jugador* p){
        //AÃ±adir un jugador
    }
    
    Jugador* getJugador(int i){
        //Obtener un jugador de la lista
    }
    
    void addTarjeta(int jugador, Tarjeta* t){
        //AÃ±adir una tarjeta a un jugador
    }
    
    void sort(){
        //Implemente un mÃ©todo de ordenamiento
    }
    
    void print(){
        l.print();
    }
    
};

int main(){
    srand(1234);
    int num_jugadores = 0;
    int num_colores = 4;
    int num_tarjetas = 10;
    
    //Lea el nÃºmero de jugadores, hasta que cumpla con la condiciÃ³n
 

    int winner = rand()%num_jugadores;
    Uno u = Uno();
    
    //AÃ±ada num_jugadores jugadores a la lista
    int temp=0;
    for(int i = 0; i<num_colores; i++){
        for(int j = 0; j< num_tarjetas; j++){
            temp = rand()%num_jugadores;
            if(temp != winner){
                u.addTarjeta(temp, new Tarjeta(i,j));
            }
        }
    }
    
    cout << temp;
    
    u.print();
    
    //Muestre el puntaje de los jugadores, en orden de id

    u.sort(); //Ordena a jugadores y sus cartas internamente

    cout<<endl;

    u.print();
    
    return 0;
}
