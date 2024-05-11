/*
  Binary Tree Maximum Path Sum

  A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

  The path sum of a path is the sum of the node's values in the path.

  Given the root of a binary tree, return the maximum path sum of any non-empty path.
 */
#include <algorithm>
using namespace std;

struct TreeNode
{
  int val = 0;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;
  explicit TreeNode(int x = 0, TreeNode *left = nullptr, TreeNode *right = nullptr) : val(x), left(left), right(right) {}
};

int maxGain(TreeNode *root, int &maxSum) {
  if (root == nullptr) {
    return 0;
  }

  int left = max(maxGain(root->left, maxSum), 0);
  int right = max(maxGain(root->right, maxSum), 0);
  int newPrice = root->val + l + r;
  maxSum = max(maxSum, newPrice);
  return root->val + max(left, right);
}

int maxPathSum(TreeNode *root) {
  int maxSum = 0;
  maxGain(root, maxSum);
  return maxSum;
}
