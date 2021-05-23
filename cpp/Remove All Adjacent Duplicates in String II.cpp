class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(char c:s){
            if(st.empty() || st.top().first!=c){
                st.push({c,1});
            }
            else if(st.top().first == c){
                if(st.top().second == k-1){
                    for(int i=0;i<k-1;i++){
                        st.pop();
                    }
                }
                else{
                    st.push({c,st.top().second+1});    
                }
            }
        }
        string ans="";
        while(!st.empty()){
            // cout<<st.top().first<<st.top().second;
            ans = st.top().first + ans;
            st.pop();
        }
        return ans;
    }
};