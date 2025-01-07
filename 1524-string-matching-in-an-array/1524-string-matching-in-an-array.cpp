class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {

        vector<string>ans;
        map<string, bool>mp;

        for(int i=0; i<words.size(); i++){
            string s1 = words[i];
            for(int j=0; j<words.size(); j++){
                if(i != j){
                string s2 = words[j];
                    string small = "";
                    string big = ""; 
                    if(s1.length() < s2.length()){
                        small = s1;
                        big = s2;
                    }
                    else{
                        small = s2;
                        big = s1;
                    }
                    
                    int index = big.find(small);
                    cout<<small <<" "<<big<<" "<<index<<endl;
                    if( !mp[small] && index >=0 && index + small.length() <= big.length() ){
                        mp[small] = true;
                        ans.push_back(small);
                    }
                }
            }
        }

        return ans;
    }
};