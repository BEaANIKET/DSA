class Solution {
public:
    int maxProfit(vector<int>& prices) {

        map<int, int> mp;
        int maxi = -1;
        for(int i=prices.size()-1; i>=0; i--){
            mp[i] = maxi;
            maxi = max(maxi, prices[i]);
        }
        maxi = INT_MIN;
        for(int i=0; i<prices.size(); i++){
           int profit = mp[i] - prices[i] ;
           maxi = max(maxi, profit);
        }

        return maxi <= 0 ? 0 : maxi ;
    }
};