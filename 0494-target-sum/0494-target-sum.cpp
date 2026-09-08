class Solution {
public:
    vector<vector<int>>dp;
    int func(int i,int curr,vector<int>&nums,int target){
        if(i>=nums.size()){
            if(curr==(target)){return 1;}
            else return 0;
        }
        if(dp[i][1000+curr]!=-1){return dp[i][1000+curr];}
        int ways=0;
        ways=func(i+1,curr-nums[i],nums,target)+func(i+1,curr+nums[i],nums,target);
        return dp[i][1000+curr]=ways;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        dp.assign(n+1,vector<int>(2005,-1));
        int ans=func(0,0,nums,target);
        return ans;
    }
};