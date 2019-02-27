/***************************************************
        Problem: Majority Element
        Solution: Use a hash table to record the number of occurrences of a number
        Date: 2019-2-27 10:27
***************************************************/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>record;
        int l = nums.size();
        for(int i=0;i<l;i++){
            if(record.find(nums[i])!=record.end()){
                record[nums[i]]++;
            }
            else{
                record[nums[i]]=1;
            }
            if(record[nums[i]]> l/2){
                return nums[i];
            }
        }
        return -1;
    }
};
