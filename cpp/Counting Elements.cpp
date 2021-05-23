class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> s;
        int c=0;
        for(int i=0;i<arr.size();i++){
            s.insert(arr[i]);
        }
        for(int i=0;i<arr.size();i++)
            if(s.find(arr[i]+1)!=s.end())
                c++;
        return c;
    }
};