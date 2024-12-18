class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string pref = strs[0];
        int len = pref.length();

        for (int i = 1; i < strs.size(); i++) {

            while (len > strs[i].length() || pref != strs[i].substr(0, len)) {
                len--;
                if (len == 0)
                    return "";

                pref = pref.substr(0, len);
            }
           
        }

        return pref;
    }
};

/*
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = "";
        if(strs.size() == 1){
            return strs[0];
        }
        for(int i=0; i<strs[0].length(); i++){
            char ch = strs[0][i];
            for(int j=0; j<strs.size(); j++){
                if(strs[j][i] != ch){
                    return ans;
                }
            }
            ans += ch;
        }

        return ans ;
    }
};

*/