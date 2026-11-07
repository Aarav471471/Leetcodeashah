class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // 1  2 9 10
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mid=0;
        if(n&1){
            mid=nums[n/2];
        }else{
            mid=(nums[n/2]+nums[n/2-1])/2;
        }
        cout<<mid<<endl;
        int ans=0;
        for(auto x:nums){
            ans+=abs(x-mid);
        }
        return ans;
    }
};