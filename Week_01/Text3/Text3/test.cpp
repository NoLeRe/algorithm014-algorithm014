#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//盛最多水的容器
int maxArea(vector<int>& height) {

	int begin = 0;
	int end = height.size() - 1;
	int maxret = 0;
	while (begin<end)
	{
		int cur = min(height[begin], height[end])*(end - begin);
		maxret = max(maxret, cur);
		if (height[begin]<height[end])
			begin++;
		else
			end--;
	}
	return maxret;

}
//移动零
void moveZeroes(vector<int>& nums) {

	int j = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		if (nums[i] != 0)
		{
			swap(nums[j], nums[i]);
			j++;
		}
	}
}
//爬楼梯
int climbStairs(int n) {

	int pre = 0;
	int cur = 1;

	int ret;
	for (int i = 0; i<n; i++)
	{
		ret = pre + cur;
		pre = cur;
		cur = ret;
	}
	return ret;
}
//三数之和
vector<vector<int>> threeSum(vector<int>& nums) {

	vector<vector<int>> ret;
	if (nums.size()<3)
		return ret;

	sort(nums.begin(), nums.end());
	for (int i = 0; i<nums.size() - 2; i++)
	{
		if (nums[i]>0)
			break;
		if (i>0 && nums[i] == nums[i - 1])
			continue;
		int left = i + 1, right = nums.size() - 1;
		while (left<right)
		{
			int sum = nums[i] + nums[left] + nums[right];
			if (sum == 0)
			{
				vector<int> tmp = { nums[i], nums[left], nums[right] };
				ret.push_back(tmp);
				left++;
				right--;
				while (left<right&&nums[left] == nums[left - 1])
					left++;
				while (left<right&&nums[right] == nums[right + 1])
					right--;
			}
			if (sum>0)
				right--;
			if (sum<0)
				left++;
		}
	}
	return ret;
}