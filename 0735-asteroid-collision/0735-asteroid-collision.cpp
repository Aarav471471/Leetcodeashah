class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto x:asteroids){
            if(x>0){
                st.push(x);
            }else{
                int isE=0;
                while(st.size()>0&&st.top()>0&&st.top()<=abs(x)){
                    int f=st.top();
                    st.pop();
                    if(f==abs(x)){isE=1;break;}
                }
                // cout<<isE<<endl;
                if((st.empty()|| st.top()<0)&&isE==0){
                    st.push(x);
                }
            }
        }
        asteroids.clear();
        while(!st.empty()){
            asteroids.push_back(st.top());
            st.pop();
        }
        reverse(asteroids.begin(),asteroids.end());
        return asteroids;
    }
};