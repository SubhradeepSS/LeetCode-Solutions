class Solution {
public:
    int maxPower(string s) {
        int n=s.length();
        vector<int> p(n,0);
        p[0]=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])
                p[i]=1+p[i-1];
            else
                p[i]=1;
        }
        return *max_element(p.begin(),p.end());
    }
};