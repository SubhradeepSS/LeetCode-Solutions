class Solution {
public:
    int lengthOfLastWord(string s) {
        string last="";
        int i=s.length()-1;
        while(i>=0&&s[i]==' ')
            i--;
        for(;i>=0;i--){
            if(s[i]!=' ')
                last+=s[i];
            else
                break;
        }
        return last.length();
    }
};