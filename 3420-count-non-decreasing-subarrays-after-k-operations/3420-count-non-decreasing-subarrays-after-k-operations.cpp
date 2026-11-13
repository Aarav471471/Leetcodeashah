class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>pref(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        vector<int>nxtGreater(n,n);
        stack<int>st;
        // st.push(0);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]>nums[st.top()]){
                    nxtGreater[st.top()]=i;
                    st.pop();
            }
            st.push(i);
        }
        // while(!st.empty()){
        //     nxtGreater[st.top()]=-1;
        //     st.pop();
        // }
        vector<long long>ops(n+1,0);
        for(int i=n-1;i>=0;i--){
            int m=nxtGreater[i];
            long long sum=0;
            if(i>0){
                sum=pref[m-1]-pref[i-1];
            }else{
                sum=pref[m-1];
            }
            long long rops=(1LL*nums[i]*(m-i))-(sum);
            ops[i]=rops+ops[m];
        }

        deque<int>deq;
        long long ans=0;
        int l=0;
        int r=0;
        while(r<n){
            while(!deq.empty() && nums[r]>nums[deq.back()]){
                deq.pop_back();
            }
            deq.push_back(r);

            while(l<=r){
                int m=deq.front();
                long long sum=0;
                if(m>0){
                    sum=pref[r]-pref[m-1];
                }else{
                    sum=pref[r];
                }
                long long cnt=(ops[l]-ops[m])+(1LL*nums[m]*(r-m+1))-sum;

                if(cnt<=k){
                    break;
                }
                l++;
                if(deq.front()<l){
                    deq.pop_front();
                }

            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
};