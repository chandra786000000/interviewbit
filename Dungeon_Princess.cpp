int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int m = A.size() ; 
    int n = A[0].size() ; 
    
    int dp[m][n]  ;
    for(int i=0;i<m;i++){
        for(int j =0;j<n;j++){
            dp[i][j] = 0 ;
        }
    }
    dp[m-1][n-1] = min(0,A[m-1][n-1] ) ; 
    for(int i=m-2;i>=0;i--){
        dp[i][n-1] = min(0,min(A[i][n-1],A[i][n-1]+dp[i+1][n-1])) ;  
    }
    for(int j=n-2;j>=0;j--){
        dp[m-1][j] = min(0,min(A[m-1][j],A[m-1][j]+dp[m-1][j+1])) ; 
    }
    
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            //int best = max(dp[i+1][j],dp[i][j+1]) ; 
            dp[i][j] = min(0,min(A[i][j],(max(dp[i+1][j],dp[i][j+1])+A[i][j]))) ; 
        }
    }
    
    return(abs(dp[0][0])+1) ; 
}
