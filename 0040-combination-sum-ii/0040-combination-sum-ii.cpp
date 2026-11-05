class Solution {
public:
    void ways(int idx,int target,vector<int>&candidates,vector<vector<int>>&fans,vector<int>&ans){
        if(target==0){
            fans.push_back(ans);
            return;
        }else if(idx>candidates.size()||target<0){
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx&&candidates[i]==candidates[i-1]){continue;}
            ans.push_back(candidates[i]);
                ways(i+1,target-candidates[i],candidates,fans,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        // auto last=unique(candidates.begin(),candidates.end());
        // candidates.erase(last,candidates.end());
        vector<vector<int>>fans;
        vector<int>ans;
        // vector<int>vis(51,0);
        ways(0,target,candidates,fans,ans);
        return fans;        
    }
};