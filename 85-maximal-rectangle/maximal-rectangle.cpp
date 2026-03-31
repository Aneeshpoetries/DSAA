class Solution {
public:
    int histo(vector<int>arr){
        int n=arr.size();
        int res=0;
        stack<int>st;
        int nse=n;
        int pse=-1;
        for(int i=0;i<n;i++){
            while(!st.empty()&& arr[st.top()]>arr[i]){
                int h=arr[st.top()];
                st.pop();
                nse=i;
                pse=st.empty()?-1:st.top();
                res=max(res,h*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int h=arr[st.top()];
            st.pop();
            nse=n;
            pse=st.empty()?-1:st.top();
            res=max(res,h*(nse-pse-1));
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;
        vector<int>heights(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')heights[j]++;
                else heights[j]=0;
            }
            maxArea=max(maxArea,histo(heights));
        }
        return maxArea;
    }
};