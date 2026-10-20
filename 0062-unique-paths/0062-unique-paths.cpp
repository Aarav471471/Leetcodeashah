class Solution {
public:

    // long long fact(int n){
    //     if(n==1 || n==0){return 1;}
    //     return fact(n-1)*n;
    // }
    int uniquePaths(int m, int n) {
       long long ans=1;
       for(int i=1;i<=min(m-1,n-1);i++){
        ans=ans*(m+n-2-min(m-1,n-1)+i)/i;
       }
    //    (n-1+1)
       return ans;
    }
};