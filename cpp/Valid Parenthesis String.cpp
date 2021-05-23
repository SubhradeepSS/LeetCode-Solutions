class Solution {
public:
    bool checkValidString(string s) {
        if(s.length()==0)
            return true;
        stack<char> st;
        stack<char> util;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='*')
                st.push(s[i]);
            else{
                if(st.empty())
                    return false;
                if(st.top()=='(')
                    st.pop();
                else{
                    while(!st.empty()&&st.top()=='*'){
                        util.push('*');
                        st.pop();
                    }
                    if(st.empty())
                        util.pop();
                    else
                        st.pop();
                    while(!util.empty()){
                        st.push('*');
                        util.pop();
                    }
                }
            }
        }
        if(st.empty())
            return true;
        while(!st.empty()){
            if(st.top()=='*')
               { util.push('*');
                st.pop();}
            else{
                if(util.empty())
                    return false;
                else
                    {util.pop();
                    st.pop();}
            }
        }
        return true;
    }
};