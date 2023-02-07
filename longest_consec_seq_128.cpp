class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> myset;

        for(auto i: nums){
            myset.insert(i);
        }

        int res = 0;
        

        for(auto val : nums){
            //means we are looking at the first value in
            //a possible consecutive sequence
            if(myset.count(val-1) == 0){
                int cur = val;
                while(myset.count(cur) != 0){

                    cur+=1;
                }

                //check max against the current length
                res = max(res,cur-val);





            }
        }

        return res;
    }
};