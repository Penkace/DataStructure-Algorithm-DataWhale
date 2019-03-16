class Solution {
private:
    vector<vector<int>>res;
    vector<bool> used;
    
    //p中已经保存了又index个元素的排列
    //向这个排列的末尾添加第index+1个元素，获得一个有index+1个元素的排列
    void bfs(const vector<int>& nums, int index, vector<int>& temp){
        if(index==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!used[i]){
                temp.push_back(nums[i]);
                used[i] = true;
                bfs(nums,index+1,temp);
                used[i] = false;
                temp.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        if(nums.size()==0) return res;
        used = vector<bool>(nums.size(),false);
        vector<int> temp;
        bfs(nums,0,temp);
        return res;
    }
};
