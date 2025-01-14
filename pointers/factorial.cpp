#include <bits/stdc++.h>
using namespace std;

int main (){
    int n ;
    long factorial = 1.0;
cout<<"enter the number :";
cin >> n;
if(n<0)
cout<< "erorr factorial numbers:";
{

else{
    for(int i=1;i<=n;i++){
    factorial *=i;
    }
    cout<< "factorial of "<< n << " = " << factorial;
    return 0;
}
}



}