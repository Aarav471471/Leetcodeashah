class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD=1e9+7;
        int n=arr.size();
        vector<int>next(n,n);
        vector<int>prev(n,-1);
        stack<int>st;
        // stack<int>st2;

        st.push(0);
        for(int i=1;i<n;i++){
            if(!st.empty()){
                while(!st.empty() && arr[i]<arr[st.top()]){
                    next[st.top()]=i;
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            st.pop();
        }
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            if(!st.empty()){
                while(!st.empty() && arr[i]<=arr[st.top()]){
                    prev[st.top()]=i;
                    st.pop();
                }
                st.push(i);
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<next[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<prev[i]<<" ";
        // }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long term=(((i-prev[i])%MOD)*((next[i]-i)%MOD))%MOD;
            ans=(ans+((arr[i]%MOD)*(term%MOD))%MOD)%MOD;
        }
        return ans;

    }
};