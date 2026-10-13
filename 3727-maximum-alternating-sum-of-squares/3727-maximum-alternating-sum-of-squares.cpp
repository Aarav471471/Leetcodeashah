class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(auto &x:nums){
            x=abs(x);
        }
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());

        long long ans=0;
        if(n&1){

            for(int i=0;i<=(n/2);i++){
                ans+=(long long)(nums[i]*nums[i]);
            }
            for(int i=n/2+1;i<n;i++){
                ans-=(long long)(nums[i]*nums[i]);
            }
        }else{
            for(int i=0;i<=(n/2)-1;i++){
                ans+=(long long)(nums[i]*nums[i]);
            }
            for(int i=n/2;i<n;i++){
                ans-=(long long)(nums[i]*nums[i]);
            }
        }
        return ans;
    }
};