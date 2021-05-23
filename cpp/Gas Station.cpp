class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        if(n==1)
            return (gas[0] >= cost[0] ? 0 : -1);
        int start=0,end=1,curr=gas[0]-cost[0];
        while(start!=end || curr<0){
            while(start!=end && curr<0){
                curr -= gas[start] - cost[start];
                start = (start+1)%n;
                if(start == 0)
                    return -1;
            }
            curr += gas[end] - cost[end];
            end = (end+1)%n;
        }
        return start;
    }
};