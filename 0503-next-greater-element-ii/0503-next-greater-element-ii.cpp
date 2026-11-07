class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>nums2;
        for(int i=0;i<n;i++){
            nums2.push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            nums2.push_back(nums[i]);
        }
        vector<int>ans(2*n,-1);
        stack<int>st;
        st.push(0);
        for(int i=1;i<2*n;i++){
            if(!st.empty()){
                while(!st.empty() && nums2[i]>nums2[st.top()]){
                    ans[st.top()]=(nums2[i]);
                    st.pop();
                }
                    st.push(i);
            }
        }
        ans.erase(ans.begin()+n,ans.end());
        return ans;
    }
};