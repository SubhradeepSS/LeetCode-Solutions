class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> done;
        string curr=s.substr(0,10);
        
        unordered_set<string> ans;
        
        done.insert(curr);
        for(int i=10;i<s.length();i++){
            curr=curr.substr(1)+s[i];
            if(done.find(curr) != done.end())
                ans.insert(curr);
            done.insert(curr);
        }
         
        return vector<string>(ans.begin(),ans.end());
    }
};