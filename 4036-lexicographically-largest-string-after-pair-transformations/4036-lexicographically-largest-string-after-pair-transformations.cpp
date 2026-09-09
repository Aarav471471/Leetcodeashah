class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string>a;
        for(int i=0;i<nums.size();i++){
            string t="";
            int x=-1;
            for(int k=0;k<32;k++){
                int bit=(nums[i]>>k)&1;
                x++;
                if(bit){
                    if(x>25){
                        x=25;
                    t+=(char)(x+'a');
                    }
                   t+=(char)(x+'a');
                }
            }
            reverse(t.begin(),t.end());
            a.push_back(t);
        }
        return a;
        
    }
};