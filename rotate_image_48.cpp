class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        //optimal solution is to transpose the columns, 
        //and then reverse the order of the rows

        // int n=matrix.size();
        // for (int i=0;i<n;i++)
        // {
        //     for (int j=i;j<n;j++)
        //     {
        //         swap(matrix[i][j],matrix[j][i]);
        //     }
        // }
        // for (int i=0;i<n;i++)
        // {
        //     reverse(matrix[i].begin(),matrix[i].end());
        // }
        
        
        int x = matrix.size() - 1;
        int y = 0;
        
        int currentX = 0;
        int currentY = 0;
        int saveCY = 0;


        //width = n - 1
        
        int width = x;
        

        while (width > 0 ) {

            //width decreases by 2 on each iteration
            //this correlates to the current "square's values that we are rotating"
            
            while(y < width){
                                            
            
                //currentX - row is the same

                //swap cells in the same cycle : 1, 3  , 7 , and 9

                //ex :  1 2 3 
                //      4 5 6
                //      7 8 9


                //y = 0, x = n - 1
                //swap 1 with 3
                //ex :  3 2 1 
                //      4 5 6
                //      7 8 9
                swap(matrix[currentX][currentY], matrix[currentX + y ][currentY+x] );


                //swap 3 with 7
                //ex :  7 2 1 
                //      4 5 6
                //      3 8 9
                swap(matrix[currentX][currentY],matrix[currentX + x][currentY - y ]);

                //swap 3 with 9 
                //ex :  7 2 1 
                //      4 5 6
                //      9 8 3
                swap(matrix[currentX + x][currentY - y ],matrix[currentX + x + y ][currentY - y + x ]);


                    
                    x--;
                    y++;
                    


                    //column is incremented
                    currentY++;
            }


            //decrement with by 2 since we are dealing with a square , 
            //there is padding on both sides


            //this has to do with the pattern I discovered
            //where we just have to look at the first
            //n- 1 values for each square within another
            //n = 4, jsut need to rotate the first three values in
            // a given row or column
            //n = 2 , just need to use one value to rotate all
            //four values

            width -= 2;

            //set the x to be the current width
            x = width;
            y = 0;

            //increment the row we are looking at
            currentX++;

            //increment the current column we are looking at
            saveCY++;

            // we are going down the diagonal of the grid
            //when we increment currentX and current Y(saveCY)

            //keep track of the current column we are looking at
            currentY = saveCY;
            
        
            
            
            
        }
        
        
        
    }
};