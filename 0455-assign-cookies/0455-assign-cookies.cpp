class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        int cnt=0;
        int n=g.size();
        int m=s.size();
        while(i<n && j<m){
            if(s[j]>=g[i]){
                j++;
                i++;
                cnt++;
            }else{
                j++;
            }
        }
        return cnt;
    }
};