

// int this question  I had thought about basic approach but i could not get it later I had viewed the solution in which i
// could understand fully 
class Solution {
public:  
   void  markVisited(int row , int column , vector<vector<int>>& grid)
   {

    //up
    for(int i = row-1;i>=0;i--)
    {
        if(grid[i][column] == 2 || grid[i][column] == 3 )
        {
            break;
        }
        grid[i][column] = 1;
    }
    // down 
    for(int i = row+1;i< grid.size();i++)
    {
        if(grid[i][column] == 2 || grid[i][column] == 3 )
        {
            break;
        }
        grid[i][column] = 1;
    }
    // left 
    for(int j = column-1;j>=0 ; j--)
    {
        if(grid[row][j] == 2 || grid[row][j] == 3)
        {
            break;
        }
        grid[row][j] = 1;
    }
    for(int j = column+1;j < grid[0].size() ; j++)
    {
        if(grid[row][j] == 2 || grid[row][j] == 3)
        {
            break;
        }
        grid[row][j] = 1;
    }


   } 

      
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));

        for(auto & vec : guards)
        {
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 2 ;// guards is there 

        }

        for(auto &vec : walls)
        {
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 3 ;// wall is there
        }
   
        for(auto & vec : guards)
        {  int i  =  vec[0];
          int j = vec[1];
          markVisited(i,j,grid);
        }
         


        int count = 0 ;
        for(int  i = 0 ; i < m ;i++)
        {
            for(int j = 0 ; j <  n ;j++)
            {
                if(grid[i][j] == 0 )
                {
                    count++;
                }
            
                
            }
        }

      return count ;
    }
};
