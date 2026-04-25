class Solution {
public:
    int uniquePaths(int m, int n) {
        int x=m+n-2;
        int a=ncr(x,m-1);
        return(int)a;

    }
    int ncr(int x, int m){
        long long ans=1;
        for(int i=1;i<=m;i++){
            ans=ans*(x-m+i)/i;
        }
        return (int)ans;
    }
};