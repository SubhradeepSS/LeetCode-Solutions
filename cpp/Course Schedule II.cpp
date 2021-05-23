class Solution {
public:
    class Graph{
        int v;
        list<int> *adj;
        public:
            Graph(int v){
                this->v=v;
                adj = new list<int>[v];
            }
            void addE(int u,int v){
                adj[u].push_back(v);
            }
            vector<int> topSort(){
                vector<int> in_d(v,0);
                for(int i=0;i<v;i++){
                    for(int j:adj[i])
                        in_d[j]++;
                }
                queue<int> q;
                for(int i=0;i<v;i++){
                    if(in_d[i]==0)
                        q.push(i);
                }
                int visited=0;
                vector<int> ans;
                while(!q.empty()){
                    int t=q.front();
                    q.pop();
                    ans.push_back(t);
                    visited++;
                    for(int i:adj[t]){
                        if(--in_d[i]==0)
                            q.push(i);
                    }
                }
                vector<int> l;
                return (visited==v?ans:l);
            }
    };
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses);
        for(auto i:prerequisites){
            g.addE(i[1],i[0]);
        }
        return g.topSort();
    }
};