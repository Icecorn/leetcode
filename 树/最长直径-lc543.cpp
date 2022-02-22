//这个题最长直径指的是路径，而不是节点个数，刚好是节点个数-1

#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

int result = 0;

int longest_deepth(TreeNode* root)
{
    if(!root) return 0;
    int l = longest_deepth(root->left);
    int r = longest_deepth(root->right);
    return max(l,r) + 1;
}

int diameterOfBinaryTree(TreeNode* root)
{
    int l = longest_deepth(root->left);
    int r = longest_deepth(root->right);
    result = max(result,l+r);
    return result;
}

int main()
{
    TreeNode* T1 = new TreeNode(1);
    TreeNode* T2 = new TreeNode(2);
    TreeNode* T3 = new TreeNode(3);
    TreeNode* T4 = new TreeNode(4);
    TreeNode* T5 = new TreeNode(5);
    
    T1->left = T2;
    T1->right = T3;
    T2->left = T4;
    T2->right = T5;

    int dia = diameterOfBinaryTree(T1);
    cout<< "最长直径"<< dia <<endl;    

}

