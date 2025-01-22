#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MOD 998244353
using namespace std;

const int MAXN = 5000;
long long fact[2*MAXN+1], inv_fact[2*MAXN+1];

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i <= 2 * MAXN; ++i) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    inv_fact[2 * MAXN] = mod_exp(fact[2 * MAXN], MOD - 2, MOD);
    for (int i = 2 * MAXN - 1; i >= 0; --i) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

long long catalan_number(int n) {
    return (fact[2 * n] * inv_fact[n] % MOD) * inv_fact[n + 1] % MOD;
}

int main() {
    precompute_factorials();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<pair<int, int>> clues(n);
        for (int i = 0; i < n; ++i) {
            cin >> clues[i].first >> clues[i].second;
            --clues[i].first;
            --clues[i].second;
        }

        vector<long long> dp(2 * n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= 2 * n; ++i) {
            for (int j = 0; j <= i; ++j) {
                dp[i] = (dp[i] + dp[i - 1]) % MOD;
            }
        }

        cout << dp[2 * n] << " ";

        for (auto& clue : clues) {
            int l = clue.first, r = clue.second;

            vector<long long> new_dp(2 * n + 1, 0);
            for (int i = 0; i < 2 * n; ++i) {
                if (dp[i] > 0) {
                    new_dp[i + 1] = (new_dp[i + 1] + dp[i]) % MOD;
                }
            }

            dp = new_dp;
            cout << dp[2 * n] << " ";
        }

        cout << endl;
    }

    return 0;
}
