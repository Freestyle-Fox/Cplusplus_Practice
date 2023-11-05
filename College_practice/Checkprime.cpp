#include <bits/stdc++.h>
using namespace std;

// checkin the prime number by deviding the number with all the number till that number

int main(){
    int a;
    cout <<"Enter the number to check ,wheather it is prime or not ? :  ";
    cin >> a;
    for (int i=2; i<a; i++){
        int s = a % i;
        if (s==0){
            cout << a << " is not a Prime Number";
            break;
        }
    else{
        cout << a << " is a Prime Number";
    }
        
    }
    
    return 0;
}