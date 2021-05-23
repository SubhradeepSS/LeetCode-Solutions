class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        for(auto ch:t){
            if(ch==s[i])
                i++;
        }
        return i>=s.length();
    }
};