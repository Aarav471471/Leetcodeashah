class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i ,int j,vector<int>&nums,vector<int>&ans,vector<int>&fans){
        int n=nums.size();
        if(i>=n){
          
            return 0;
        }
        if(dp[i][j]!=-1){return dp[i][j];}
        int take=0;
        int skip=0;
        if(j==n || nums[i]%nums[j]==0){
           
                ans.push_back(nums[i]);
                take=1+solve(i+1,i,nums,ans,fans);
                // ans.pop_back();
                ans.pop_back();
            
        
                // ans.push_back(nums[i
            }
                skip=solve(i+1,j,nums,ans,fans);
        
        return dp[i][j]=max(take,skip);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>ans;
        vector<int>fans;
        int n=nums.size();
        dp.assign(n,vector<int>(n+1,-1));
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n;
         int k=solve(0,n,nums,ans,fans);
         while(i<n) {
            int skip=solve(i+1,j,nums,ans,fans);
            int take=0;

                if(j==n || nums[i]%nums[j]==0) {
                    take=1+solve(i+1,i,nums,ans,fans);
                }

                if((j==n || nums[i]%nums[j]==0) && take>=skip) {
                    fans.push_back(nums[i]);
                    j=i;
                }

                i++;
            }
         return fans;
    }
};