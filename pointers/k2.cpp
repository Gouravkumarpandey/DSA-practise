#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findWeirdNumbers(vector<int>& nums, int k) {
        vector<int> result;
        for (int num : nums) {
            if (num % k != 0 && sumOfDigits(num) % k == 0) {
                result.push_back(num);
            }
        }
        return result;
    }

private:
    int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};

// Driver code for testing
int main() {
    Solution sol;
    vector<int> nums = {20, 25, 36, 49, 58, 63};
    int k = 5;
    
    vector<int> weirdNumbers = sol.findWeirdNumbers(nums, k);
    
    cout << "Weird Numbers: ";
    for (int num : weirdNumbers) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
