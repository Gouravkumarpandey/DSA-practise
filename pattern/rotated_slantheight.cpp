// ******
// ****
// ***
// **
// *


#include<bits/stdc++.h>
using namespace std;

void print(int n){
    for(int i =1;i<n;i++){
        for(int j =0;j<n;j++){
            cout<<"*";
        }
        cout<< endl;
    }
}
int main (){
    int n =5;
    print(n);
    return 0;
}