#include <bits/stdc++.h>
using namespace std;

int calculate(int r, int unit, int n, int arr[]) {
    if (n == 0) {
        return -1;
    }

    int totalFoodRequired = r * unit;
    int foodTillNow = 0;

    for (int i = 0; i < n; i++) {
        foodTillNow += arr[i];
        if (foodTillNow >= totalFoodRequired) {
            return i + 1;
        }
    }
    return 0;  // If food is insufficient
}

int main() {
    int r, unit, n;
    
    cout << "Enter the number of rats: ";
    cin >> r;
    
    cout << "Enter the number of units of food each rat needs: ";
    cin >> unit;
    
    cout << "Enter the number of houses: ";
    cin >> n;

    int arr[n];
    cout << "Enter the food available at each house: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = calculate(r, unit, n, arr);
    cout << "Minimum number of houses required: " << result << endl;

    return 0;
}
