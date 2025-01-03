class Solution {
public:
vector<string>result;

    void solve( int open, int close, string ans){

        if(open<0 || close<0){
            return;
        }

        if(open==0 && close==0){
            result.push_back(ans);
            ans = "";
            return;
        }

        if(open){
            ans.push_back('(');
            solve(open-1, close, ans);
            ans.pop_back();
        }

        if(close && close>open){
            ans.push_back(')');
            solve(open, close-1, ans);
            ans.pop_back();
        }

        return;
    }
    vector<string> generateParenthesis(int n) {
        solve(n, n, "");
        return result;
    }
};