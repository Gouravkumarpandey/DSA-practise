
#include<bits/stdc++.h>
using namespace std;

int main (){
int a= 10;
int* ptr =&a;

int** parentPtr = & ptr;
    

    cout<< *(&a) << endl;
     cout<< *(ptr) << endl;
     
     cout<< (ptr) << endl;
    return 0;

}



