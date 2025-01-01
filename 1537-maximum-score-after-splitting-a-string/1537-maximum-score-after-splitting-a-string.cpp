class Solution {
public:
    int maxScore(string s) {
        map<int, pair<int, int>> mp;

        int zero = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '0') zero ++;

            mp[i].first = zero; 
        }

        int one = 0;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i] == '1') one++;

            mp[i].second = one;
        }

        int maxi = 0;
        for(int i=0; i<s.length()-1; i++){
            int one = i<s.length()-1 ? mp[i+1].second : 0;
            int zero = mp[i].first;
            cout<<one <<" "<<zero<<endl;

            maxi = max(maxi, one+zero);
        }

        return maxi;
    }
};