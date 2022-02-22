// 0代表空节点NULL，树的节点值不能为0
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

class TreeMethod
{

public:
    TreeNode *root;

public:
    void CreateTree(vector<int> &val)
    {

        root = CreateTree(val, 0);
    }

    void preOrder()
    {
        preOrder(root);
        cout << endl;
    }

    TreeMethod() {}
    ~TreeMethod() {}

private:
    TreeNode *CreateTree(vector<int> &val, int index)
    { //传入一个数组来创建二叉树 从index处开始构建数组

        if (val[index] == 0)
            return 0;

        TreeNode *cur = new TreeNode(val[index]);

        int leftNodeNum = 2 * index + 1;
        int rightNodeNum = 2 * index + 2;

        if (leftNodeNum >= val.size())
            cur->left = 0;
        else
            cur->left = CreateTree(val, leftNodeNum);

        if (rightNodeNum >= val.size())
            cur->right = 0;
        else
            cur->right = CreateTree(val, rightNodeNum);

        return cur;
    }

    void preOrder(TreeNode *node)
    {

        if (node != 0)
        {
            cout << node->val << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
};

// int main(){

//     int input[] = {1, 2, 3, 4, 5, 0, 6, 7 };
//     vector<int> val(input,input+8);
//     TreeMethod mytree;
//     mytree.CreateTree(val);
//     mytree.preOrder();
//     cout<< mytree.root->val;

// }
