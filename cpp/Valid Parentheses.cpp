class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;s[i];i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                st.push(s[i]);
            else{
                if(st.empty())
                    return false;
                if(st.top()=='[')
                {
                    if(s[i]!=']')
                        return false;
                    else
                        st.pop();
                }
                else if(st.top()=='{'){
                    if(s[i]!='}')
                        return false;
                    else
                        st.pop();
                }
                else if(st.top()=='('){
                    if(s[i]!=')')
                        return false;
                    else
                        st.pop();
                }
            }
        }
        return (st.empty());
    }
};