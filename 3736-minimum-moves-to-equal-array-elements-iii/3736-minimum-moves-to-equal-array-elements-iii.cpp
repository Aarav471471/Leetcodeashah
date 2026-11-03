class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        int ans=INT_MAX;
     
            int ops=0;
            // int isC=1;
            for(int j=0;j<n;j++){
            
                    ops+=maxi-nums[j];
                    // cout<<ops<<endl;
                
            }
        
        return ops;
    }
};