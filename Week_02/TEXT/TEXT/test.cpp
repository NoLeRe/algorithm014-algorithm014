#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

//有效的字母异位词
bool isAnagram(string s, string t) {
	if (s.size() != t.size())
		return false;

	int hash[26] = { 0 };
	for (int i = 0; i<s.size(); i++)
	{
		hash[s[i] - 'a']++;
		hash[t[i] - 'a']--;
	}
	for (int i = 0; i<26; i++)
	{
		if (hash[i] != 0)
			return false;
	}
	return true;
}

//N叉树的前序遍历
vector<int> ret;
void dfs(Node* root)
{
	if (root == nullptr)
		return;
	ret.push_back(root->val);
	for (int i = 0; i<root->children.size(); i++)
	{
		dfs(root->children[i]);
	}
}
vector<int> preorder(Node* root) {

	dfs(root);
	return ret;
}

//字母异位词分组
vector<vector<string>> groupAnagrams(vector<string>& strs) {

	vector<vector<string>> ret;
	unordered_map<string, int> hash;

	int pos = 0;
	string tmp;

	for (auto& str : strs)
	{
		tmp = str;
		sort(tmp.begin(), tmp.end());
		if (hash.count(tmp))
		{
			ret[hash[tmp]].push_back(str);
		}
		else
		{
			vector<string> v(1, str);
			ret.push_back(v);
			hash[tmp] = pos++;
		}
	}
	return ret;
}

//二叉树的中序遍历
vector<int> ret;
void inorder(TreeNode* root)
{
	if (root == nullptr)
		return;

	inorder(root->left);
	ret.push_back(root->val);
	inorder(root->right);
}
vector<int> inorderTraversal(TreeNode* root) {

	inorder(root);
	return ret;
}

//二叉树的前序遍历
vector<int> preorderTraversal(TreeNode* root) {

	vector<int> ret;
	stack<TreeNode*> st;

	TreeNode* cur = root;

	while (cur || !st.empty())
	{
		while (cur)
		{
			st.push(cur);
			ret.push_back(cur->val);
			cur = cur->left;
		}
		cur = st.top();
		st.pop();
		cur = cur->right;
	}
	return ret;
}

//N叉树的层序遍历
vector<vector<int>> levelOrder(Node* root) {

	vector<vector<int>> ret;
	if (root == nullptr)
		return ret;

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		vector<int> v;
		int sz = q.size();
		for (int i = 0; i<sz; i++)
		{
			Node* cur = q.front();
			q.pop();
			v.push_back(cur->val);
			for (int j = 0; j<cur->children.size(); j++)
			{
				q.push(cur->children[j]);
			}
		}
		ret.push_back(v);
	}
	return ret;
}

//丑数
int nthUglyNumber(int n) {

	if (n<7)
		return n;
	vector<int> num(n);
	num[0] = 1;

	int index_1 = 0, index_2 = 0, index_3 = 0;

	for (int i = 1; i<n; i++)
	{
		num[i] = min(num[index_1] * 2, min(num[index_2] * 3, num[index_3] * 5));
		if (num[i] == num[index_1] * 2)
			index_1++;
		if (num[i] == num[index_2] * 3)
			index_2++;
		if (num[i] == num[index_3] * 5)
			index_3++;
	}
	return num[n - 1];

}

//前 K 个高频元素
vector<int> topKFrequent(vector<int>& nums, int k) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
	// pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> >
	unordered_map<int, int> hash;
	for (int i = 0; i<nums.size(); i++)
		hash[nums[i]]++;

	auto it = hash.begin();
	while (it != hash.end())
	{
		if (heap.size() == k)
		{
			if (it->second>heap.top().first)
			{
				heap.pop();
				heap.push(make_pair(it->second, it->first));
			}

		}
		else
			heap.push(make_pair(it->second, it->first));
		it++;
	}

	vector<int> ret;
	while (!heap.empty())
	{
		ret.push_back(heap.top().second);
		heap.pop();
	}
	return ret;
}