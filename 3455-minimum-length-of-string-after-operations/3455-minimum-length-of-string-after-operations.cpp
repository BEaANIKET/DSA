class Solution {
public:
    int minimumLength(string s) {
        
        map<char,int>mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]] ++;

            if(mp[s[i]] >= 3){
                mp[s[i]] = 1;
            }
        }


        int ans = 0;
        for(auto & a : mp){
            ans += a.second;
        }

        return ans ;
    }
};