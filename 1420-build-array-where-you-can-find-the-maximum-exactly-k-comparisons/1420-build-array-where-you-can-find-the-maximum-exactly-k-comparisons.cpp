class Solution {
public:
    vector<vector<vector<int>>>dp;
    const int mod=1e9+7;
    int ways(int i,int sc,int maxi,int k,int m,int n){
        if(i==n){
            if(sc==k){return 1;}
            return 0;
        }
    
            if(dp[i][sc][maxi]!=-1) return dp[i][sc][maxi];
        
        int ans=0;
        for(int j=1;j<=m;j++){
            if(j>maxi){
                ans=(ans+ways(i+1,sc+1,j,k,m,n))%mod;
            }else{
                ans=(ans+ways(i+1,sc,maxi,k,m,n))%mod;
            }
        }
        return dp[i][sc][maxi]=(ans%mod);
    }
    int numOfArrays(int n, int m, int k) {
        //1 2 5 4 6
        // if(k>m){return 0;}
        // if(k==m){return m;}
        // return 0;
        dp.assign(n+5,vector<vector<int>>(n+5,vector<int>(m+5,-1)));
        return ways(0,0,0,k,m,n);
    }
};