class Solution {
public:
bool isValid(int x,int y,int m,int n){
    return x>=0 && y>=0 && x<m && y<n;
}
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n));
        set<tuple<int,int,int>>st;
        if(grid[0][0]>0){

        st.insert({health-1,0,0});
        }else{
        st.insert({health,0,0});
        }
        vector<pair<int,int>>movements={
            {1,0},{0,1},{-1,0},{0,-1}
        };
        vis[0][0]=1;
        while(!st.empty()){
            auto [h,i,j]=*st.rbegin();
            st.erase(*st.rbegin());
                        // cout<<h-1<<" "<<i<<" "<<j<<endl;
            if(h>0&&i==m-1 && j==n-1){
                return true;
            }
            vis[i][j]=1;
            for(auto move:movements){
                int x=i+move.first;
                int y=j+move.second;
                if(isValid(x,y,m,n)){
                    if(!vis[x][y] && grid[x][y]>0){
                        if(h>0){
                            st.insert({h-1,x,y});
                        }
                    }else{
                        if(!vis[x][y]){
                            st.insert({h,x,y});
                        }
                    }
                }
            }
        }
        return false;

    }
};