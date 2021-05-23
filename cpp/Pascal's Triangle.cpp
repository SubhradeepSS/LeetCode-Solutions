class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for(int i=1;i<=numRows;i++){
            vector<int> u;
            int c=1;
            for(int j=1;j<=i;j++){
                u.push_back(c);
                c=c*(i-j)/j;
                //u.push_back(c);
            }
            v.push_back(u);
        }
        return v;
    }
};