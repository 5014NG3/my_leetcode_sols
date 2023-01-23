class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();

        int i  = 0;

        for(int reach = 0; i < n && i <= reach; i++){
            //reach - is to see how far we can currently
            //reach check if the value we are looking
            //at is within our grasp via jumping

            //keep incrementing i to see how 
            //far we can truly reach

            //then we check I against reach to see 
            //if it is possible to reach a value
            

            //reach set a bound to see how far we can
            // increment to, and if we reach a point
            //that is greater than the current reach
            //that means we can't reach the end
            //since the current i + nums[i] wasn't greater than 
            //the reach 

            //essentially i am hoping I find a 
            //value greater than the current
            //reach so I can  keep on traversing
            //else break out of the loop

            //[2,3,1,1,4], reach_1 = 0 + nums[0] = 2, reach_2 = 1 + nums[1] = 1 + 3 = 4, at this point reach = n-1 
            reach = max(i + nums[i], reach);
        }


        //lastly check the index of the 
        //the last index we visited 
        //and see if it is equal to n;
        //we were able to visit every value
        //without experiencing any setbacks
        //by the reach 


        return i == n;


        
    }
};