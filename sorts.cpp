#include <iostream>
#include <vector>
using namespace std;

void select_sort(vector<int> &a){

}

void insert_sort(vector<int> &a){
    for(int i = 0; i < a.size()-1; i++){
        
    }
}

void quick_sort(vector<int> &a){
    for(int i = 0; i < a.size()-1; i++){
        
    }
}

void bubble_sort(vector<int> &a){
    for(int j =0; j < a.size()-1; j++){
        for(int i = 0; i < (a.size()-1)-j; i++){
            if(a[i] > a[i+1]){
                int pata = a[i];
                a[i] = a[i+1];
                a[i+1] = pata;
            }
        }
    }
}

void shell_sort(vector<int> &a){
    for(int gap = a.size()/2; gap > 0; gap /= 2){
        for(int i = gap; i < a.size(); i++){
            int temp = std::move(a[i]);
            int j = i;
            for(;j >= gap && temp > a[j - gap]; j -= gap){
                a[j] = std::move(a[j - gap]);
            }
            a[j] = std::move(temp);
        }
    }
}

void max_heap(int* v, int n, int i){
    int greatest = i;
    int parent = (i - 1) / 2;
    int 
    if(izq(i) < n )
}

void heap_sort(int* v)
int main() {

    return 0;
}
void print_vec(vector<int>& a){
  for(int i = 0; i < a.size(); ++i)
    cout << a[i] << " ";
  cout << "\n";
}

int main() {
    vector<int> yoongi;
    yoongi.push_back(5);
    print_vec(yoongi);
    return 0;
}
