int Solution::solve(vector<vector<int> > &A) {
    int m = A.size() ; 
    int n = A[0].size();
    
    if(m==1&&n==1) return A[0][0] ; 
    if(A[m-1][n-1]<0) return A[m-1][n-1] ; 
    int dp[m+1][n+1] ; 
    for(int i =0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = 0 ; 
        }
    }
    dp[m][n] = A[m-1][n-1] ;
    //dp[0][0] = 0 ;
    //int count = 0 ;
    for(int i =m-1;i>0;i--){
        dp[i][n] = dp[i+1][n] + A[i-1][n-1] ;  
    }
    for(int i =n-1;i>0;i--){
        dp[m][i] = dp[m][i+1] + A[m-1][i-1] ;  
    }
    
    for(int i = m-1;i>0;i--){
        for(int j = n-1;j>0;j--){
            dp[i][j] = dp[i+1][j]+dp[i][j+1]-dp[i+1][j+1]+A[i-1][j-1] ; 
        }
    }
    int max  = INT_MIN ; 
    for(int i =0;i<=m;i++){
        for(int j =0;j<=n;j++){
            if(dp[i][j]>max) max = dp[i][j] ;
           // cout<<dp[i][j]<<" " ; 
        }
        //cout<<endl ; 
    }
    
    
    return max ;
}
