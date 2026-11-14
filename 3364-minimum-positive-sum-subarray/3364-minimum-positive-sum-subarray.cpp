class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        vector<int>pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        int ans=INT_MAX;
        for(int i=l;i<=r;i++){
            int u=0;
            int v=i-1;
            int mx=INT_MAX;
           while(v<n){
                int sum=0;
                if(u>0){
                    sum=pref[v]-pref[u-1];
                }else{
                    sum=pref[v];
                }
                if(sum>0){
                    mx=min(mx,sum);
                }
                v++;
                u++;
                // cout<<sum<<" "<<i<<" "<<endl;
            }
            ans=min(ans,mx);
        }
        //3 1 2 6
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};