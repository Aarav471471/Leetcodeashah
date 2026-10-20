class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        for(auto x:s){
            if(x==']'){
                string inn="";
                cout<<st.top()<<endl;
                // st.pop();
                while(st.top()!='['){
                    // cout<<st.top()<<endl;
                    inn+=st.top();
                    st.pop();
                }
                // cout<<inn<<endl;
                reverse(inn.begin(),inn.end());
                st.pop();
                int num=0;
                int mul=1;

                while(!st.empty()&&isdigit(st.top())){
                    int d=st.top()-'0';
                    num+=d*mul;
                    mul*=10;
                    st.pop();
                }
                // st.pop();
                cout<<num<<endl;
                string temp=inn;
                for(int i=1;i<num;i++){
                    inn+=temp;
                }
                // cout<<inn<<endl;
                for(auto c:inn){
                    st.push(c);
                }
            }else{
                st.push(x);
                // cout<<st.top()<<endl;
            }
        }
        string finall="";
        while(!st.empty()){
            finall+=st.top();
            st.pop();
        }
        reverse(finall.begin(),finall.end());
        return finall;
    }
};