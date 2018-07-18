/*
小偷又发现一个新的可行窃的地点。 这个地区只有一个入口，称为“根”。 除了根部之外，每栋房子有且只有一个父房子。 一番侦察之后，聪明的小偷意识到“这个地方的所有房屋形成了一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

在不触动警报的情况下，计算小偷一晚能盗取的最高金额。

示例 1:

     3
    / \
   2   3
    \   \ 
     3   1
能盗取的最高金额 = 3 + 3 + 1 = 7.

示例 2:

     3
    / \
   4   5
  / \   \ 
 1   3   1
能盗取的最高金额 = 4 + 5 = 9.

思路：
对一个节点，可以选择偷或不偷
如果选择偷，那么子节点不能偷，记录两个（或0-1个）子节点不偷时以该节点为根的子树的最大可偷金额（本身值+左子最大金额+右子最大金额）
如果选择不偷，那么两个子节点可偷可不偷，每个子节点各自比较一下偷或者不偷时得到的子树最大值是多少，取较大的一个返回。然后本身记录子节点所构成子树的最大值之和（左子最大金额+右子最大金额）
比较偷该节点和不偷的较大值返回给父节点
根节点的输出值就是结果
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int stealCurrent(TreeNode *root){
        if(root==NULL)return 0;
        //假设偷当前结点，两个孩子结点不能偷，可以直接返回这棵子树的可偷最大值
        int left=root->left!=NULL?notStealCurrent(root->left):0;
        int right=root->right!=NULL?notStealCurrent(root->right):0;
        return root->val+left+right;
    }
    int notStealCurrent(TreeNode *root){
        if(root==NULL)return 0;
        //不偷当前结点，可以偷两个孩子结点（之一或同时），返回这课子树可偷最大值
        //孩子结点是可偷可不偷的，有些情况即使本身不偷，孩子也不偷时收益最大，因为大鱼可能藏在更底下
        //比如：
        /*
            3
          4     5
        4   3 0   1
        这时最大策略是根左子的两个孩子+根右子一共12，而这个时候跟和左子两个连着的都不偷
        */
        int leftS=stealCurrent(root->left);
        int leftNS=notStealCurrent(root->left);
        int rightS=stealCurrent(root->right);
        int rightNS=notStealCurrent(root->right);
        int left=leftS>leftNS?leftS:leftNS;
        int right=rightS>rightNS?rightS:rightNS;
        return left+right;
    }
    int rob(TreeNode* root) {
        int stealRoot=stealCurrent(root);
        int notStealRoot=notStealCurrent(root);
        return stealRoot>notStealRoot?stealRoot:notStealRoot;
    }
};
