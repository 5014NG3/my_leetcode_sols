class Solution {
public:
    int uniquePaths(int m, int n) {


        //diagram for test case, m = 3, n = 7
        //the number correlate to the amount
        //of ways you can reach a tile
        //calculate the paths count based the value above
        //and to the left of the current tile
        /*
        0  1  1  1  1  1  1
        1  2  3  4  5  6  7
        1  3  6  10 15 21 28
        */
        int vector[m][n];

        // Fill vector with zeroes
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if(i == 0 || j == 0){
                    //if 
                    vector[i][j] = 1;

                }
                else{
                    vector[i][j] = vector[i-1][j] + vector[i][j-1];
                }


                
            }
        }


        return vector[m-1][n-1];
            
    }
};