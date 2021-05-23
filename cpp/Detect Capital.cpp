class Solution {
public:
    bool detectCapitalUse(string word) {
        int i=0;
        for(i=0;i<word.length();i++){
            if(word[i]<65||word[i]>90)
                break;
        }
        if(i==word.length())
            return true;
        for(i=0;i<word.length();i++){
            if(i!=0&&word[i]>=65&&word[i]<=90)
                return false;
        }
        return true;
    }
};