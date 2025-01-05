class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        vector<int> diff(s.length(), 0);

        for(auto &v : shifts){
            int start = v[0];
            int end = v[1];
            int directions = v[2];
            int x = directions == 0 ? -1 : 1;
            diff[start] += x;
            if(end+1 < s.size()){
                diff[end+1] -= x;
            }
        }

        for(int i=1; i<diff.size(); i++){
            diff[i] += diff[i-1];
        }

        for(int i=0; i<s.length(); i++){
            int shift = diff[i] % 26;
            if(shift < 0){
                shift += 26;
            }

            s[i] = (((s[i] - 'a') + shift) % 26) + 'a';
        }

        return s;
    }
};