class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        int has=-prices[0],no=0,prev=0;
        
        for(int i=1;i<prices.size();i++){
            int t=has;
            has=max(has,prev-prices[i]);
            prev=no;
            no=max(no,t+prices[i]);
        }
        
        return max(has,no);
    }
};