#include <iostream>
using namespace std;

int fact(int n){
    if(n <= 1){
        return 1;
    }else{
        return fact(n-1)*n;
    }
}

int fibo (int n){
    if (n <= 1){
        return 1;
    }else{
        return fibo(n-1) + fibo(n-2);
    }
}

int main() {
    cout << "factorial: " << fact(3) << endl;
    cout << "fibonacci: " << fibo(5) << endl;

    return 0;
}
