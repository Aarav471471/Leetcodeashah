class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=0;
        int ans1=0;
        int cnt=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                cnt++;
                ans=max(ans,cnt);
            }else{
                cnt=1;
            }
        }
        ans=max(ans,cnt);
        cnt=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                cnt++;
                ans=max(ans,cnt);
            }else{
                cnt=1;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};