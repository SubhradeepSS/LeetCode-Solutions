class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        int n=s.length();
        vector<bool> valid(n,false);
        
        for(int i=0;s[i];i++){
            if(s[i]=='('){
                st.push({'(',i});
            }
            else if(s[i]==')'){
                if(!st.empty()&&st.top().first=='('){
                    valid[st.top().second]=true;
                    valid[i]=true;
                    st.pop();
                }
            }
        }
        
        string ans="";
        for(int i=0;s[i];i++){
            if(s[i]!='('&&s[i]!=')')
                ans+=s[i];
            else if(valid[i])
                ans+=s[i];
        }
        return ans;
    }
};