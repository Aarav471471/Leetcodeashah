class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        int ans=INT_MAX;
        for(int i=mini;i<=maxi;i++){
            int ops=0;
            int isC=1;
            for(int j=0;j<n;j++){
                if(nums[j]<=i){
                    ops+=i-nums[j];
                    // cout<<ops<<endl;
                }else{
                    isC=0;
                }
            }
            if(isC){
                ans=min(ops,ans);
            }
        }
        return ans;
    }
};