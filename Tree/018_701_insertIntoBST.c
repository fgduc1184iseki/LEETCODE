/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void insert(struct TreeNode *root, int val)
{
    if (root->val > val)
    {
        if (root->left == NULL)
        {
            struct TreeNode *temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            temp->right = NULL;
            temp->left = NULL;
            temp->val = val;
            root->left = temp;
        }
        else
        {
            insert(root->left, val);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            struct TreeNode *temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            temp->right = NULL;
            temp->left = NULL;
            temp->val = val;
            root->right = temp;
        }
        else
        insert(root->right,val);
    }
};

struct TreeNode *insertIntoBST(struct TreeNode *root, int val)
{
    if(root==NULL)
    {
        struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    insert(root,val);
    return root;
}