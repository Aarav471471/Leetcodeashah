class Solution {
public:
vector<vector<int>>dp;
    int func(int i,int tot,vector<int>&nums){
        if(i<0 || tot==0){return 0;}
        if(dp[i][tot]!=-1){return dp[i][tot];}
        int sum=0;
        sum=func(i-1,tot,nums);

        if(nums[i]<=tot){
            sum=max(sum,func(i-1,tot-nums[i],nums)+nums[i]);
        }
        return dp[i][tot]=sum;

    }
    int lastStoneWeightII(vector<int>& stones) {
        // sort(stones.begin(),stones.end());
        int n=stones.size();
        dp.assign(n,vector<int>(3005,-1));
        int tot=accumulate(stones.begin(),stones.end(),0);
        int s=func(n-1,tot/2,stones);
        return tot-2*s;
    }
};