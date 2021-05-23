class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        // cout<<s;
        stack<char> st;
        for(char c:s){
            if(isalnum(c))
                st.push(c);
        }
        // cout<<st.top();
        for(char c:s){
            if(isalnum(c)&&c!=st.top())
                return false;
            else if(isalnum(c))
                st.pop();
        }
        return true;
    }
};