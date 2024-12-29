class Solution {
public:
    int minimumOperations(vector<vector<int>>& nums) {
        int ans = 0;

        for (int j = 0; j < nums[0].size(); j++) { 
            int prev = nums[0][j]; 
            for (int i = 1; i < nums.size(); i++) {
                
                if (nums[i][j] <= prev) { 
                    ans += (prev - nums[i][j] + 1);
                    prev++;
                } else {
                    prev = nums[i][j]; 
                }
            }
        }

        return ans;
    }
};
