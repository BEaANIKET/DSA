// class Solution {
// public:

//     int solve(vector<int>& v, int i, int j, vector<vector<int>>& dp){

//         if(i>=v.size() || j>=v.size() || i>=j){
//             return 0;
//         }

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         int score = v[i] + v[j] + i - j;

//         int opt1 = solve(v, i+1, j, dp);
//         int opt2 = solve(v, i, j+1, dp);
//         int opt3 = solve(v, i+1, j+1, dp);

//         return dp[i][j] = max(score, max(opt1, max(opt2, opt3)));

//     }

//     int maxScoreSightseeingPair(vector<int>& values) {

//         vector<vector<int>>dp(values.size(), vector<int>(values.size(), -1));
//         return solve(values, 0, 1, dp);
//     }
// };

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int bestPrev = values[0] + 0; 
        
        for (int j = 1; j < values.size(); ++j) {
            maxScore = max(maxScore, bestPrev + values[j] - j);
            bestPrev = max(bestPrev, values[j] + j);
        }
        
        return maxScore;
    }
};
