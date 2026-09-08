class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        multiset<int>st;
        for(auto x:stones){
            st.insert(x);
        }

        while(st.size()>1){
            int maxi=*st.rbegin();
            st.erase(prev(st.end()));
            int Smaxi=0;
            if(!st.empty()){
                Smaxi=*st.rbegin();
             st.erase(prev(st.end()));
            }else{
                break;
            }

            if(maxi!=Smaxi){
                st.insert(maxi-Smaxi);
            }
        }
        if(st.size()==1){
            return *st.begin();
        }
        return 0;
    }
};