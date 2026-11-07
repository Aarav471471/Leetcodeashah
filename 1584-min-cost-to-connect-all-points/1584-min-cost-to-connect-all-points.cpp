class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        vector<vector<pair<int,int>>>graph(n);
        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
           for(int j=i+1;j<n;j++){
            int x2=points[j][0];
            int y2=points[j][1];
            int wt=abs(x1-x2)+abs(y1-y2);
            graph[i].push_back({wt,j});
            graph[j].push_back({wt,i});
           }
        }
        set<pair<int,int>>st;
        vector<int>vis(n,0);
        st.insert({0,0});
        while(!st.empty()){
            auto [wt,i]=*st.begin();
            st.erase(*st.begin());
            if(vis[i]){
                continue;
            }
                ans+=wt;
            vis[i]=1;
            for(auto c:graph[i]){
                if(!vis[c.second]){
                    // cout<<c.second<<" "<<i<<endl;
                    // ans+=c.first;
                    st.insert({c.first,c.second});
                }
            }
        }
        return ans;
    }
};