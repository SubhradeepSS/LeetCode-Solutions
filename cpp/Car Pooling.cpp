class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> util(1001, 0);
        for(auto t:trips){
            util[t[1]] += t[0];
            util[t[2]] -= t[0];
        }
        int curr=0;
        for(int i:util){
            curr += i;
            if(curr>capacity)
                return false;
        }
        return true;
    }
};