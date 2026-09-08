class Solution {
public:

    int func(int i,int curr,vector<int>&nums,int target){
        if(i>=nums.size()){
            if(curr==target){return 1;}
            else return 0;
        }
        int ways=0;
        ways=func(i+1,curr-nums[i],nums,target)+func(i+1,curr+nums[i],nums,target);
        return ways;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=func(0,0,nums,target);
        return ans;
    }
};