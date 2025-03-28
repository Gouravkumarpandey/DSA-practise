#include<bits/stdc++.h>
using namespace std;

void page_allocated(int n ,int m ,int arr[], int book_allocated){
    int sum =0;

    for (int i =0;i<n;i++){
        sum+= arr[i]; 

        if(sum > book_allocated){
            cout<<"Book allocated to student" << i<< is "<< arr[i]<< endl";
        }

        else{
            if (sum == book_allocated){
                cout<<"Book allocated to student" << i<< is "<< arr[i]<< endl";
            }

            
        }
}