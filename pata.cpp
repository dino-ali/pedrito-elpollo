#include <iostream>

void swap(int* v, int a, int b){  //cambia los valores de una posición a otra
    int aux;
    aux=v[a];
    v[a]=v[b];
    v[b]=aux;
}

int particion(int* v, int ini, int fin){
    int pivote=v[fin]; //Ultimo elemento del vector con el que se comparan los demás elementos
    int i=ini-1;  //Marcador qe aumenta cuando encuentra un elemento menor que el pivote
    int j=ini;  //Marcador que recorre el vector
    for(j; j<fin+1; j++){
        if(v[j]<=pivote){  //Si encuentra un elemento menor que el pivote
            i++;
            int aux=v[i];
            v[i]=v[j];
            v[j]=aux;  //hace el intercambio del elemento del indice i con el elemento que este en el indice j
        }
    }
    return i;
}

void select_sort(){
        int minimo;
        int* v1  = new int(size);
        int x;
        for (int j = 0; j<size;j++){
            minimo = 1000;
            for(int i=0; i<size; i++){
                if (v[i] <= minimo ){
                    minimo = v[i];
                    x = i;
                }
            }
            v1[j] = minimo;
            v[x] = 1000;
        }
        v = v1;
        cout<<endl;        
    }     
    
    void insert_sort(){
        int aux;
        for (int i=0; i<size-1;i++){
            if(v[i+1]<v[i]){
                aux=v[i+1];
                v[i+1]=v[i];
                v[i]=aux;
                while(v[i]<v[i-1] && i>=0){
                    aux=v[i];
                    v[i]=v[i-1];
                    v[i-1]=aux;
                    i--;
                }
            }
        }
    }

void quicksort(int* v, int ini, int fin){
    if(ini>=fin){
         cout<<"";
    }else{
        int i=particion(v, ini, fin); 
        quicksort(v, ini, i-1);
        quicksort(v, i+1, fin);  //Hace la partición y despues organiza lo que queda en ambos lados
    }   
}

void heapify(int* v, int size){  //Evalua ramas del arbol binario, e intercambia su valor con los hijos si son mayores
    int mxheap, mxheap_son;
    mxheap=(size/2)-1;  //La ultima rama del arbol
    for(mxheap; mxheap>=0; mxheap--){
        if(2*(mxheap+1)<size){  //Si la rama tiene dos hojas, saca el mayor valor de entre las dos
        mxheap_son=max(v[(2*mxheap)+1], v[2*(mxheap+1)]);
        }else{
            mxheap_son=v[(2*mxheap)+1];  //Sino, el mayor valor será la hoja izquierda
        }
        if(v[mxheap]<mxheap_son){  //Si la hoja es mayor que la rama, intercambian valores
            if(mxheap_son==v[(2*mxheap)+1]){  //Si el valor es la hoja izquierda
                swap(v, mxheap, (2*mxheap)+1);
            }else{
                swap(v, mxheap, 2*(mxheap+1)); //Si el valor es la hoja derecha
            }
        }
    }
    swap(v, 0, size-1);  //Intercambia el ultimo valor con el primero
}

void heapsort(int* v, int size){  //Llama a heapify restando uno al tamaño, hasta que el tamaño sea igual a 1
    if(size==1){
        cout<<"";
    }else{
        heapify(v, size);
        heapsort(v, size-1);
    }
}

int main() {
    // Write C++ code here
    std::cout << "Hello world!";

    return 0;
}
