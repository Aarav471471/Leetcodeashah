class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n=arrival.size();
        multiset<int>free;
        multiset<pair<int,int>>busy;
        vector<int>freq(k,0);
        for(int i=0;i<k;i++){
            free.insert(i);
        }
        // cout<<"1"<<endl;
        int t=0;
        for(int i=0;i<n;i++){
            t=max(arrival[i],t);
            // auto [fin,id]=*busy.begin();

            while(!busy.empty() && (*busy.begin()).first<=t){
                free.insert((*busy.begin()).second);
                busy.erase(*busy.begin());
            }
            if(!free.empty()){
                auto lb=free.lower_bound(i%k);
                if(lb!=free.end()){
                    busy.insert({load[i]+t,*lb});
                    freq[*lb]++;
                    free.erase(*lb);
                }else{
                    if(!free.empty()){
                        freq[*free.begin()]++;
                        busy.insert({load[i]+t,*free.begin()});
                        free.erase(*free.begin());
                    }
                }
            }
            
        }
        vector<int>ans;
        int mx=*max_element(freq.begin(),freq.end());
        for(int i=0;i<k;i++){
            if(freq[i]==mx){ans.push_back(i);}
        }
        return ans;
    }
};