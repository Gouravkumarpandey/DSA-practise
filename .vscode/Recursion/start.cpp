#include<iostream>
using namespace std;


int sum(int n){
    if(n==1){
        return 1;
    }
   
    

    return n+ sum (n-1);
}
int main(){
    int n ;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    
    cout<<sum(n)<<endl;
    return 0;
}