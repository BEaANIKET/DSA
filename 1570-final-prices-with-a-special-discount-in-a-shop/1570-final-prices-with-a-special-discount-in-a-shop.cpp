class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        
        vector<int>ans ;
        for(int i=0; i<p.size(); i++){
            int cp = p[i];
            int d = 0;
            for(int j=i+1; j<p.size(); j++){
                if(p[j] <= cp){
                    d=p[j];
                    break;
                }
            }
            ans.push_back(cp - d);
        } 

        return ans;
    }
};