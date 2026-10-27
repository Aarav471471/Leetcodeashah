class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){return false;}
        string s;
        int temp=x;
        while(temp>0){
            int d=temp%10;
            char c=d+'0';
            s+=c;
            temp/=10;
        }
        // cout<<s<<endl;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=s[n-i-1]){return false;}
        }
        return true;
    }
};