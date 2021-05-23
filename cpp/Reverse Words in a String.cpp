class Solution {
public:
    string reverseWords(string s) {
        string ans = "", curr = "";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                curr += s[i];
            }
            else if(curr!=""){
                ans = curr + (ans==""?"":" ") + ans;
                curr = "";
            }
        }
        if(curr!=""){
            ans = curr + (ans==""?"":" ") + ans;
        }
        return ans;
    }
};