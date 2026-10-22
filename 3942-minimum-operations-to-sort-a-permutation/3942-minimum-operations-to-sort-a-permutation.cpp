class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        if(is_sorted(nums.begin(),nums.end())){
            return 0;
        }
        vector<int>v=nums;
        reverse(v.begin(),v.end());
        if(is_sorted(v.begin(),v.end())){
            return 1;
        }
        int cnt=0;
        int cnt1=0;
        int i1=0;
        int i2=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){cnt++;i1=i+1;}
        }
        if(nums[0]<nums[n-1]){cnt++;i1=2;}
        for(int i=0;i<n-1;i++){
            if(v[i]>v[i+1]){cnt1++;i2=i+1;}
        }
        if(v[0]<v[n-1]){cnt1++;i2=2;}
        if(min(cnt,cnt1)>1){
            return -1;
        }
        // 2 0 1 
        // 4 0 1 2 3
        // 3,4,0,1,2
        if(cnt==1){
            return min(i1,n-i1+2);
        }else if(cnt1==1){
            // if(i2==1){i2++;}
            return min(i2+1,n-i2+1);
        }
        return 0;
    }
};