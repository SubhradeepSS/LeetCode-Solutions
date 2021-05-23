class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int s=trust.size();
        if(s==0)
        {
            if(N==1)
                return 1;
            return -1;
        }
        int ans,c=0;
        unordered_map<int,int> mp;
        unordered_map<int,int> mp2;
        for(auto i:trust){
            mp[i[1]]++;
            mp2[i[0]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second>c&&mp2[it->first]==0){
                ans=it->first;
                c=it->second;
            }
        }
        int m=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second==c)
                m++;
        }
        if(m==1)
            return ans;
        return -1;
    }
};