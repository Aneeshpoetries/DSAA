class Solution {
public:
    void merge(vector<int>& nums, int l, int r, int mid, int& cnt){
        vector<int> temp;
        int j=mid+1;
        for(int i=l;i<=mid;i++){
            while(j<=r&&nums[i]>2LL*nums[j]){
                j++;
            }
            cnt+=j-(mid+1);
        }
        int left=l;
        int right=mid+1;
        while(left<=mid&&right<=r){
            if(nums[left]>nums[right]){
                temp.push_back(nums[right]);
                right++;
            }
            else{
                temp.push_back(nums[left]);
                left++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=r){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=l;i<=r;i++){
            nums[i]=temp[i-l];
        }
    }
    void mergeSort(vector<int>& nums, int l, int r, int& cnt){
        int mid=l+(r-l)/2;
        if(l>=r)return;
        mergeSort(nums,l,mid,cnt);
        mergeSort(nums,mid+1,r,cnt);
        merge(nums,l,r,mid,cnt);
    }
    int reversePairs(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int cnt=0;
        mergeSort(nums,l,r,cnt);
        return cnt;
    }
};