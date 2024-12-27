class Solution {
public:
    string reverseWords(string s) {

        int i = 0;
        string ans = "";
        while (s[i] == ' ' && i < s.length())
            i++;

        string temp = "";
        while (i < s.length()) {

            if (s[i] != ' ') {
                while (s[i] != ' ' && i < s.length()) {
                    temp += s[i];
                    i++;
                }
                temp += ' ';
                ans = temp + ans;
                temp = "";
            }
            else{
                i++;
            }
        }

        int j = ans.length() - 1;

        while (ans[j] == ' ') {
            ans.pop_back();
            j--;
        }

        return ans;
    }
};