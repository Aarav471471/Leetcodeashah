class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& events) {
        int k=4;
		int n=events.size();
		for(int i=0;i<n;i++){
			events[i].push_back(i);
		}
		sort(events.begin(),events.end());
		vector<int>v1(n);
		for(int i=0;i<n;i++){
			v1[i]=events[i][0];
		}
		vector<vector<pair<long long,vector<long long>>>>dp(n+1,vector<pair<long long,vector<long long>>>(k+1,{0,{}}));
		for(int i=n-1;i>=0;i--){
			int ni=upper_bound(v1.begin(),v1.end(),events[i][1])-v1.begin();
			for(int j=1;j<=k;j++){
				long long val1=events[i][2];
				vector<long long>idx1={events[i][3]};
				if(ni<n){
					val1+=dp[ni][j-1].first;
					idx1.insert(idx1.end(),dp[ni][j-1].second.begin(),dp[ni][j-1].second.end());
				}
				sort(idx1.begin(),idx1.end());
				long long val2=dp[i+1][j].first;
				vector<long long>idx2=dp[i+1][j].second;
				if(val1>val2||(val1==val2&&idx1<idx2)){
					dp[i][j]={val1,idx1};
				}else{
					dp[i][j]={val2,idx2};
				}
			}
		}
        vector<int> ans;
        for(int i=0; i<dp[0][k].second.size(); i++)ans.push_back(dp[0][k].second[i]);
		return ans;
        
    }
};