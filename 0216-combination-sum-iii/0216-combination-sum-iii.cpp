class Solution {
public:
    typedef vector<int> vint;
    vector<vector<int>> result;

    void solve(int n, int index, vint& temp, int k) {

        if (n == 0 && k == 0) {
            result.push_back(temp);
        }

        if (index > 9 || n < 0) {
            return;
        }

        for (int i = index; i <= 9; i++) {
            if (i > n) {
                break;
            }
            temp.push_back(i);
            solve(n - i, i+1, temp, k - 1);
            temp.pop_back();
        }
        
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vint temp;
        solve(n, 1, temp, k);
        return result;
    }
};