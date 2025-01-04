class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char, int>mp;
        map<char, bool> vis;
        int n = s.length();

        for(int i=n-1; i>=0; i--){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = i;
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            if(!vis[s[i]] &&  mp[s[i]] > i ){
                int diff = 0;
                map<char, int>d;
                for(int j=i+1; j<mp[s[i]]; j++){
                    if(d.find(s[j]) == d.end()){
                        diff++;
                        d[s[j]]++;
                    }
                }

                ans += diff;
                vis[s[i]] = true;
            }
        }

        return ans;
    }
};