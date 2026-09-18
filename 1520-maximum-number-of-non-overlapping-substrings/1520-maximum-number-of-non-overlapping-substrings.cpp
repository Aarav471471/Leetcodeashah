class Solution{
public:
	void dfs(vector<vector<int>>&adj,vector<int>&vis,int i,stack<int>&st){
		vis[i]=1;
		for(auto it:adj[i]){
			if(!vis[it])dfs(adj,vis,it,st);
		}
		st.push(i);
	}
	void dfs2(vector<vector<int>>&radj,vector<int>&sccid,int i,int count){
		sccid[i]=count;
		for(auto it:radj[i]){
			if(sccid[it]==-1)dfs2(radj,sccid,it,count);
		}
	}
	vector<string> maxNumOfSubstrings(string s){
		vector<int>first(26,-1);
		vector<int>last(26,-1);
		int n=s.length();
		for(int i=0;i<n;i++){
			if(first[s[i]-'a']==-1)first[s[i]-'a']=i;
			last[s[i]-'a']=i;
		}
		vector<vector<int>>adj(26);
		vector<vector<int>>radj(26);
		for(int i=0;i<26;i++){
			if(first[i]!=-1){
				for(int j=first[i];j<=last[i];j++){
					int v=s[j]-'a';
					if(i!=v){
						adj[i].push_back(v);
						radj[v].push_back(i);
					}
				}
			}
		}
		stack<int>st;
		vector<int>vis1(26,0);
		for(int i=0;i<26;i++){
			if(first[i]!=-1&&!vis1[i]){
				dfs(adj,vis1,i,st);
			}
		}
		int count=0;
		vector<int>sccid(26,-1);
		while(!st.empty()){
			int a=st.top();
			st.pop();
			if(sccid[a]==-1){
				dfs2(radj,sccid,a,count);
				count++;
			}
		}
		vector<int>outdeg(count,0);
		for(int i=0;i<26;i++){
			if(first[i]!=-1){
				for(auto v:adj[i]){
					if(sccid[i]!=sccid[v]){
						outdeg[sccid[i]]=1;
					}
				}
			}
		}
		vector<string>ans;
		for(int i=0;i<count;i++){
			if(outdeg[i]==0){
				int minfirst=1e9;
				int maxlast=-1;
				for(int j=0;j<26;j++){
					if(first[j]!=-1&&sccid[j]==i){
						minfirst=min(minfirst,first[j]);
						maxlast=max(maxlast,last[j]);
					}
				}
				if(minfirst!=1e9){
					ans.push_back(s.substr(minfirst,maxlast-minfirst+1));
				}
			}
		}
		return ans;
	}
};