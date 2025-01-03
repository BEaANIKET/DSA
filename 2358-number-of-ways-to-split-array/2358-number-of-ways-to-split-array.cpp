class Solution {
public:

    typedef long long ll;
    int waysToSplitArray(vector<int>& nums) {

        int n = nums.size();
        vector<ll>pre(n, 0);
        vector<ll >suf(n, 0);

        pre[0] = nums[0];
        suf[n-1] = nums[n-1];

        for(int i=1; i<nums.size(); i++){
            pre[i] = 1ll * nums[i] + pre[i-1];
        }

        for(int i=nums.size()-2; i>=0; i--){
            suf[i] = 1ll * nums[i] + suf[i+1];
        }

        int count = 0;
        for(int i=0; i<n-1; i++){
            if(pre[i] >= suf[i+1]){
                count ++;
            }
        }

        return count;
    }
};