class Solution {
public:
    int maxArea(vector<int>& height) {


        const int size = height.size();
        int left = 0;
        int right = size - 1;
        int cur_area;

        //assume max is the end-start * min height between two
        int max = (right - left)*std::min(height[right], height[left]);



        //max sure the left pointer is always smaller than the right
        while(left < right){


            //this is where we are maximizing the distance and the height

            //if the left heigh is greater move the right pointer to the left
            if(height[left] > height[right]){

                right -= 1;

                //calculate area based on new right value
                cur_area = (right - left)*std::min(height[right], height[left]);

                //compare against the previous max value

                max = std::max(max,cur_area);

            }

            //else move the left pointer to the right

            else{
                
                left += 1;

                //calculate rea based on new left value 
                cur_area = (right - left)*std::min(height[right], height[left]);

                max = std::max(max,cur_area);

            }
        }

        return max;
        
    }
};