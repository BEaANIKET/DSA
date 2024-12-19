class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> S;
        map<char, char> T;

        for (int i = 0; i < t.length(); i++) {
            if(S.find(s[i]) == S.end()){
                S[s[i]] = i;
            }
            if(T.find(t[i]) == T.end()){
                T[t[i]] = i;
            }

            if(S[s[i]] != T[t[i]]){
                return false;
            }
        }

        return true;
    }
};