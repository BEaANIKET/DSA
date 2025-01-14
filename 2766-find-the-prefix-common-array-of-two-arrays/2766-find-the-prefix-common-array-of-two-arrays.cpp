class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int, bool> v;
        int n = A.size();

        vector<int>ans;
        for(int i=0; i<n; i++){
            v[A[i]] = true;
            v[B[i]] = true;

            int val = ((i+1) * 2 ) - v.size();
            ans.push_back(val);
        }
        
        return ans ;
    }
};