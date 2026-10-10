class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        map<long long, long long> freq;
        
        for(int i = 0; i < n; i++){
            freq[abs(nums1[i] - nums2[i])]++;
        }
        
        long long k = (long long)k1 + k2;
        while(k > 0 && !freq.empty()){
            auto it = prev(freq.end());
            long long curr_max = it->first;
            if(curr_max == 0) break; 
            long long sec_max = 0;
            if(it != freq.begin()){
                sec_max = prev(it)->first;
            }
            long long cnt=it->second;
            long long diff=curr_max-sec_max;
            long long ops_needed = diff*cnt;
            
            if(ops_needed <= k){
                k -= ops_needed;
                freq[sec_max] += cnt;
                freq.erase(curr_max);
            } else {
                long long drop = k/cnt;
                long long rem = k%cnt;
                long long new_val=curr_max-drop;
                
                freq.erase(curr_max);
                freq[new_val] += (cnt-rem);
                freq[new_val-1]+=rem;       
                k = 0;
                break;
            }
        }
        long long ans = 0;
        for(auto& x : freq){
            ans+=x.first*x.first*x.second;
        }
        return ans;
    }
};