#include<iostream>
using namespace std;

class Set{
    int size;
    int capacity;
    int *v;

public:
    Set(int capacity1) {
        capacity = capacity1;
        size = 0;
        v = new int[capacity];
    }
    
    int get_size(){
        return size;
    }
    
    bool contains(int x){
        for(int i = 0; i<size; i++){
            if (x == v[i]){
                return true;
            }
        }
        return false;
    }
    
    bool empty(){
        if(size == 0){
            return true;
        }else{
            return false;
        }
    }
    void increase_capacity(){
        capacity*=2;
        int *v1 = new int[capacity];
        for (int i = 0; i < size; i++) {
            v1[i] = v[i];
        }
        delete[] v; //Borra el vector antiguo
        v = v1;
    }
    
    void corrimiento_der(int i){
        for(int j = size; j>i; j--){
            v[j] = v[j-1];
        }
    }
    
    void push(int x){
        if(contains(x) == false){
            if(size >= capacity){  ////si esta lleno, crea un nuevo vector, pasa los valores e inserta 
                increase_capacity();
            }
            if(size==0){
                v[size] = x;
                size++;
            }else{
                int flag = 0;
                for(int i = 0; i<size; i++){
                    if(x<v[i]){
                        corrimiento_der(i);
                        v[i] = x;
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    v[size] = x;
                }
                size++;
            }  
        }
    }

    Set unionn(Set c){
        int size_u = size+c.get_size();
        Set u = Set(size_u);
        for(int i = 0; i<size; i++){
            u.push(v[i]);
        }
        for(int i = 0; i<c.get_size(); i++){
            u.push(c.v[i]);
        }
        return u; 
    }
    
    Set interseccion(Set c){
        int n_cap;
        n_cap = min(size, c.get_size());
        Set n = Set(n_cap);
        if(n_cap == size){
            for(int i = 0; i<n_cap; i++){
                if(c.contains(v[i])){
                    n.push(v[i]);
                }    
            }
        }else{
            for(int i = 0; i<n_cap; i++){
                if(contains(c.v[i])){
                    n.push(c.v[i]);
                }    
            }
        }
        return n;
    }
    
    Set A_B(Set c){
        int A_B_cap;
        Set I = interseccion(c);
        A_B_cap = size-I.get_size();
        Set A_B = Set(A_B_cap);
        for(int i = 0; i<size; i++){
            if(i<I.get_size()){
                if(not I.contains(v[i])){
                    A_B.push(v[i]);
                }
            }else{
                A_B.push(v[i]);
            }
        }
        return A_B;
    }
    
    void print() {
        for (int i = 0; i <size; i++) {
            cout << v[i] << "\t";
        }
        cout<<endl;
    }
    
    Set& operator=(const Set& s) { 
        capacity = s.capacity;
        size = s.size;
        for(int i = 0; i<size; i++){
            v[i] = s.v[i];
        }
		return *this; 
	}
};
int main(){
    Set prueba = Set(10);
    Set un = Set(10);
    prueba.push(6);
    prueba.push(5);
    prueba.push(4);
    un.push(4);
    un.push(9);
    un.push(8);
    un.push(7);
    
    cout<<"La union de el conjunto A: "<<endl;
    prueba.print();
    cout<<"y el conjunto B: "<<endl;
    un.print();
    cout<<"es: "<<endl;
    prueba.unionn(un).print();
    cout<<"------------------------------------------"<<endl;
    cout<<"Y la interseccion es: "<<endl;
    prueba.interseccion(un).print();
     cout<<"------------------------------------------"<<endl;
    cout<<"Y A-B es: "<<endl;
    prueba.A_B(un).print();
    
    return 0;
}
