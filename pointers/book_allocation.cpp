#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int> & arr, int n , int m, int maxAllowesPages){
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++){
        pageSum += arr[i];

        if (pageSum > maxAllowesPages){
            studentCount++;
            pageSum = arr[i];

            if (studentCount > m || arr[i] > maxAllowesPages){
                return false;
            }
        }
    }
    return true;
}