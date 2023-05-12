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



//------------------------------------------------------------------------------- ELEMENTO MINIMO

#include<iostream>

using namespace std;

int min(int* v) {
	int min = v[0];
	for (size_t i = 1; i < (sizeof v - 1); i++)
	{
		if (v[i] < min) {
			min = v[i];
		}
	}

	return min;
}

int min2(int* v, int k, int min) {
	if (k >= (sizeof v - 1)){
		return min;
	}
	else{
		
		if (v[k] < min) {
			min = v[k];
		}
		min2(v, k+1, min);
	}
}

int main()
{
    int vector[] = {5,45,6,2,8,63,1};
    
	cout << min2(vector,0,100);
    
    
    return 0;
}

