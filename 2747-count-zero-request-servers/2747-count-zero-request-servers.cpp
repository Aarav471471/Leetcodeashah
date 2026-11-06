class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=logs.size();
        int q=queries.size();
        vector<pair<int,int>>vp(q);
        for(int i=0;i<q;i++){
            vp[i]={queries[i],i};
        }
        vector<int>ans(q);
        sort(vp.begin(),vp.end());
        auto lamda=[](vector<int>&v1,vector<int>&v2){
            return v1[1]<v2[1];
        };
        sort(logs.begin(),logs.end(),lamda);
        map<int,int>freq;
        int i=0;
        int j=0;
        for(int k=0;k<q;k++){
            int st=vp[k].first-x;
            int end=vp[k].first;
            int curr=0;
            while(j<m && logs[j][1]<=end){
                freq[logs[j][0]]++;
                j++;
            }
            while(i<m && logs[i][1]<st){
                freq[logs[i][0]]--;
                if(freq[logs[i][0]]==0){freq.erase(logs[i][0]);}
                i++;
            }
            ans[vp[k].second]=n-freq.size();
        }
        return ans;
    }
};