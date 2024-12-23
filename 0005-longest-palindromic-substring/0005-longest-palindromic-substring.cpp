class Solution {
public:

    int findLength(string s, int i, int j){
        while(i>=0 && j<s.length() && s[i] == s[j]){
            i--;
            j++;
        }

        return j-i -1;
    }

    string longestPalindrome(string s) {
        int end = 0; int start = 0;
        for(int i=0; i<s.length(); i++){

            int len1 = findLength(s, i, i);
            int len2 = findLength(s, i, i+1);

            int length = max(len1, len2);

            if( end - start < length){
                end = i + length/2;
                start = i - (length - 1)/2;
            }

        }

        string ans = s.substr(start, end-start + 1);

        return ans;
    };
};