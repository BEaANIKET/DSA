class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size(), 0);

        for (int i = 0; i < words.size(); i++) {
            if (isVowel(words[i].front()) && isVowel(words[i].back())) {
                prefix[i] = 1;
            }
        }

        for (int i = 1; i < words.size(); i++) {
            prefix[i] += prefix[i - 1];
        }

        vector<int> result;
        for (auto& query : queries) {
            int left = query[0], right = query[1];
            int count = prefix[right] - (left > 0 ? prefix[left - 1] : 0);
            result.push_back(count);
        }

        return result;
    }
};
