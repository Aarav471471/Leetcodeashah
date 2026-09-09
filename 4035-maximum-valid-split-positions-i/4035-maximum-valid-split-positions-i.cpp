class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int>org1(n,0);
        vector<int>org2(n,0);
        org1[0]=nums[0];
        org2[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            org1[i]=__gcd(org1[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            org2[i]=__gcd(org2[i+1],nums[i]);
        }
        for(int i=0;i<n-1;i++){
            // org1[i]=__gcd(org1[i-1],nums[i])
            if(org1[i]==org2[i+1]){ans++;}
        }
        
        
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                if(j!=i){
                    temp.push_back(nums[j]);
                }
            }
            int cnt=0;
            vector<int>pref(n-1,0);
            vector<int>suff(n-1,0);
            pref[0]=temp[0];
            suff[n-2]=temp[n-2];
            for(int j=1;j<n-1;j++){
                pref[j]=__gcd(pref[j-1],temp[j]);
            }
            for(int j=n-3;j>=0;j--){
                suff[j]=__gcd(suff[j+1],temp[j]);
            }
            for(int j=0;j<n-2;j++){
                if(pref[j]==suff[j+1]){cnt++;}
            }
           
            ans=max(ans,cnt);
        }
        return ans;
    }
};