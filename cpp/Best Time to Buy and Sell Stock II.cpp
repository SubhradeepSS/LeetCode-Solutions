class Solution {
public:
    int maxProfit(vector<int>& a) {
        int c=0,n=a.size();
        if(n==0||n==1)
            return 0;
        int i=0;
        int b,s;
        while(i<a.size()-1){
            while(i<n-1&&a[i]>=a[i+1])
                i++;
            if(i==n-1)
                break;
            b=i++;
            while(i<n&&a[i-1]<=a[i])
                i++;
            s=i-1;
            c+=a[s]-a[b];
        }
        return c;
    }
};