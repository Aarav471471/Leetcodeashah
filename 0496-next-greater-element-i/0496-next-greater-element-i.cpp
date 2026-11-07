    class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            stack<int>st;
            map<int,int>next;
                if(st.empty()){st.push(nums2[0]);}
            for(int i=1;i<nums2.size();i++){
                if(!st.empty()){
                    // int t=st.top();
                    while(!st.empty()&&nums2[i]>st.top()){
                        next[st.top()]=(nums2[i]);
                        st.pop();
                    }
                        st.push(nums2[i]);
                }
                
            }
            while(!st.empty()){
                    next[st.top()]=(-1);
                    st.pop();
                }
            vector<int>ans;
            for(int i=0;i<nums1.size();i++){
                ans.push_back(next[nums1[i]]);
            }
            return ans;
        }
    };