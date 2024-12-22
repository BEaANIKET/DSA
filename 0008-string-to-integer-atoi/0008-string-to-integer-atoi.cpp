class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long long ans = 0;

        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            int num = s[i] - '0';
            ans = ans * 10 + num;

            if (ans * sign > INT_MAX) {
                return INT_MAX;
            }
            if (ans * sign < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }

        return ans * sign;
    }
};
