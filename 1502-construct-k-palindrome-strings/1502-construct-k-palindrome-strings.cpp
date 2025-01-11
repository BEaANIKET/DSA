class Solution {
public:
    bool canConstruct(string s, int k) {
        

        if( k>s.length()) return false;
        if( k==s.length()) return true;
        vector<int> v(26, 0);

        for(int i=0; i<s.size(); i++){
            v[s[i] - 'a'] ++;
        }

        int oddcount = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i] % 2 != 0){
                oddcount ++;
            }
        }

        return oddcount <= k;
    }
};