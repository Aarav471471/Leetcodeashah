class Solution {
public:
    bool isvalid(int x, int y, int m ,int n){
        if(x >= 0 && y >= 0 && x < m && y < n){
            return true;
        }
        return false;
    }
    int minPathSum(vector<vector<int>>& grid) {
         int m = grid.size();
         int n = grid[0].size();
         vector<pair<int,int>>movements = {
            {1,0},{0,1}
         };
         vector<vector<int>>dis(m,vector<int>(n,1e9));
         priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
         q.push({0,0,0});
         dis[0][0] = 0;
         while(!q.empty()){
            auto it = q.top();
            int d = it[0];
            int x = it[1];
            int y = it[2];
            q.pop();
            for(auto c : movements){
                 int a = x + c.first;
                 int b = y + c.second;
                 if(isvalid(a,b,m,n) && d + grid[x][y] < dis[a][b]){
                    dis[a][b] = d+ grid[x][y];
                    cout<< dis[a][b]<<endl;
                    q.push({dis[a][b],a,b});
                 }
            }
         }
         return dis[m-1][n-1] + grid[m-1][n-1];
    }
};