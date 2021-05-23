class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> p1,p2;
        int curr=0,i=0;
        while(i<version1.length()){
            if(version1[i]!='.')
                curr=curr*10+version1[i]-'0';
            else{
                p1.push_back(curr);
                curr=0;
            }
            i++;
        }
        p1.push_back(curr);
        
        curr=0;i=0;
        while(i<version2.length()){
            if(version2[i]!='.')
                curr=curr*10+version2[i]-'0';
            else{
                p2.push_back(curr);
                curr=0;
            }
            i++;
        }
        p2.push_back(curr);
        
        int j=0,n=p1.size(),m=p2.size();i=0;
        while(i<n||j<m){
            if(i<n&&j<m){
                if(p1[i]<p2[j])
                    return -1;
                else if(p1[i]>p2[j])
                    return 1;
                i++;j++;
            }
            else if(i<n){
                if(p1[i]!=0)
                    return 1;
                i++;
            }
            else{
                if(p2[j]!=0)
                    return -1;
                j++;
            }
        }
        return 0;
    }
};