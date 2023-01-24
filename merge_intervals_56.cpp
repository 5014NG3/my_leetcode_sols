class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {


    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {

        //sort interval based on the starting interval value
        //it isn't necessary to compare based on the last value's
        //of the intervals because we are checking this condition
        //at **

        return a[0] < b[0];

    });


  //clean solution I found

    vector<vector<int>> res = {intervals[0]};

    for(int i = 0; i < intervals.size(); i++){

        //if the start of the current interval 
        //is less than the end of the previous
        //interval, then they are merged
        if(intervals[i][0] <= res.back()[1]){

            //merge by updating the value in the result vector
            //keep the current largest final value between
            //the previous and current interval
            //** checked here
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        else{

            //if the start of the current interval
            //is greater than the end of the previous
            //interval, then we just add the current
            //value to the result and check this 
            //value against the next interval
            res.push_back(intervals[i]);
            

        }





    }







        return res;
    }
};