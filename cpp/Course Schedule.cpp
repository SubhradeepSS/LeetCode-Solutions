class Graph{
    int v;
    list<int> *adj;
    public:
    Graph(int v){
        this->v=v;
        adj=new list<int>[v];
    }
    void addedge(int a,int b){
        adj[a].push_back(b);
    }
    bool cyclic(){
        vector<int> in(v,0);
        for(int i=0;i<v;i++){
            for(int j:adj[i])
                in[j]++;
        }
        queue<int> q;
        int c=0;
        for(int i=0;i<v;i++){
            if(in[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i:adj[u]){
                if(--in[i]==0)
                    q.push(i);
            }
            c++;
        }
        return (c==v);
    }
};


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses);
        for(int i=0;i<prerequisites.size();i++)
            g.addedge(prerequisites[i][0],prerequisites[i][1]);
        return g.cyclic();
    }
};