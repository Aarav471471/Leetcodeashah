class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>>ans(m,vector<char>(n,'#'));
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         ans[i][j]='#';
        //     }
        // }
        for(int i=0;i<n;i++){
            ans[0][i]='.';
        }
        for(int i=0;i<m;i++){
            ans[i][n-1]='.';
        }
        vector<string>fans;
        for(int i=0;i<m;i++){
            string s;
            for(int j=0;j<n;j++){
                s+=ans[i][j];
            }
            fans.push_back(s);
        }
        return fans;
    }
};