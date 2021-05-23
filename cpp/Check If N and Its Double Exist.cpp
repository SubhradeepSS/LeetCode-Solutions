class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for(int i:arr){
            if(s.find(i*2)!=s.end())
                return true;
            if(i%2==0&&s.find(i/2)!=s.end())
                return true;
            s.insert(i);
        }
        return false;
    }
};