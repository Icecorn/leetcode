#include <iostream>
#include "生成二叉树.cpp"


//DFS
int rootSum(TreeNode* root,int targetSum)
{
    if(!root) return 0;
    int res = 0;
    if(root->val == targetSum) res++;

    res += rootSum(root->left,targetSum-root->val);
    res += rootSum(root->right,targetSum-root->val);

    return res;

}
int pathSum(TreeNode* root,int targetSum)
{
    if(!root) return 0;
    int res = rootSum(root,targetSum);
    res += pathSum(root->left,targetSum);
    res += pathSum(root->right,targetSum);
    return res;
}

int main()
{
    int root[] = {10,5,-3,3,2,0,11,3,-2,0,1};
    vector<int> val(root,root+11);
    int targetSum = 8;

    TreeMethod mytree;
    mytree.CreateTree(val);
    mytree.preOrder();

    cout << pathSum(mytree.root,targetSum)<<endl;
    
    return 0;
}