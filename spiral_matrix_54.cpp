class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        
        vector<int> res;
        int left = 0;
        int right = matrix[0].size() - 1;

        int top = 0;
        int bot = matrix.size() - 1;

        while(left <= right & top <= bot){

            //go left
            for(int i = left; i <= right; i++){
                res.push_back(matrix[top][i]);
                

            }
            //this move down 1 since we cleared top row
            top = top + 1;

            //go down
            for(int i = top; i <= bot; i++){

                res.push_back(matrix[i][right]);

            }
            //this move left since we cleared the vertical right now
            right = right - 1;


            //go left
            if(top <= bot){
                for(int i = right; i >= left; i--){

                    res.push_back(matrix[bot][i]);
                }

            }
            //this move up since we cleared the bottom row
            bot = bot - 1;

            
            //go up
            if(left <= right){
                for(int i = bot; i >= top ; i--){

                    res.push_back(matrix[i][left]);
                }

            }
            //this right since we cleared the vertical left row
            left = left + 1;


        }




        return res;



        
    }
};