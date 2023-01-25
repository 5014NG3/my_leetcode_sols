class Solution {
public:
    int climbStairs(int n) {


        //just count how many way you
        //can get to the first step, and the second step
        // and the rest of the values are derived by 
        //summing the previous two values from the 
        //current step


        if(n == 1){
            return 1;
        }

        if(n == 2){
            return 2;
        }

        int prev_step = 1;
        int cur_step = 2;
        int temp;

        for(int i = 3; i < n; i ++){
            temp = cur_step;
            cur_step = temp + prev_step;
            prev_step = temp;

        }


        return prev_step + cur_step;


        
    }
};