class Solution {
public:

    int solve(vector<int>&nums, int target, int index){
        if(index>=nums.size()){
            if(target == 0){
                return 1;
            }
            return 0;
        }

        int sum = solve(nums, target+nums[index], index+1);
        int minus = solve(nums, target-nums[index], index+1);

        return sum+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0); 
    }
};