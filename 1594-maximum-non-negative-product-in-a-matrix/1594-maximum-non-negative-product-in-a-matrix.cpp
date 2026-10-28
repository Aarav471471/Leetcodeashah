class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        long long mod=1e9+7;
        vector<vector<long long>>dpmax(m,vector<long long>(n,-1e18));
        vector<vector<long long>>dpmin(m,vector<long long>(n,1e18));
        dpmax[0][0]=grid[0][0];
        dpmin[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0){
                    dpmax[i][j]=max({dpmax[i-1][j]*grid[i][j],dpmin[i-1][j]*grid[i][j],dpmax[i][j]});
                    dpmin[i][j]=min({dpmax[i-1][j]*grid[i][j],dpmin[i-1][j]*grid[i][j],dpmin[i][j]});
                }if(j>0){
                    dpmax[i][j]=max({dpmax[i][j-1]*grid[i][j],dpmin[i][j-1]*grid[i][j],dpmax[i][j]});
                    dpmin[i][j]=min({dpmax[i][j-1]*grid[i][j],dpmin[i][j-1]*grid[i][j],dpmin[i][j]});
                }
            }
        }
        if(dpmax[m-1][n-1]<0){return -1;}
        return dpmax[m-1][n-1]%mod;
    }
};