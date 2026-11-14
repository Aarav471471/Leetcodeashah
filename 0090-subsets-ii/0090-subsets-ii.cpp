class Solution {
public:

    void solve(int i,int j,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        int n=nums.size();
        if(i>=n){
            // sort(ans.begin(),ans.end());
           ans.push_back(temp);
            return;
        }
            if(i==0||j==i-1||(nums[i]!=nums[i-1])){
                temp.push_back(nums[i]);
                solve(i+1,i,nums,temp,ans);
                temp.pop_back();
            }
                solve(i+1,j,nums,temp,ans);
            
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 1 2 2
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,n,nums,temp,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};