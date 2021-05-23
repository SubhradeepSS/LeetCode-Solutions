class Solution {
public:
    int firstUniqChar(string s) {
        pair<int,int> p[256];
        for(int i=0;i<s.length();i++){
            (p[s[i]].first)++;
            p[s[i]].second=i;
        }
        int min=INT_MAX;
        for(int i=0;i<256;i++){
            if(p[i].first==1&&min>p[i].second)
                min=p[i].second;                
        }
        return (min!=INT_MAX?min:-1);
    }
};