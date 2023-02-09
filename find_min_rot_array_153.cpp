class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;


        while(start < end){

            //if array is rotated n times
            //then the array is in its
            //original state, only case
            //when first element is first value(min)
            //and last value is the last value(max)
            if(nums[start] < nums[end]){
                return nums[start];
            }

            int mid = (start+end)/2;

            //if value of element in mid
            //is > than first element, know 
            //rotation is in the 2nd half of array

            if(nums[mid] >= nums[start]){

                start = mid + 1;

            }
            
            //rotation in the first half
            else{
                end = mid;
            }


        }


        return nums[start];    
    }


};