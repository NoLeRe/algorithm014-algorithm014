#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//删除排序数组中的重复项（Facebook、字节跳动、微软在半年内面试中考过）
int removeDuplicates(vector<int>& nums) {
	if (nums.size()<2)
		return nums.size();

	int j = 0;
	for (int i = 1; i<nums.size(); i++)
	{
		if (nums[i] != nums[j])
		{
			nums[++j] = nums[i];
		}
	}
	return j + 1;
}
//旋转数组（微软、亚马逊、PayPal 在半年内面试中考过）
void rotate(vector<int>& nums, int k) {

	k %= nums.size();
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin() + k);
	reverse(nums.begin() + k, nums.end());
}
//合并两个有序链表（亚马逊、字节跳动在半年内面试常考）
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* head = new ListNode;
	ListNode* cur = head;
	while (l1&&l2)
	{
		if (l1->val <= l2->val)
		{
			ListNode* node = new ListNode(l1->val);
			cur->next = node;
			l1 = l1->next;
			cur = cur->next;
		}
		else
		{
			ListNode* node = new ListNode(l2->val);
			cur->next = node;
			l2 = l2->next;
			cur = cur->next;
		}
	}
	if (l1)
		cur->next = l1;
	else if (l2)
		cur->next = l2;
	else
		cur->next = nullptr;
	return head->next;
}
//合并两个有序数组（Facebook 在半年内面试常考）
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int pos = m;
	int i = 0;
	while (i<nums2.size())
	{
		nums1[pos++] = nums2[i++];
	}
	sort(nums1.begin(), nums1.end());
}
//两数之和（亚马逊、字节跳动、谷歌、Facebook、苹果、微软在半年内面试中高频常考）
vector<int> twoSum(vector<int>& nums, int target) {

	vector<int> ret;
	unordered_map<int, int> mp;
	for (int i = 0; i<nums.size(); i++)
	{
		auto it = mp.find(target - nums[i]);
		if (it != mp.end())
		{
			ret.push_back(i);
			ret.push_back(it->second);
			return ret;
		}
		mp.emplace(nums[i], i);
	}
	return ret;
}
//移动零（Facebook、亚马逊、苹果在半年内面试中考过）
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
//加一（谷歌、字节跳动、Facebook 在半年内面试中考过）
vector<int> plusOne(vector<int>& digits) {

	digits[digits.size() - 1]++;
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (digits[i] == 10)
			digits[i] = 0;
		else
			return digits;
		if (i == 0)
			digits.insert(digits.begin(), 1);
		else
			digits[i - 1]++;
	}
	return digits;
}