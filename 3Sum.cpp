/******************************************************
       Problem: 3Sum
       Solution: 先用sort从小到大进行排序，之后基于对碰指针的思想，建立头尾两个“哨兵”和一个在头尾两“哨兵”之间的移动“哨兵”；
                 求这三个“哨兵”对应的数的和，如果这个和大于0，则向左移动尾“哨兵”；如何这个和小于0，则向右移动头“哨兵”。
       Date: 2019-2-27 10:05
******************************************************/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int i=0,l=nums.size()-1;
        while(i<l){
            int a=nums[i],j=i+1,k=l;
            while(j<k){
                int b=nums[j],c=nums[k];
                int sum=a+b+c;
                if(sum==0)
                    result.push_back({a,b,c});
                if(sum<=0)
                    while(nums[j]==b&&j<k) j++;
                if(sum>=0)
                    while(nums[k]==c&&j<k) k--;
            }
            while(nums[i]==a&&i<l) i++;
        }
        return result;
    }
};
