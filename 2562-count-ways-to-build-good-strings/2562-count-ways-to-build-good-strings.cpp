class Solution {
public:
    #define MOD 1000000007

    int solve(int l, int h, int z, int o, int s, vector<int>& dp) {
        if (s > h) return 0;

        if (dp[s] != -1) return dp[s];

        int count = (s >= l) ? 1 : 0;

        count = (count + solve(l, h, z, o, s + z, dp)) % MOD;
        count = (count + solve(l, h, z, o, s + o, dp)) % MOD;

        return dp[s] = count;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return solve(low, high, zero, one, 0, dp);
    }
};
