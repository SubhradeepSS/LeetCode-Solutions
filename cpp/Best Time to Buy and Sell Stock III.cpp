class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> p(n,0);
        int max_=prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(prices[i]>max_)
                max_=prices[i];
            p[i]=max(p[i+1],max_-prices[i]);
        }
        int min_=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]<min_)
                min_=prices[i];
            p[i]=max(p[i-1],p[i]+prices[i]-min_);
        }
        return p[n-1];
    }
};