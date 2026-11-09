class Solution {
public:
    int find(int i,vector<int>&parent){
        if(i==parent[i]){return i;}
        return parent[i]=find(parent[i],parent);
    }
    void Union(int a,int b,vector<int>&parent,vector<int>&rank){
        int p1=find(a,parent);
        int p2=find(b,parent);

        if(p1==p2){
            return;
        }
        if(rank[p1]>rank[p2]){
            parent[p2]=p1;
        }else if(rank[p2]>rank[p1]){
            parent[p1]=p2;
        }else{
            parent[p2]=p1;
            rank[p1]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
       vector<int>parent(n,0);
       vector<int>rank(n,0);
       for(int i=0;i<n;i++){
        parent[i]=i;
       }

        map<string,int>mpp;
        for(int j=0;j<n;j++){
            vector<string>x=accounts[j];
            for(int i=1;i<x.size();i++){
                if(mpp.find(x[i])!=mpp.end()){
                    int p1=mpp[x[i]];
                    Union(j,mpp[x[i]],parent,rank);
                    
                }else{
                    mpp[x[i]]=j;
                }
            }
        }
        // for(auto x:mpp){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        vector<vector<string>>ans(n);
            // vector<string>block;
        for(int i=0;i<n;i++){
            ans[i].push_back(accounts[i][0]);
        }
        for(auto x:mpp){
            int p1=find(x.second,parent);
            ans[p1].push_back(x.first);
        }
        vector<vector<string>>ans2;
        for(auto &x:ans){
            if(x.size()>1){ans2.push_back(x);}
        }
        return ans2;
    }
};