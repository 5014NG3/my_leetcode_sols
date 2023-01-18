class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> res;
        vector<int> comb;

        int length = candidates.size();

        traverse(candidates,comb,0,res,target, length);
        
        return res;

    }


    void traverse(vector<int> candidates, vector<int> comb, int start, vector<vector<int>>& res, int target, int length){

        int sum = std::accumulate(comb.begin(), comb.end(), 0);
        //check the current sum of the combination vector

        if(sum == target){
            res.push_back(comb);
            return;
        }

        if(sum > target){

            return;
        }

        else{

            for (int i = start; i < length; i++){
                //generate combinations here based on the current index
                comb.push_back(candidates[i]);

                //recursively go through combinations
                traverse(candidates,comb,i,res,target,length);

                //pop the most recently added candidate to the combination vector
                comb.pop_back();

            }

        }




    }





};