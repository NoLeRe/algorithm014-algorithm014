
//�������������������
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

//��ǰ��������������й��������
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

//���
vector<vector<int>> combine(int n, int k) {
	vector<int> curr(k);
	std::iota(curr.begin(), curr.end(), 1); // ��ʼ������.
	vector<vector<int>> res;
	res.push_back(curr);   // �ѳ�ʼ���зŽ�ȥ
	// ��ʼѭ��������һ������
	int curr_idx = k - 1;
	while (curr_idx >= 0) {
		// ��k��ֵ�����ֵ��n,��ô��k-1��ֵ���ֵ��Ӧ����n-1, ���Ե�ǰҪ�Ƚϵ��ǵ�ǰλ�õ����ֵ.
		if (curr[curr_idx] < n - (k - 1 - curr_idx)) {
			// �����ǰָ���ֵ���Լ�1,��ôֱ������.
			++curr[curr_idx];
			if (curr_idx < k - 1) {    // �����ǰ���ӵ�λ����ĩβ, ��ô��Ҫ���ú�����λ.
				int next_idx = curr_idx + 1;
				while (next_idx < k) {
					curr[next_idx] = curr[next_idx - 1] + 1;
					++next_idx;
				}
				curr_idx = k - 1;     // Ȼ��ѵ�ǰָ���λ�޸�Ϊ���һλ.
			}
			res.push_back(curr);
		}
		else {
			// ���С�ڵ�ǰλ�õ����ֵ,��ô����Ҫ��ǰ��һλ,���԰ѵ�ǰָ���λǰ��.
			--curr_idx;
		}
	}
	return res;
}

//ȫ����
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

//ȫ���� II
bool nextPermutation(vector<int>& nums) {
	auto i = is_sorted_until(nums.rbegin(), nums.rend()); // �ҵ�ĩβ��һ�������[s]����ǰһ��Ԫ��i
	bool has_next = i != nums.rend();
	if (has_next) {
		iter_swap(i, upper_bound(nums.rbegin(), i, *i));  // �ҵ�[s]�б�i���������С��
		reverse(nums.rbegin(), i);                        // ���з�ת
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