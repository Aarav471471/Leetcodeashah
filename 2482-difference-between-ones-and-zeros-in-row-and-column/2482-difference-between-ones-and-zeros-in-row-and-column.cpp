class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>v1(m);
        vector<int>v0(m);
        vector<int>v2(n);
        vector<int>v3(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    v1[i]++;
                    v2[j]++;
                }else{
                    v0[i]++;
                    v3[j]++;
                }
            }
        }
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<v1[i]<<" "<<v3[j]<<" "<<v2[j]<<" "<<v0[i]<<endl;
                ans[i][j]=v1[i]+v2[j] - (v3[j]+v0[i]);
            }
        }
        return ans;
    }
};