class Solution {
public:
int find(int i,vector<int>&parent){
        if(i==parent[i]){return i;}
        return parent[i]=find(parent[i],parent);
    }
    void Union(int a,int b,vector<int>&parent,vector<int>&rank){
        int p1=find(a,parent);
        int p2=find(b,parent);
        if(p1==p2){return;}
        if(rank[p1]>rank[p2]){
            parent[p2]=p1;
        }else if(rank[p2]>rank[p1]){
            parent[p1]=p2;
        }else{
            parent[p2]=p1;
            rank[p1]++;
        }

    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>parent(n,0);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int>freq(n,0);
        for(auto x:edges){
            int a=x[0];
            int b=x[1];
            int p1=find(a,parent);
            int p2=find(b,parent);
            if(p1!=p2){Union(a,b,parent,rank);}
        }
        for(int i=0;i<n;i++){
            freq[find(parent[i],parent)]++;
        }
        sort(freq.begin(),freq.end());
        vector<int>pref(n,0);
        pref[0]=freq[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+freq[i];
            // cout<<parent[i]<<endl;
        }
        long long ans=0;
        for(int i=1;i<n;i++){
            ans=ans+(1LL*freq[i]*pref[i-1]);
        }
        return ans;



    }
};