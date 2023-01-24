class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {


    


    vector<vector<int>> res;


    for(int i = 0; i < intervals.size(); i++){

        if(intervals[i][1] < newInterval[0]){
            //if the end of the current interval is 
            //less than the start of the new interval
            //then we add it to the result
            //this interval doesn't intersect with the new interval
            res.push_back(intervals[i]);
        }
        else if(intervals[i][0] > newInterval[1]){
            //if the start of the current interval
            //is greater than the end of the new interval
            //then we add the new interval to result

            //this means that the new interval is before the current
            //interval

            res.push_back(newInterval);

            //make the new interval the current interval
            //to perform any necessary interval merging
            newInterval = intervals[i];
        }

        //the new interval is in range of interval
        else {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);

        }

    }


    //add the merged interval to the results
    res.push_back(newInterval);




    return res;
        
    }
};