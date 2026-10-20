class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto x:tokens){
            if(x=="+" || x=="-" || x=="*" ||x=="/"){
                int f=st.top();
                st.pop();
                int s=st.top();
                st.pop();

                if(x=="+"){st.push(f+s);}
                if(x=="-"){st.push(s-f);}
                if(x=="*"){st.push(f*s);}
                if(x=="/"){st.push(s/f);}
            }else{
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};