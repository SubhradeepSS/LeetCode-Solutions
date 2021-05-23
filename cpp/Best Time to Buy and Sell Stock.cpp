class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        if(prices.size()<=1)
            return 0;
        int min_cost=prices[0];
        for(int i=1;i<prices.size();i++){
            min_cost=min(min_cost,prices[i]);
            ans=max(ans,prices[i]-min_cost);
        }
        return ans;
    }
};