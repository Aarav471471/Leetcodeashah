class Solution {
public:

    bool cycleDfs(int i,vector<vector<int>>&graph,vector<int>&state,vector<int>&ans2){
        int m=graph.size();
        state[i]=1;
        for(auto c:graph[i]){
            if(state[c]==1){
                ans2={i,c};
                return true;
            }
            if(state[c]==0 && cycleDfs(c,graph,state,ans2)){
                // ans2={i,c};
                return true;
            }
        }
        state[i]=2;
        return false;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>inorder(n+1);
        vector<int>ans;
        vector<int>ans2;
        vector<int>state(n+1,0);

         vector<vector<int>>graph(n+1);
        for(auto x:edges){
            int i=x[0];
            int j=x[1];

            graph[i].push_back(j);
        }
        for(int i=0;i<=n;i++){
            for(auto x:graph[i]){
                inorder[x]++;
            }
        }
        int node=-1;
        for(int i=0;i<=n;i++){
            if(inorder[i]==2){
                node=i;
                break;
            }
        }
       vector<int>edge1;
        vector<int>edge2;

        if(node!=-1){
                for(auto x:edges){
                    if(x[1]==node){
                        if(edge1.size()==0){
                            edge1.push_back(x[0]);
                            edge1.push_back(node);
                        }else{
                            edge2.push_back(x[0]);
                            edge2.push_back(node);
                            // edge2=({i,node});

                        }
                    }
                }
            
        
        //remove edge1;
        int l=edge1[0];
        for(int i=0;i<graph[l].size();i++){
            if(graph[l][i]==node){graph[l].erase(graph[l].begin()+i);}
        }
            // for(int i=0;i<=n;i++){
            //     for(auto x:graph[i]){
            //         cout<<i<<" "<<x<<endl;
            //     }
            //     cout<<endl;
            // }
            int isCycle=0;
            for(int i=0;i<=n;i++){
                if(cycleDfs(i,graph,state,ans2)){
                   isCycle=1; 
                }
            }
            if(!isCycle){

                    ans=edge1;
            }
            isCycle=0;
            graph[l].push_back(node);
            // cout<<ans[0]<<" "<<ans[1]<<endl;
            //remove edge2;
            int r=edge2[0];
             for(int i=0;i<graph[r].size();i++){
                 if(graph[r][i]==node){graph[r].erase(graph[r].begin()+i);}
             }
             state.assign(n+1,0);
            //  for(int i=0;i<=n;i++){
            //     for(auto x:graph[i]){
            //         cout<<i<<" "<<x<<endl;
            //     }
            //     cout<<endl;
            // }
            for(int i=0;i<=n;i++){
                if(cycleDfs(i,graph,state,ans2)){
                    // cout<<ans2[0]<<" "<<ans2[1]<<endl;
                    // cout<<"ex"<<endl;
                    isCycle=1;
                }
            }
            if(!isCycle){
                    ans.clear();
                    ans=edge2;
            }
        }else{
            for(int j=n-1;j>=0;j--){
                int u=edges[j][0];
                int v=edges[j][1];
                state.assign(n+1,0);
                //  int l=edge1[0];
                for(int i=0;i<graph[u].size();i++){
                    if(graph[u][i]==v){graph[u].erase(graph[u].begin()+i);}
                }
           
            int isCycle=0;
            for(int i=0;i<=n;i++){
                if(cycleDfs(i,graph,state,ans2)){
                   isCycle=1; 
                }
            }
            if(!isCycle){
                    ans={u,v};
                    break;
            }
            graph[u].push_back(v);
            }
        }
        return ans;
    }
};