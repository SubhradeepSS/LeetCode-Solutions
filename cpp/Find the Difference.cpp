class Solution {
public:
    char findTheDifference(string s, string t) {
        int n=s.size();
        vector<int> pres(26,0);
        for(char ch:s){
            pres[ch-'a']++;
        }
        for(char ch:t){
            if(pres[ch-'a']==0)
                return ch;
            pres[ch-'a']--;
        }
        return 'a';
    }
};