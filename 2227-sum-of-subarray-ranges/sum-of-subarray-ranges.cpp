class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        long long total=0;
        long long smin=0;
        long long smax=0;
        vector<int>pge(n);
        vector<int>nge(n);
        vector<int>pse(n);
        vector<int>nse(n);
        
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty())pse[i]=-1;
            else{
                pse[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.empty())nse[i]=n;
            else{
                nse[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.empty())pge[i]=-1;
            else{
                pge[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]<nums[i]){
                st.pop();
            }
            if(st.empty())nge[i]=n;
            else{
                nge[i]=st.top();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            smin+=(1LL)*(i-pse[i])*(nse[i]-i)*nums[i];
            smax+=(1LL)*(i-pge[i])*(nge[i]-i)*nums[i];
        }
        total=smax-smin;
        return total;               
    }
};