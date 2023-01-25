class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        //add location of zeros to a vector,
        //iterate through vector and use the row,col 
        //pairs to fill in matrix based on these values

        bool zeroRow = false;
        bool zeroCol = false;   



        //fill in these values after we process 
        //the inner zero values
    

        //check if thie first col is zero
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][0] == 0){
                zeroCol = true;
                break;
            }
        }

        //check if the first row is zero
        for(int i = 0; i < matrix[0].size(); i++){
            if(matrix[0][i] == 0){
                zeroRow = true;
                break;
            }
        }     

        
        //check inner values , not first row or col

        //this is where the cross sections are created
        //these zero valuse are going to be filled in the next step
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    //make values on the first column that are
                    //on the same row have value 0
                    matrix[i][0] = 0;

                    //make values on the row column that are
                    //on the same column have value 0 
                    matrix[0][j] = 0;
                }

                
            }

        }


        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                //the first row and col, are cross-section
                //of the way the grid is filled in
                if(matrix[i][0] == 0 || matrix[0][j] == 0){

                    matrix[i][j] = 0;

                }
            }

        }


        //fill in the zero col and here to not lose info
        //in the previous steps
        if(zeroCol){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][0] = 0;
            }
        }

        if(zeroRow){
            for(int i = 0; i < matrix[0].size(); i++){
                matrix[0][i] = 0;
            }
        }








        
    }
};