class Solution {
public:
    const int mod = 1e9 + 7;
    
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    void facto(vector<long long>& fact, long long n) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
    }

    long long nCr(vector<long long>& fact, long long n, long long r) {
        if (r > n) {
            return 0;
        }
        long long res = fact[n];
        long long inv_r = modPow(fact[r], mod - 2, mod); // Finding modular inverse
        long long inv_nr = modPow(fact[n - r], mod - 2, mod); // Finding modular inverse

        res = (res * inv_r) % mod;
        res = (res * inv_nr) % mod;

        return res;
    }

    long long solver(vector<long long>& fact, vector<int> nums) {
        long long n = nums.size();
        if (n <= 2) {
            return 1;
        }
        long long first = nums[0];
        vector<int> left;
        vector<int> right;
        for (int i = 1; i < n; i++) {
            if (nums[i] < first) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }
        long long leftpart = solver(fact, left) % mod;
        long long rightpart = solver(fact, right) % mod;

        return nCr(fact, n - 1, left.size()) % mod * leftpart % mod * rightpart % mod;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<long long> fact(n + 1, 0);
        facto(fact, n);
        return (solver(fact, nums) - 1 + mod) % mod;
    }
};
