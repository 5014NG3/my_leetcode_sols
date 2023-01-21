class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        //if trailing value is negative then it
        //it should be included in the sum and the 
        //starting value should be reset to the value
        //of the current index we are standing on

        int running_total = nums[0];
        int max = running_total;

        for(int i = 1; i < nums.size(); i++){
            
            //if the running total is less than the current
            //value then reset the sum to be that value
            if(running_total + nums[i] < nums[i] ){
                running_total = nums[i];
                if(running_total > max){
                    max = running_total;
                }
            }

            //keep adding to the running total
            else{
                running_total += nums[i];
                if(running_total > max){
                    max = running_total;
                }
            }



        }


        return max;




        
    }
};