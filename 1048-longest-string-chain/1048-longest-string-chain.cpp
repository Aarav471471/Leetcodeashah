class Solution {
public:

    bool check(string s1,string s2){
        int l1=s1.size();
        int l2=s2.size();
        if(l2-l1!=1){return false;}
        int idx=l2-1;
        for(int i=0;i<l1;i++){
            if(s1[i]!=s2[i]){
                idx=i;
                break;
            }
        }
        int i=0;
        int j=0;
        while(i<l1 && j<l2){
            if(j!=idx){
                if(s1[i]!=s2[j]){return false;}
                i++;
                j++;
            }else{
                j++;
            }
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<pair<int,string>>word;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            // cout<<words[i]<<" ";
            word.push_back({words[i].length(),words[i]});
        }
        sort(word.begin(),word.end());
        // cout<<endl;
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(word[j].second,word[i].second)){
                    dp[i]=max(dp[i],dp[j]+1);
                    cout<<dp[i]<<" "<<i<<endl;
                    ans=max(ans,dp[i]);
                }
            }
        }
       return ans;
    }
};