class Solution {
public:
    int maxProduct(vector<int>& nums) {

        if(nums.size() == 0){
            return 0;
        }

        int maxhere_prev = nums[0];
        int minhere_Prev = nums[0];
        int max_prod = nums[0];
        int maxhere, minhere;

        for(int i = 1; i < nums.size(); i++){

            //need to compare across three values, the min and max prev product with
            //the current value, and the current value which could be the 
            //the start of a new sequence
            
            //maxhere holds the max between the three values
            maxhere = max(max(maxhere_prev*nums[i], minhere_Prev*nums[i]), nums[i]);

            //minhere holds the min between the thre values, this is to account for 
            //negative values that could become positive after being multiplied to 
            //another negative value
            minhere = min(min(maxhere_prev*nums[i], minhere_Prev*nums[i]), nums[i]);

            //look at the maxhere and compare it to the 
            //the max_prod value and choose the max of those two
            max_prod = max(maxhere,max_prod);

            //update the max and minhere prev
            maxhere_prev = maxhere;
            minhere_Prev = minhere;

        }


        return max_prod;








    }
};