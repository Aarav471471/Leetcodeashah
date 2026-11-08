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
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>parent(n,0);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int cnt=0;
        for(auto x:connections){
            int a=x[0];
            int b=x[1];
            int p1=find(a,parent);
            int p2=find(b,parent);
            if(p1==p2){cnt++;continue;}
            Union(a,b,parent,rank);
        }
        int ex=-1;
         for(int i=0;i<n;i++){
            if(parent[i]==i){ex++;}
        }
        // cout<<cnt<<endl;
        // cout<<ex<<endl;
        if((cnt-ex)<0){
            return -1;
        }
        return ex;
    }
};