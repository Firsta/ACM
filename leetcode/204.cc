class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        bool *is_prime = new bool[n];
        for (int i = 0; i < n; i++)
            is_prime[i] = true;
        for (int i = 2; i < n; i++)
            if (is_prime[i]) {
                ans++;
                for (int j = i * 2; j < n; j += i)
                    is_prime[j] = false;
            }
        return ans;
    }
};
