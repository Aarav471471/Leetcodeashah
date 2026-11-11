class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<int>&nums){
        int n=nums.size();
        if(i>=n){
            return 0;
        }
       
        if(j==-1){
            return max(1+solve(i+1,i,nums),solve(i+1,j,nums));;
        }
        if(dp[i][j]!=-1){return dp[i][j];}
        if(nums[j]<nums[i]){
            return dp[i][j]=max(1+solve(i+1,i,nums),solve(i+1,j,nums));
        }
        return dp[i][j]=solve(i+1,j,nums);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,vector<int>(n,-1));
        return solve(0,-1,nums);
    }
};