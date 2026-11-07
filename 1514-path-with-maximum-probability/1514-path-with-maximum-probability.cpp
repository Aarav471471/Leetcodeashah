class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        int m=edges.size();
        vector<vector<pair<double,int>>>graph(n);
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double wt=succProb[i];
            // cout<<wt<<endl;
            graph[u].push_back({wt,v});
            graph[v].push_back({wt,u});
        }
        // cout<<graph[0][0].first<<endl;
        set<pair<double,int>>st;
        st.insert({1,start});
        // vector<int>vis(n);
        // vis[start]=1;
        vector<double>dist(n,0);
        dist[start]=1;
        while(!st.empty()){
            auto [wt,i]=*st.rbegin();
            st.erase(*st.rbegin());
            // if(vis[i]){continue;}
            // vis[i]=1;
            for(auto c:graph[i]){
                    if(dist[c.second]<wt*c.first){
                        dist[c.second]=wt*c.first;
                        // cout<<c.second<<endl;
                        // cout<<dist[c.second]<<endl;
                        st.insert({dist[c.second],c.second});
                    }
            }
        }
        return dist[end];
    }
};