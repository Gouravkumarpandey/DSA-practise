
// Find the Longest Subsequence from the given array whose sum of consecutive
//  elements in array is divisible by K given to us ?



#include <bits/stdc++.h>
using namespace std;

int longestSubsequenceDivByK(vector<int>& arr, int K) {
    unordered_map<int, int> remainderIndex; // Stores remainder -> first index
    remainderIndex[0] = -1; // Initialize for case when whole prefix sum is divisible by K
    int prefixSum = 0, maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];
        int remainder = ((prefixSum % K) + K) % K; // Ensure positive remainder

        if (remainderIndex.find(remainder) != remainderIndex.end()) {
            maxLen = max(maxLen, i - remainderIndex[remainder]);
        } else {
            remainderIndex[remainder] = i; // Store first occurrence of remainder
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {2, 7, 6, 1, 4, 5}; 
    int K = 3;

    int result = longestSubsequenceDivByK(arr, K);
    cout << "Longest subsequence length: " << result << endl;

    return 0;
}
