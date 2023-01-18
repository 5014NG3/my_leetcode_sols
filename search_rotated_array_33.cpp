class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        int start;


        while(left < right){

            mid = (left + right)/2;

            if(nums[mid] > nums[right]){
                left = mid + 1;
                //smallest value is on the right side

            }
            else{
                right = mid;
                //smallest value is on the left side

            }


        }





        start = left;
        left = 0;
        right = nums.size() - 1;

        if(target >= nums[start]  && target <= nums[right] ){
            //has to be on left side

            left = start;

        }
        else{
            //has to be on the right

            right = start;
        }


        while (left <= right){
            mid = (left + right)/2;

            if(nums[mid] == target){
                return mid;
            }


            else if(nums[mid] < target){
                left = mid + 1;
            }

            else{
                right = mid - 1;
            }
        }

        return -1;








        
    }
};