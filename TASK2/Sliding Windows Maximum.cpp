/**************************************************************
        References: https://www.jianshu.com/p/641ead99c785
        Idea: 这道题开始的时候以为是求滑动窗口里的最大值，然后一直WA，跑去看了别人的才知道自己理解错了题意，是求滑动窗口中的最大值，弄明白写好提交AC
**************************************************************/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < k-1; i++) 
            pq.push(pair<int,int>(nums[i],i));
        for(int i = k-1; i<nums.size();i++) 
        {
            pq.push(pair<int,int>(nums[i],i));
            pair<int,int> temp = pq.top(); 
            while(temp.second < i-(k-1)) 
            {
                pq.pop();
                temp = pq.top();
            }
            res.push_back(temp.first);
        }
        return res;
    }
};
