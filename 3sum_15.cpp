// if have seen number continue

//  if i>0 and num[i] == nums[i-1]	
// 	continue

// int left = i + 1, right = size -1;

// while left < right
// 	sum = nums[i, + left, + right]

// 	if(sum < 0 ) left++
// 	else if (sum >  0) right--;
// 	else 
// 		res.push_back({i,left,right})
// 		int last_left = nums[left]
// 		int last_right = nums[right]

// 		while left < right and nums[left] == last_left , left++
// 		while left < right and nums[right] == last_right , right--




//threeSuum

//std::unordered_map<int,int> m;
//res

//sort(nums)

//assign values to  unordermap m[value] = index

//loop through 0 to n-1

    //we have already looked at this number
    //if i > 0 and nums[i] == nums[i-1] continue;

    //for j = i+1 to n-1
        //if j != i+1 i guess skip the first value and check if nums[j] == nums[j-1] continue


        //this means we already have the value in the map 
        //this is likely due to the nature of three sum requiring
        //negative and positive values
        //if map[-(nums[i] + nums[j]) > j]
            //push to result

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        //reduce 3 sum to two sum 
        //in this case target = 0

        const int size = nums.size();

        std::vector<std::vector<int>> res;

        std::sort(nums.begin(), nums.end());

        int left,right,sum,last_left,last_right;


        for (int i = 0; i < size; i++){

            if(nums[i] > 0){
                break;
            }

            //check if we have already seen the value,
            //since the list is sorted,there may be
            //a repeated value sequence. check if the current 
            //value is equal to the previous value
            if(i > 0 && nums[i-1] == nums[i]){
                continue;
            }

            //make the left pointer be the value immediately
            //after the current target (i) value we are looking
            //at. 

            left = i + 1;
            right = size - 1;


            while(left < right ){

                sum = nums[i] + nums[left] + nums[right];

                if(sum > 0){
                    //sum is too big , go to 
                    //smaller positive number
                    right--;

                }
                else if (sum < 0){
                    //number is too small, got
                    //negative number closer to zero
                    left++;

                }
                else{
                    //sum == 0, push the result
                    res.push_back({nums[i],nums[left],nums[right]});

                    last_left = left;
                    last_right = right;

                    while(left < right && nums[left] == nums[last_left]){

                        //move left to the right until we hit a different value
                        left++;

                    }

                    while(left < right && nums[right] == nums[last_right]){
                        //right to the left until we hit a different value
                        right--;

                    }

                }

                




            }


        }

        return res;

    }



};