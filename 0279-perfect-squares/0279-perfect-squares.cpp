class Solution {
public:
    vector<int>dp;
    int ways(int sum,int n){
        if(sum==0){return 0;}
        if(dp[sum]!=-1){return dp[sum];}
        int cnt=INT_MAX;
        for(int i=1;i<=n;i++){
            if(i*i<=sum){
                cnt=min({cnt,ways(sum-i*i,n)+1});
            }
        }
        return dp[sum]=cnt;
    }
    int numSquares(int n) {
        dp.assign(n+1,-1);
        return ways(n,n);
    }
};