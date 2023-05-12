#include<iostream>
#include<string>
using namespace std;

template <typename T, typename T2>
class Tupla{
    T key;
    T2 dato;

public:
    Tupla(T k, T2 d) {
        key = k;
        dato = d;
    }

    Tupla(){
    }
    
    void setKey(T k){
        key = k;
    }
    
    void setDato(T2 d){
        dato = d;
    }
    
    T getKey(){
        return key;
    }
    
    T2 getDato(){
        return dato;
    }
    
    Tupla& operator=(const Tupla& f) { 
		setKey(f.key);
		setDato(f.dato);
		return *this; 
	}
};

template <typename T, typename T2>
class Mapa{
private:
    int size;
    int capacity;
    Tupla<T, T2>* v;

public:
    Mapa(){
        size = 0;
        capacity = 10;
        v = new Tupla<T, T2>[capacity];
    }

     bool Haskey(Tupla<T, T2> t){
        for(int i = 0; i<size; i++){
            if (v[i].getKey() == t.getKey()){
                return true;
            }
        }
        return false;
    }
    
    void corrimiento_der(int i){
        for(int j = size; j>i; j--){
            v[j] = v[j-1];
        }
    }
    
    void push(Tupla<T, T2> t){
        if(Haskey(t) == false){
            if (size >= capacity){  ////si esta lleno, crea un nuevo vector, pasa los valores e inserta 
                capacity*=2;
                Tupla<T, T2>* v1 = new Tupla<T, T2>[capacity];
                for (int i = 0; i < size; i++){
                    v1[i] = v[i];
                }
                delete[] v; //Borra el vector antiguo
                v = v1;
            }
            if(size==0){
                v[size] = t;
                size++;
            }else{
                int flag = 0;
                for(int i = 0; i<size; i++){
                    if(t.getKey()<v[i].getKey()){
                        corrimiento_der(i);
                        v[i] = t;
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    v[size] = t;
                }
                size++;
            }  
        }else{
            cout<<"Llave repetida"<<endl;
        }
    }

    T2 find(T key){
        int left = 0;
        int right = size-1;
        while(left <= right){
            int mid = (right+left)/2;;
            if(v[mid].getKey() == key){
                return v[mid].getDato();
            }
            else{
                if(v[mid].getKey()>key){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }    
        }
        return NULL;
    }
    
    void print() {
        for (int i = 0; i <size; i++) {
            cout << "(" << v[i].getKey() << ", " << v[i].getDato() << ")" << "\t";
        }
        cout<<endl;
    }
};

int main(){
    Tupla<string, int> p1 = Tupla<string, int>("A", 0);
    Tupla<string, int> p2 = Tupla<string, int>("D", 3);
    Tupla<string, int> p3 = Tupla<string, int>("C", 2);
    Tupla<string, int> p4 = Tupla<string, int>("B", 1);
    Mapa<string, int> p = Mapa<string, int>();
    p.push(p1);
    p.push(p2);
    p.push(p3);
    p.push(p4);
    p.print();
    cout<<p.find("B")<<endl;
}
