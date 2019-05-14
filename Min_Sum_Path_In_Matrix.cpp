int Solution::minPathSum(vector<vector<int> > &A) {
    int m = A.size()  ;
    int n = A[0].size() ; 
    if(m==1&&n==1) return A[0][0] ; 
    if(m==1){
        int sum = A[0][0] ; 
        for(int i=1;i<A[0].size();i++){
            sum = sum+A[0][i] ; 
        }
        return sum ; 
    }
    
    
    int dp[m+1][n+1] ;
    for(int i = 0 ;i<m;i++){
        for(int j =0;j<m;j++){
            dp[i][j] = 0 ; 
        }
    }
    for(int i=1;i<=m;i++){
        dp[i][1] = dp[i-1][1]+A[i-1][0] ; 
    }
    for(int i=2;i<=n;i++){
        dp[1][i] = dp[1][i-1]+A[0][i-1] ; 
    }
    for(int i=2;i<=m;i++){
        for(int j =2;j<=n;j++){
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + A[i-1][j-1] ; 
        }
    }
    
    return dp[m][n] ; 
    
}
