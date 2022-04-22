/*
如果cur无左孩子，cur向右移动(cur = cur->right)
如果cur有左孩子，找到cur左子树上最右节点，记为mostRight
    如果mostRight的right指针指向NULL，让其指向cur，cur向左移动(cur = cur->left)
    如果mostRight的right指针指向cur，让其指向NULL，cur向右移动(cur = cur->right)
*/
void MorrisTraversal(TreeNode *root)
{
    if (!root)
        return;
    TreeNode *cur = root;
    TreeNode *mostRight = nullptr;
    while (cur)
    {
        mostRight = cur->left;
        if (mostRight)
        {
            // cur有左子树，找cur节点的左子树上的最右子节点
            while (mostRight->right && mostRight->right != cur)
            {
                mostRight = mostRight->right;
            }
            if (mostRight->right == nullptr)
            {
                // mostRight->right指向cur，第一次来到cur
                mostRight->right = cur;
                cur = cur->left;
                continue;
            }
            else
            {
                // 第二次来到cur，还愿mostRight->right指向NULL
                mostRight->right = nullptr;
            }
        }
        // cur无左子树，右移；第二次来到cur，右移
        cur = cur->right;
    }
}

// Morris Preorder Traversal
/*
只会遍历一次的节点直接打印
遍历两次的节点，第一次的时候打印，第二次不打印
*/
void PreMorris(TreeNode *root)
{
    if (!root)
        return;
    TreeNode *cur = root;
    TreeNode *mostRight = nullptr;
    while (cur)
    {
        mostRight = cur->left;
        if (mostRight)
        {
            // cur有左子树，找cur节点的左子树上的最优子节点
            while (mostRight->right && mostRight->right != cur)
            {
                mostRight = mostRight->right;
            }
            if (mostRight->right == nullptr)
            {
                // 第一次来到cur，打印cur
                cout << cur->val << " ";
                mostRight->right = cur;
                cur = cur->left;
                continue;
            }
            else
            {
                // 第二次来到cur，mostRight->right进行还原，cur不打印
                mostRight->right = nullptr;
            }
        }
        else
        {
            // cur节点没有左子树，直接打印
            cout << cur->val << " ";
        }
        // cur无左子树，右移；第二次来到cur，右移
        cur = cur->right;
    }
}

// Morris Inorder Traversal
/*
只会遍历一次的节点直接打印
遍历两次的节点，第一次的时候不打印，第二次打印
*/
void InMorris(TreeNode *root)
{
    if (!root)
        return;
    TreeNode *cur = root;
    TreeNode *mostRight = nullptr;
    while (cur)
    {
        mostRight = cur->left;
        if (mostRight)
        {
            // cur有左子树，找cur节点的左子树上的最右子节点
            while (mostRight->right && mostRight->right != cur)
            {
                mostRight = mostRight->right;
            }
            if (mostRight->right == nullptr)
            {
                // 第一次来到cur，不打印cur
                mostRight->right = cur;
                cur = cur->left;
                continue;
            }
            else
            {
                // 第二次来到cur，还原mostRight->right = nullptr
                mostRight->right = nullptr;
            }
        }
        // cur无左子树，直接打印；遍历两次的节点，第二次打印
        cout << cur->val << " ";
        // cur无左子树，右移；第二次来到cur，右移
        cur = cur->right;
    }
}

// Morris Postorder Traversal
/*
1. 每个节点第一次被遍历到的时候不打印
2. 每个节点第二次被遍历到的时候，逆序打印该节点的左子树的右边界
3. 逆序打印整棵树的右边界
*/
void PostMorris(TreeNode *root)
{
    if (!root)
        return;
    TreeNode *cur = root;
    TreeNode *mostRight = nullptr;
    while (cur)
    {
        mostRight = cur->left;
        if (mostRight)
        {
            while (mostRight->right * *mostRight->right != cur)
            {
                mostRight = mostRight->right;
            }
            if (mostRight->right == nullptr)
            {
                mostRight->right = cur;
                cur = cur->left;
                continue;
            }
            else
            {
                mostRight->right = nullptr;
                printRightEdge(cur->left);
            }
        }
        cur = cur->right;
    }
    printRightEdge(root);
}
// 逆序打印以node为根节点的二叉树的右边界
void printRightEdge(TreeNode *node)
{
    TreeNode *tail = reverseRightEdge(node);
    TreeNode *cur = tail;
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->right;
    }
    // 逆序之后进行还原
    reverseRightEdge(tail);
}
// 逆序右边界 和单向链表的逆序一样
TreeNode *reverseRightEdge(TreeNode *node)
{
    TreeNode *pre = nullptr;
    TreeNode *next = nullptr;
    while (node)
    {
        next = node->right;
        node->right = pre;
        pre = node;
        node = next;
    }
    return pre;
}