int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int m = A.size() ; 
    if(m==1) return A[0][0] ; 
    int dp[m] ; 
    for(int i =0;i<m;i++){
        dp[i] = A[m-1][i] ; 
    }
    for(int j =m-2;j>=0;j--){
        for(int i=0;i<A[j].size();i++){
            dp[i] = min(dp[i],dp[i+1])+A[j][i] ; 
        }
    }
    return dp[0] ; 
    
}
