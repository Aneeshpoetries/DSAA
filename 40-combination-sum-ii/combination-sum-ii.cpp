class Solution {
public:
    void f(vector<vector<int>>& ans, vector<int>& candidates, int target,int ind, vector<int>& temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind&&candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target)break;
            temp.push_back(candidates[i]);
            f(ans,candidates,target-candidates[i],i+1,temp);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        f(ans,candidates,target,0,temp);
        return ans;
    }
};