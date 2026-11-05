class Solution {
public:

    void ways(int idx,int k,int n,vector<vector<int>>&fans,vector<int>&ans){
        if(n==0){
            if(ans.size()==k){
                fans.push_back(ans);
                return;
            }else{
                return;
            }
        }else if(ans.size()>k || n<0){
            return;
        }
        for(int i=idx;i<=9;i++){
            ans.push_back(i);
            ways(i+1,k,n-i,fans,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>fans;
        vector<int>ans;
        ways(1,k,n,fans,ans);
        return fans;
    }
};