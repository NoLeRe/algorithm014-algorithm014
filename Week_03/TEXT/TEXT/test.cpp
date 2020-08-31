
//二叉树的最近公共祖先
typedef struct TreeNode TreeNode;
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

	if (p == root || q == root)
		return root;
	if (root == NULL)
		return NULL;

	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);

	if (left&&right)
		return root;
	if (left)
		return left;
	else
		return right;
}

//从前序与中序遍历序列构造二叉树
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

	int n = preorder.size();
	if (n == 0)
		return NULL;
	TreeNode* root = new TreeNode(preorder[0]);

	vector<int> left_pre, left_ino, right_pre, right_ino;
	int i;
	for (i = 0; i<n; i++)
	{
		if (inorder[i] == preorder[0])
			break;
		left_ino.push_back(inorder[i]);
	}
	for (i = i + 1; i<n; i++)
	{
		right_ino.push_back(inorder[i]);
	}
	for (int j = 1; j<n; j++)
	{
		if (j <= left_ino.size())
			left_pre.push_back(preorder[j]);
		else
			right_pre.push_back(preorder[j]);
	}
	root->left = buildTree(left_pre, left_ino);
	root->right = buildTree(right_pre, right_ino);
	return root;
}

//组合
vector<vector<int>> combine(int n, int k) {
	vector<int> curr(k);
	std::iota(curr.begin(), curr.end(), 1); // 初始化序列.
	vector<vector<int>> res;
	res.push_back(curr);   // 把初始序列放进去
	// 开始循环计算下一个序列
	int curr_idx = k - 1;
	while (curr_idx >= 0) {
		// 第k个值的最大值是n,那么第k-1个值最大值就应该是n-1, 所以当前要比较的是当前位置的最大值.
		if (curr[curr_idx] < n - (k - 1 - curr_idx)) {
			// 如果当前指向的值可以加1,那么直接增加.
			++curr[curr_idx];
			if (curr_idx < k - 1) {    // 如果当前增加的位不是末尾, 那么需要重置后续的位.
				int next_idx = curr_idx + 1;
				while (next_idx < k) {
					curr[next_idx] = curr[next_idx - 1] + 1;
					++next_idx;
				}
				curr_idx = k - 1;     // 然后把当前指向的位修改为最后一位.
			}
			res.push_back(curr);
		}
		else {
			// 如果小于当前位置的最大值,那么就需要向前找一位,所以把当前指向的位前移.
			--curr_idx;
		}
	}
	return res;
}

//全排列
vector<vector<int>> ret;
vector<vector<int>> permute(vector<int>& nums) {
	vector<bool> exist(nums.size(), true);
	vector<int> track;
	dfs(nums, exist, track);

	return ret;
}
void dfs(vector<int>& nums, vector<bool>& exist, vector<int>& track)
{
	if (track.size() == nums.size())
	{
		ret.push_back(track);
		return;
	}

	for (int i = 0; i<nums.size(); i++)
	{
		if (exist[i])
		{
			track.push_back(nums[i]);
			exist[i] = false;
			dfs(nums, exist, track);
			exist[i] = true;
			track.pop_back();
		}
	}
}

//全排列 II
bool nextPermutation(vector<int>& nums) {
	auto i = is_sorted_until(nums.rbegin(), nums.rend()); // 找到末尾的一个降序段[s]及其前一个元素i
	bool has_next = i != nums.rend();
	if (has_next) {
		iter_swap(i, upper_bound(nums.rbegin(), i, *i));  // 找到[s]中比i大的数中最小的
		reverse(nums.rbegin(), i);                        // 序列反转
	}
	return has_next;
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());
	result.push_back(nums);
	while (nextPermutation(nums)) {
		result.push_back(nums);
	}
	return result;
}