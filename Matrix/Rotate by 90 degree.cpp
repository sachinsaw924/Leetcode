
// Time Complexity O(n*n)
// Space Complexity O(n*n)
// ye to me khud banaya hu 
void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    int m = mat.size();
    int n = mat[0].size();
     vector<vector<int>>matrix(m,vector<int>(n,0));
      for(int i = 0 ;i<m;i++)
    {
        for(int j=0 ;j<n;j++)
        {
            matrix[i][j] = mat[i][j];
        }
         
    }
    
    int i = 0 ; 
    int k = 0 ;
    
    while(i<m && k<m)
    {
        for(int j = m-1 , l= 0;j>=0 && l<n ;j--,l++)
        {
           mat[k][l]  =  matrix[j][i];
        }
        k++;
        i++;
        
    }
    
}






// Time complexity O(n*n)
// space complexity O(1)


void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    
    int n = mat.size();
    
    for(int i = 0 ; i <n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            swap(mat[i][j],mat[j][i]);
        }
    }
    
    
    for(int i = 0 ;i<n;i++)
    {
        reverse(mat[i].begin(),mat[i].end());
    }
}
