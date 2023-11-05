#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cout << "Enter your first number : ";
    cin >> a;
    int b;
    cout << "Enter your second number : ";
    cin >> b;
    if (a>b){
        cout<< a << " greater than " << b;
    }
    else if (a==b)
    {
        cout <<a <<" equals "<<b;
    }
    
    else
        cout <<  b << " greater than " << a << endl; 
    return 0;
}