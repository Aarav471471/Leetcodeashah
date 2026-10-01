class Solution {
public:
    bool isValid(string s) {
        bool b=true;
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('|| s[i]=='{'|| s[i]=='['){
                st.push(s[i]);
            }
            else if(
                s[i]==')'|| s[i]=='}'|| s[i]==']' 
            ){
                if(st.empty()){
                    b=false;
                    break;
                }
                char a = st.top() ;
                if((s[i]==')' && a=='(') || (s[i]=='}' && a=='{') || (s[i]==']' && a=='[')){
                    st.pop();
                }
                else{
                    b=false;
                    break;
                }
            }
        }
        if(b && st.empty()){
            return true;
        }
        return false;
    }
};