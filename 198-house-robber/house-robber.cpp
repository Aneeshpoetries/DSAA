class Solution {
public:
    int rob(vector<int>& nums) {
        int prev=0;
        int prev2=0;
        for(int i=0;i<nums.size();i++){
            int curr=max(prev,nums[i]+prev2);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};