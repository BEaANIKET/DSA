class Solution {
public:
    vector<int> minOperations(string boxes) {
        map<int, vector<int>>mp;

        for(int i=0; i<boxes.size(); i++){
            if(boxes[i] == '1'){
                mp[1].push_back(i);
            }
        }

        vector<int>ans(boxes.size(), 0);
        for(int i=0; i<boxes.size(); i++){
            int count = 0;
            for(auto &v : mp[1]){
                count += abs(v - i);
            }

            ans[i] = count;
        }

          return ans;
    }
};