class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=0;
        int x=(start^goal);
        while((x)>0){
            if(x&1){
                ans++;
            }
            x=(x>>1);
        }
        // 1010
        // 0111
        // 1101
        return ans;
    }
};