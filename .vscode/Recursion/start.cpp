#include<iostream>
using namespace std;

int fibonaci(int n){
    if (n==1||n==0){
        return n;
    }

    return fibonaci(n-1)+fibonaci(n-2);
}

int main(){
    
    cout<< fibonaci(5)<<endl;
    return 0;

}