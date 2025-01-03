class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& can, int index, int target, vector<int>& ans) {

        if (target == 0) {
            result.push_back(ans);
            return;
        }

        if (index >= can.size() || target < 0) {
            return;
        }

        ans.push_back(can[index]);
        solve(can, index, target - can[index], ans);
        ans.pop_back();

        solve(can, index + 1, target, ans);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        solve(candidates, 0, target, ans);
        return result;
    }
};