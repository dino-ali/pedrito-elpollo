#include <cstdlib>
#include <ctime>
#include <iostream>
#include <math.h>
using namespace std;

// Genera un decimal entre el rango del minimo y maximo
double generarDec(double min, double max) {
    return min + static_cast<double>(rand()) / (RAND_MAX / (max - min));
}

// A partir de un string que viene en base binaria retorna lo que seria pero en base 32
string bin2b32(string s) {
    int caso = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[s.length() - i - 1] == 49) {
            caso += pow(2, i);
        }
    }
    switch (caso) {
        case 0:
            return "0";
        case 1:
            return "1";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        case 10:
            return "b";
        case 11:
            return "c";
        case 12:
            return "d";
        case 13:
            return "e";
        case 14:
            return "f";
        case 15:
            return "g";
        case 16:
            return "h";
        case 17:
            return "j";
        case 18:
            return "k";
        case 19:
            return "m";
        case 20:
            return "n";
        case 21:
            return "p";
        case 22:
            return "q";
        case 23:
            return "r";
        case 24:
            return "s";
        case 25:
            return "t";
        case 26:
            return "u";
        case 27:
            return "v";
        case 28:
            return "w";
        case 29:
            return "x";
        case 30:
            return "y";
        case 31:
            return "z";
        default:
            return " ";
    }
}

// Genera el geoHash recibiendo las coordenadas de la ubicacion dentro del mapa.
string GeoHash(double latitud, double longitud, int digitos) {
    double lai = -90, laf = 90, loi = -180, lof = 180;
    string temp = "";
    string s = "";
    for (int i = 0; i < (digitos * 5 + 1)/2; i++) {
        if (longitud < (loi + lof) / 2) {
            temp += "0";
            lof = (loi + lof) / 2;
        } else {
            temp += "1";
            loi = (loi + lof) / 2;
        }

        if (temp.length() == 5) {
            s += bin2b32(temp);
            temp = "";
        }

        if (latitud < (lai + laf) / 2) {
            temp += "0";
            laf = (lai + laf) / 2;
        } else {
            temp += "1";
            lai = (lai + laf) / 2;
        }

        if (temp.length() == 5) {
            s += bin2b32(temp);
            temp = "";
        }
    }
    return s;
}

template <typename T>
class Nodo {
    private:
    T dato;
    Nodo *next;

    public:
    Nodo(T d) {
        dato = d;
        next = NULL;
    }

    ~Nodo() {}

    T get_dato() {return dato;}
    void set_dato(T d) {dato = d;}
    Nodo* get_next() {return next;}
    void set_next(Nodo* n) {next = n;}
};

template <typename T> 
class Lista {
    private:
    Nodo<T> *ptr;
    int size;

    public:
    Lista() {
        ptr = NULL;
        size = 0;
    }

    int get_size() { return size; }

    ~Lista() {
        Nodo<T> *temp = ptr;
        if (ptr != NULL) {
            Nodo<T> *temp_next = ptr->get_next();
            while (temp_next != NULL) {
                delete temp;
                temp = temp_next;
                temp_next = temp->get_next();
            }
            delete temp; // Borrar el último nodo
        }
    }

    Nodo<T> *get_nodo(int i) {
        Nodo<T> *temp = ptr;
        while (i > 0) {
            temp = temp->get_next();
            i--;
        }
        return temp;
    }

    void add(T d) {
        Nodo<T> *nodo = new Nodo<T>(d);

        if (ptr == NULL) { // La lista está vacía
            ptr = nodo;
        } else { // La lista no está vacía
            Nodo<T> *temp = ptr;
            while (temp->get_next() != NULL) {
                temp = temp->get_next();
            }
            temp->set_next(nodo);
        }
        size++;
    }

    void insert(T d, int i) {
        if (ptr == NULL or i >= size) {
            add(d);
        } else if (i < size && ptr != NULL) {
            Nodo<T> *temp = get_nodo(i - 1);
            Nodo<T> *nodo = new Nodo<T>(d);
            if (i == 0) {
                ptr = nodo;
                nodo->set_next(temp);
            } else {
                nodo->set_next(temp->get_next());
                temp->set_next(nodo);
            }
        size++;
        }
    }

    void print() {
        if (ptr == NULL) { // La lista está vacía
            cout << "La lista está vacía" << endl;
        } else { // La lista no está vacía
            Nodo<T> *temp = ptr;
            while (temp != NULL) {
                cout << temp->get_dato()->get_hash() << "\t";
                temp = temp->get_next();
            }
            cout << endl;
        }
    }
};

class Coordenada {
    private:
    double x, y;

    public:
    Coordenada() {
        x = 0;
        y = 0;
    }
    Coordenada(double a, double b) {
        x = a;
        y = b;
    }

    double get_x() { return x; }
    double get_y() { return y; }

    string to_string() {
        string s = "Coordena: (" + std::to_string(x) + ", " + std::to_string(y) + ")";
        return s;
    }

    friend std::ostream &operator<<(std::ostream &os, Coordenada &p) {
        return os << "Coordenada: (" << p.get_x() << ", " << p.get_y() << ")";
    }
};

class Nodo_a {
    // clase nodo_a para construir el Arbol
    private:
    string hash;                // variable donde se guarda el GeoHash
    Lista<Coordenada>* coord;   // Lista donde guaradaremos las coordenadas
    Lista<Nodo_a*>* hijos;      // Lista donde guardamos los hijos del nodo_a

    public:
    Nodo_a(string geo) {        // constructor del Arbol
        coord = new Lista<Coordenada>;
        hash = geo;
        hijos = new Lista<Nodo_a *>;
    }

    void add_coord(Coordenada c){   // metodo para añadir Coordenadas
        coord->add(c);
    }

