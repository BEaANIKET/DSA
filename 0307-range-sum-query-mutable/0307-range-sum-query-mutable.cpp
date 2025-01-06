class NumArray {
public:
    vector<int> v;
    vector<int> prefixSum;

    NumArray(vector<int>& nums) {
        v = nums;
        prefixSum = vector<int>(v.size(), 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
    }
    
    void update(int index, int val) {
        int diff = val - v[index];
        v[index] = val;
        for (int i = index; i < prefixSum.size(); i++) {
            prefixSum[i] += diff;
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) {
            return prefixSum[right];
        }
        return prefixSum[right] - prefixSum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */