#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);  // Read number of test cases

    while (t--) {
        int n;
        scanf("%d", &n);  // Read number of coffee machines

        long long a[n + 2];  // Array to store the number of students around coffee machines
        a[0] = a[n + 1] = 0; // Set the boundary conditions to 0 (as these rooms are not involved)
        
        // Read the number of students for coffee machines numbered from 1 to n
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }

        long long max_students = 0;

        // For each coffee machine, calculate the maximum number of students that can be gathered
        for (int i = 1; i <= n; i++) {
            long long gathered = a[i] + (a[i-1] / 2) + (a[i+1] / 2);
            if (gathered > max_students) {
                max_students = gathered;  // Update max_students if we find a higher value
            }
        }

        printf("%lld\n", max_students);  // Output the result for the current test case
    }

    return 0;
}
