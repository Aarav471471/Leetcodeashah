class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // multiset<int>st;
        int ans=0;
        unordered_map<int,int>freq;
        for(auto x:digits){
            freq[x]++;
        }

        for(int i=100;i<=998;i+=2){
            int x1=i;
            int flag=1;
            unordered_map<int,int>temp;
            while(x1>0){
                int d=x1%10;
                temp[d]++;
                x1/=10;
            }
            for(auto x:temp){
                if(freq.count(x.first)){
                    if(freq[x.first]<x.second){
                        flag=0;
                    }
                }else{
                    flag=0;
                }
            }
            if(flag){ans++;}
        }
        return ans;
    }
};