class Solution {
public:
    class Graph{
        int v;
        list<int> *adj;
        public:
        Graph(int v){
            this->v=v;
            adj=new list<int>[v];
        }
        void addE(int u,int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        void bfs(int s,vector<bool>& v){
            v[s]=true;
            queue<int> q;
            q.push(s);
            while(!q.empty()){
                int t=q.front();
                q.pop();
                for(int u:adj[t]){
                    if(!v[u]){
                        v[u]=true;
                        q.push(u);
                    }
                }
            }
        }
    };
    
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        Graph g(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(M[i][j]==1){
                    g.addE(i,j);
                    g.addE(j,i);
                }
            }
        }
        int c=0;
        vector<bool> v(n,false);
        for(int i=0;i<n;i++){
           if(!v[i]){
               g.bfs(i,v);
               c++;
           }
        }
        return c;
    }
};