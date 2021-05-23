class Solution {
public:
    int f(vector<int> citations,int l,int h,int n){
        if(l>h)
            return 0;
        if(l==h){
            if(citations[l]>=n-l)
                return n-l;
            else
                return 0;
        }
        int m=(l+h)/2;
        if(citations[m]>=n-m&&(m==0||(m>0&&citations[m-1]<n-m)))
            return n-m;
        if(citations[m]<n-m)
            return f(citations,m+1,h,n);
        else
            return f(citations,l,m,n);
    }
    
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        return f(citations,0,n-1,n);
    }
};