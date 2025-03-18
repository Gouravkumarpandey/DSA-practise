#include <iostream>
using namespace std;

// Function to calculate the sum of digits of a number
int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Function to find and print weird numbers in the array
void findWeirdNumbers(int arr[], int n, int k) {
    cout << "Weird Numbers: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] % k != 0 && sumOfDigits(arr[i]) % k == 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int arr[] = {20, 25, 36, 49, 58, 63};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;  // Example value of K

    findWeirdNumbers(arr, n, k);

    return 0;
}
