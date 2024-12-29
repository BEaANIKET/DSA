class Solution {
public:
    string answerString(string word, int numFriends) {
        
        if(numFriends == 1){
            return word;
        }
        int maxLen = word.size() - numFriends + 1;
        string result = "";

        cout<< a;
        for(int i=0; i<word.size(); i++){
            result = max(result, word.substr(i, maxLen));
        }
        return result;
    }
};