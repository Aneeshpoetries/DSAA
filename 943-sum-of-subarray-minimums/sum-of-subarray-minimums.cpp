class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int m= 1e9+7;
        long long total=0;
        long long l=0;
        long long r=0;
        int n=arr.size();
        vector<int>pse(n);
        vector<int>nse(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty())pse[i]=-1;
            else{pse[i]=st.top();}
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty())nse[i]=n;
            else nse[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            l=i-pse[i];
            r=nse[i]-i;
            total = (total + arr[i] * (l*r % m) % m) % m;
        }
        return total;
    }
};