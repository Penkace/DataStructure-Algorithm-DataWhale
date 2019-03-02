#include<iostream>
#include<vector>
using namespace std;
// res,vis应该作为全局变量，这样就不用作为参数传递 
void bfs(const vector<int> &nums,vector<vector<int> >&res,vector<int>&temp,int k,vector<bool>&vis){
	// 递归终止条件是temp中已经存放了所有数 
	if(k==nums.size()){
		res.push_back(temp);
		return;
	}
	// 递归部分主要是遍历，把没有放入的数字放入到temp并进行下一次递归 
	for(int i=0;i<nums.size();i++){
		if(vis[i]==0){
			temp.push_back(nums[i]);
			vis[i]=1;
			// 画二叉树更好理解 
			bfs(nums,res,temp,k+1,vis);
			// 完成了前面的递归之后，要往上，即返回到前一个状态 
			vis[i]=0;
			temp.pop_back();
		}
	}
	return;
}

int main(){
	vector<vector<int> >res;
	vector<bool> vis;
	int a[] = {1,2,3,4,5};
	vector<int>nums(a,a+5);
	vis = vector<bool>(nums.size(),false);
	vector<int>temp;
	bfs(nums,res,temp,0,vis);
	cout<<"总共有"<<res.size()<<"种排列方式"<<endl;
	// vector类型的标准迭代方式，因为迭代返回的是指针形式，所以要用tmp = *iter 
	for(vector<vector<int> >::iterator iter = res.begin();iter!=res.end();iter++){
		vector<int> tmp = *iter;
		for(vector<int>::iterator it=tmp.begin();it!=tmp.end();it++){
			cout<< *it;
		}	
		cout<<endl;
	}
	return 0;
}
