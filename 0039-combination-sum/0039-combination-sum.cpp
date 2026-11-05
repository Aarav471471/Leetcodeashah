class Solution {
public:

    int ways(int idx,int target,vector<int>&candidates,vector<vector<int>>&fans,vector<int>&ans){
        if(target==0){
            return 1;
        }else if(target<0){return 0;}
        for(int i=idx;i<candidates.size();i++){
                ans.push_back(candidates[i]);
                if(ways(i,target-candidates[i],candidates,fans,ans)){
                    // sort(ans.begin(),ans.end());
                    fans.push_back(ans);
                }
                if(!ans.empty()){
                        ans.pop_back();
                }
            
        }
        return 0;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(),candidates.end());
        vector<vector<int>>fans;
        vector<int>ans;
        int curr=ways(0,target,candidates,fans,ans);
        return fans;
    }
};