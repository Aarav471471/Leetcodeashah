class Solution {
public:
    string simplifyPath(string s) {
        stack<char>st;
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='/'){
                if(cnt==0 || cnt>2){
                    if(!st.empty()){
                        if(st.top()!='/'){
                            st.push('/');
                        }
                    }else{
                        st.push('/');
                    }
                    cnt=0;
                }else if(cnt==1){
                    if(!st.empty()){
                        st.pop();
                    }
                    if(st.top()!='/'){
                        st.push('.');
                        st.push('/');
                    }
                    cnt=0;
                }else if(cnt==2){
                    if(st.size()>0){
                        st.pop();
                    }
                    if(st.size()>0){
                        st.pop();
                    }
                    if(!st.empty() && st.top()=='/'){
                        if(st.size()>1){
                            st.pop();
                            while(!st.empty() && st.top()!='/'){
                            st.pop();
                        }
                    }
                    }else{
                        st.push('.');
                        st.push('.');
                        st.push('/');
                    }
                    
                    cnt=0;
                }
            }else if(s[i]=='.'){
                st.push('.');
              cnt++;
            }else{
                st.push(s[i]);
                cnt=0;
            }
        }
        if(cnt==2){
            if(st.size()>0){
                        st.pop();
                    }
                    if(st.size()>0){
                        st.pop();
                    }
                // cout<<st.top()<<endl;
                    if(!st.empty() && st.top()=='/'){
                         if(st.size()>1){
                            st.pop();
                            while(!st.empty() && st.top()!='/'){
                            st.pop();
                        }
                    }
                    }else{
                        st.push('.');
                        st.push('.');
                        st.push('/');
                    }
                    
                    cnt=0;
                
        }else if(cnt==1){
             if(!st.empty()){
                        st.pop();
                    }
                     if(st.top()!='/'){
                        st.push('.');
                        st.push('/');
                    }
                    cnt=0;
        }
        string ans;
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        if(ans.size()>0&&ans.back()=='/'){
            ans.pop_back();
        }
        if(ans.size()==0){
            ans+='/';
        }
        
         
        return ans;

    }
};