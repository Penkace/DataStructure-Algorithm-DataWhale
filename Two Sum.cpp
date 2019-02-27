/*******************************************************
        Problem: Two Sum
        Solution： Using a hash map to improve code performance.
        Date: 2019-2-27 9:41
*******************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> record;
        for(int i=0;i<nums.size();i++){
            int complement=target-nums[i];
            if(record.find(complement)!=record.end()){
                int res[2]={i,record[complement]};
                return vector<int>(res,res+2);
            }
            record[nums[i]]=i;
        }
        throw invalid_argument("the input has no solution");
    }
};
