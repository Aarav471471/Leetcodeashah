class Solution {
public:

int find(int i,vector<int>&parent){
    if(i==parent[i]){
        return i;
    }
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
    bool equationsPossible(vector<string>& equations) {
        vector<int>parent(26,0);
        vector<int>rank(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        int n=equations.size();
        for(auto x:equations){
            int a=(x[0]-'a');
            int b=(x[3]-'a');
           if(x[1]==x[2]){
                Union(a,b,parent,rank);
           }
        }
        for(auto x:equations){
            int a=(x[0]-'a');
            int b=(x[3]-'a');
           if(x[1]!=x[2]){
                // Union(a,b,parent,rank);
                int p1=find(a,parent);
                int p2=find(b,parent);
                if(p1==p2){return false;}
           }
        }

        return true;
    }
};