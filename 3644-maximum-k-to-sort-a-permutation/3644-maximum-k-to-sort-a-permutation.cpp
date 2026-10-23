class Solution {
public:

    int np2(int n){
        int cnt=0;
        while(n>0){
            n/=2;
            cnt++;
        }
        return cnt;
    }
    int sortPermutation(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                ans=nums[i]&i;
                break;
                // cout<<ans<<endl;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                ans&=nums[i]&i;
                // break;
                // cout<<ans<<endl;
            }
        }
        
        
        if(ans==INT_MAX){return 0;}
        return ans;
        
    }
};