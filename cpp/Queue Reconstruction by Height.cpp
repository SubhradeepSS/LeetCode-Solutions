class Solution {
public:
    
    static bool f(const vector<int>& a,const vector<int>& b){
        if(a[0]!=b[0])
            return a[0]>b[0];
        return a[1]<b[1];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),f);
        for(int i=1;i<people.size();i++){
            int pos=people[i][1];
            if(pos<i){
                int t=i;
                while(t!=pos){
                    swap(people[t],people[--t]);
                }
            }
        }
        return people;
    }
};