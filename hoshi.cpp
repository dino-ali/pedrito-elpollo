#include<iostream>
using namespace std;

void hoshi(){
    string s; 
    cout<<"Escriba algo: ";
    cin >> s;
    cout<< endl;
    int c = 1 ; 
    for( int i = 0; i < s.length(); i++){
         c = (c*s[i])%1000000;
         cout<<c<<endl;
    }
    cout << "El valor es: " << c << endl;
}

int main(){
    hoshi();
    
    return 0;
}