    void add_hijo(Nodo_a* h){       // metodo que añade un hijo
        if (hijos->get_size() == 0) {   // si no tiene hijos, lo añade directamente
            hijos->add(h);
        } else {                        // añade hijo de forma ordenada
            int i = 1;
            Nodo<Nodo_a*>* hijo = hijos->get_nodo(0);
            while (hijo->get_next() != NULL && hijo->get_dato()->get_hash() < h->get_hash()) {
                hijo = hijo->get_next();
            }
            if (hijo->get_next() == NULL) {
                hijos->add(h);
            } else {
                Nodo<Nodo_a*>* temp = hijo->get_next();
                Nodo<Nodo_a*>* nuevo = new Nodo<Nodo_a*>(h);
                hijo->set_next(nuevo);
                nuevo->set_next(temp);
            }
        }
    }

    Nodo_a* get_hijo(string h) {        // metodo que retorna un nodo Arbol
        if (hijos->get_size() == 0) {
            return NULL;
        } else {
            Nodo<Nodo_a*>* hijo = hijos->get_nodo(0);
            while (hijo != NULL) {
                if (hijo->get_dato()->get_hash() == h) {    // si tiene el mismo hash lo retorna
                    return hijo->get_dato();
                }
                hijo = hijo->get_next();
            }
            return NULL;                // si termino el while, no existe el hijo
        }
    }
    
    void print() {                      // metodo que imprime el nodo Arbol
        if (coord->get_size() == 0) {
            cout << "No hay coordenadas con el GeoHash: " << hash << endl;
        } else {
            Nodo<Coordenada>* nodo = coord->get_nodo(0);
            while (nodo != NULL) {
                cout << "GeoHash: " << hash << "\t" << nodo->get_dato().to_string() << endl;
                nodo = nodo->get_next();
            }
        }
    }

    string get_hash() { return hash; }                  // retorna el GeoHash
    Lista<Coordenada> *get_coord() { return coord; }    // retorna las coordenadas
    Lista<Nodo_a *> *get_hijos() { return hijos; }      // retorna los hijos
};

class Arbol {
    private:
    Nodo_a *raiz;
    int digitos;        // variable que determina el numero de digitos en el GeoHash

    public:
    Arbol(int n) {      // constructor del Arbol
        raiz = new Nodo_a("");
        digitos = n;
    }

    void add(Coordenada c) {    // metodo de apoyo para añadir una nueva Coordenada
        string g = GeoHash(c.get_x(), c.get_y(), digitos);
        add(c, raiz, g, 0);
    }

    void add(Coordenada c, Nodo_a* nodo, string g, int i) { // metodo que añade la Coordenada
        string s;
        s = g[i];
        Nodo_a* hijo = nodo->get_hijo(s);
        if (hijo == NULL) { // si el hijo no existe, crea el camino
            if (i == digitos-1) {
                Nodo_a* nuevo_hijo = new Nodo_a(g);
                nuevo_hijo->add_coord(c);
                nodo->add_hijo(nuevo_hijo);
            } else {
                Nodo_a* nuevo_hijo = new Nodo_a(s);
                nodo->add_hijo(nuevo_hijo);
                add(c, nuevo_hijo, g, i+1);
            }
        } else { // si el camino ya existe, avanzar por ese camino
            if (i == digitos-1) {hijo->add_coord(c);}
            else {add(c, hijo, g, i+1);}
        }
    }

    // metodo para buscar las coordenadas que comparte un prefijo (coordenadas cercanas)
    Nodo_a* busqueda(string g) {return busqueda(g, raiz, 0);}
    Nodo_a* busqueda(string g, Nodo_a* nodo, int i) {
        if (g.length() > digitos) { // no se puede tener un prefijo mas grande que los GeoHash
            cout << "el prefijo es demasiado grande.";
            return NULL;
        } else { // si el prefijo tiene el tamaño adecuado
            string s;
            s = g[i];
            Nodo_a* hijo = nodo->get_hijo(s);
            if (hijo == NULL) {
                cout << "no existe coordenadas con este prefijo.";
                return NULL;
            } else { // si existe el hijo
                if (i == g.length()-1) { // si el nodo concuerda con el GeoHash retorna el nodo
                    return hijo;
                } else { // siga buscando un nodo que comparta el GeoHash
                    return busqueda(g, hijo, i+1);
                }
            }
        }
    }
    
    void print() {print(raiz);}
    
    void print(string prefijo) {
        Nodo_a* nodo = busqueda(prefijo);
        if (nodo != NULL) {
            print(nodo);
        }
    }
    // metodos prints para imprimir el arbol desde cualquier nodo, o a partir de un prefijo
    void print(Nodo_a* nodo) {
        Lista<Nodo_a*>* hijos = nodo->get_hijos();
        if (hijos->get_size() == 0) {
            nodo->print();
        } else {
            Nodo<Nodo_a*>* hijo = hijos->get_nodo(0);
            while (hijo != NULL) {
                print(hijo->get_dato());
                hijo = hijo->get_next();
            }
        }
    }
};

int main() {
    int num_coor = 5;
    int num_digitos = 10;
    double min_lat = 4.48678121;
    double max_lat = 4.78798027;
    double min_lon = -74.00439955;
    double max_lon = -74.24726596;
    string prefijo = "d2g6";
    
    
    Arbol mundo = Arbol(num_digitos);
    double lat;
    double lon;
    for (int i = 0; i < num_coor; i++) {
        lat = generarDec(min_lat, max_lat);
        lon = generarDec(min_lon, max_lon);
        Coordenada c = Coordenada(lat, lon);
        mundo.add(c);
    }
    
    cout << "completo: " << endl;
    mundo.print();
    cout << endl;
    cout << "Coordenadas cercanas:" << endl;
    mundo.print(prefijo);

    return 0;
}
