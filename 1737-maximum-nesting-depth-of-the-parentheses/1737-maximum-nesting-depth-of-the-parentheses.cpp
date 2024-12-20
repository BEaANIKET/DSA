class Solution {
public:
    int maxDepth(string S) {
        stack<int>s;
        int ans=0;

        for(int i=0; i<S.length(); i++){
            if(S[i]=='(') s.push('(');
            if(S[i]==')')s.pop();

            ans=max(ans, (int)s.size());
        }

        return ans;
    }
};