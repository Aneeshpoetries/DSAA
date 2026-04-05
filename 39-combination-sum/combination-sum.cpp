class Solution {
public:
    void f(vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& ans, int ind){
        if(target==0) {
            ans.push_back(temp);
            return;
        }
        if(ind>=candidates.size()||target<0)return;
        temp.push_back(candidates[ind]);
        f(candidates,target-candidates[ind],temp,ans,ind);
        temp.pop_back();
        f(candidates,target,temp,ans,ind+1);
        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(candidates,target,temp,ans,0);
        return ans;

    }
};