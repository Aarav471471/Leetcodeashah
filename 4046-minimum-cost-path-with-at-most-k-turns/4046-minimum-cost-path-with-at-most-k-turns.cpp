class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    int minCost(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        set<tuple<int,int,int,int,int>>q;
        q.insert({grid[0][0],0,0,4,0});
        vector<vector<vector<int>>>vis(m,vector<vector<int>>(n,vector<int>(5,1e9)));
        // vis[0][0][0]=1;
        // vis[0][0][1]=1;
        // vis[0][0][2]=1;
        // vis[0][0][3]=1;
       int dx[4]={1,0,-1,0};
       int dy[4]={0,1,0,-1};
        while(!q.empty()){
            auto [cost,x,y,dir,turns]=*q.begin();
            q.erase(q.begin());
        
            if(x==m-1 && y==n-1){
                return cost;
            }

            if(turns>vis[x][y][dir]){
                continue;
            }
            vis[x][y][dir]=turns;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(isValid(nx,ny,m,n)){
                    int nturns=turns;
                    if(dir!=4&&dir!=i){
                        nturns++;
                    }
                    int ncost=cost+grid[nx][ny];

                    if(nturns<=k && nturns<vis[nx][ny][i]){
                        // vis[nx][ny][i]=nturns;
                        q.insert({ncost,nx,ny,i,nturns});
                    }
                }
            }
        }
        return -1;
    }
};