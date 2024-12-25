#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < s.length(); j++) {
                freq[s[j] - 'a']++;

                int maxi = 0, mini = INT_MAX;
                for (int f : freq) {
                    if (f > 0) {
                        maxi = max(maxi, f);
                        mini = min(mini, f);
                    }
                }

                ans += (maxi - mini);
            }
        }

        return ans;
    }
};
