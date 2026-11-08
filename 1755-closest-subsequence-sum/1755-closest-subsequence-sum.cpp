class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int>subs1;
        vector<int>subs2;
        
        int n=nums.size();
        int a=n/2;
        int b=n-a;
        for(int i=0;i<(1<<a);i++){
            long long sum=0;
            for(int j=0;j<a;j++){
                if((i&(1<<j))){
                    // cout<<i<<" "<<j<<endl;
                    sum+=(nums[j]);
                }
            }
            subs1.push_back(sum);
        }
        for(int i=0;i<(1<<b);i++){
            int sum=0;
            for(int j=0;j<b;j++){
                if((i&(1<<j))){
                    sum+=(nums[n-j-1]);
                }
            }
            subs2.push_back(sum);
        }
        int ans=INT_MAX;
        sort(subs2.begin(),subs2.end());
        for(int i=0;i<subs1.size();i++){
            int lb=lower_bound(subs2.begin(),subs2.end(),goal-subs1[i])-subs2.begin();
            int ub=upper_bound(subs2.begin(),subs2.end(),goal-subs1[i])-subs2.begin()-1;
            if(ub==-1){ub++;}
            if(lb==subs2.size()){lb--;}
            int s1=subs1[i]+subs2[lb];
            int s2=subs1[i]+subs2[ub];
            // cout<<s1<<" "<<s2<<endl;
            ans=min({abs(goal-s1),abs(goal-s2),ans});
        }
        // for(int i=0;i<subs1.size();i++){
        //     cout<<subs1[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<subs2.size();i++){
        //     cout<<subs2[i]<<" ";
        // }
        return ans;
    }
};