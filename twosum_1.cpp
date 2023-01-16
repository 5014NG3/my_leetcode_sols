class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> res;
        std::map<int,int> table;
        int check_val = 0;

        for (int i = 0; i < nums.size(); i++){

            check_val = nums[i];

            if (table.count(check_val) != 0) {
                res.push_back(table[check_val]);
                res.push_back(i);
                return res;
            }

            else{
                table.insert ( std::pair<int,int>(target - nums[i],i) );


            }

        }
        return res;
    }
};