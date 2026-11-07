class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m=servers.size();
        int n=tasks.size();
        vector<int>ans(n);
        set<pair<int,int>>free;
        set<tuple<long long,long long,long long>>busy;
        for(int i=0;i<m;i++){
            free.insert({servers[i],i});
        }
        long long curr=0;
        for(int i=0;i<n;i++){
            curr=max(curr,(long long)i);
            if(free.empty() && !busy.empty()){
            auto [t,wt,idx]=*busy.begin();
                curr=max(curr,t);
            }
            if(!busy.empty()){
                while(true){
                    if(!busy.empty()){
                        auto [t,wt,idx]=*busy.begin();
                            if(t<=curr){
                                free.insert({wt,idx});
                                // cout<<wt<<" "<<idx<<endl;
                               
                                busy.erase(*busy.begin());
                            }else{
                                break;
                            }
                        }else{
                            break;
                        }
                }
            }
            
            auto [ser,j]=*free.begin();

            // cout<<j<<" " << ser<<" "<<endl;
                                // cout<<*free.begin()<<endl;

            ans[i]=j;
            busy.insert({curr+tasks[i],ser,j});
            free.erase(*free.begin());
        }
        return ans;
    }
};