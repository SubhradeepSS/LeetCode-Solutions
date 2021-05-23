class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n, -1);
        col[0]=0;
        for(int i=0;i<n;i++){
            for(int j:graph[i]){
                if(col[j]==-1){
                    col[j]=1-col[i];
                }
                else if(col[j]==col[i]){
                    return false;
                }
            }
        }
        return true;
    }
};