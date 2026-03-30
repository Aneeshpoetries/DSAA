class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        string res="";
        int n=num.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top()-'0'>num[i]-'0'){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0&&!st.empty()){
            st.pop();
            k--;
        }
        if(st.empty()) return"0";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        int i=0;
        for(i=0;i<res.size();i++){
            if(res[i]!='0')break;
        }
        res=res.substr(i);
       return res.empty() ? "0" : res;
    }
};