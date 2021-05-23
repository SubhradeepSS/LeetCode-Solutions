class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int time=0,ans=0;
        for(int t:timeSeries){
            if(t>time){
                ans += duration;
            }
            else{
                ans += t+duration-time;
            }
            time = t+duration;
        }
        return ans;
    }
};