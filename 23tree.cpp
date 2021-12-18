#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
    int *keys;
    TreeNode **child;
    int n;
    bool leaf;

public:
    TreeNode(bool leaf);
    void traverse();
    int findKey(int k);
    void insertNonFull(int k);
    void splitChild(int i, TreeNode *y);
    friend class Tree;
};

class Tree
{
    TreeNode *root = NULL;

public:
    /*Tree(){
        root = NULL;
    }*/
    void traverse()
    {
        if (root != NULL)
            root->traverse();
    }
    void insert(int k);
    void remove(int k);
};

TreeNode::TreeNode(bool leaf1)
{
    leaf = leaf1;
    keys = new int[3];
    child = new TreeNode *[4];
    n = 0;
}

void Tree::insert(int k)
{
    if (root == NULL)
    {
        root = new TreeNode(true);
        root->keys[0] = k;
        root->n = 1;
    }
    else
    {
        if (root->n == 3)
        {
            TreeNode *s = new TreeNode(false);
            s->child[0] = root;
            s->splitChild(0, root);
            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->child[i]->insertNonFull(k);
            root = s;
        }
        else
            root->insertNonFull(k);
    }
}

void TreeNode::insertNonFull(int k)
{
    int i = n - 1;
    if (leaf == true)
    {
        while (i >= 0 && keys[i] > k)
        {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        n = n + 1;
    }
    else
    {
        while (i >= 0 && keys[i] > k)
            i--;
        if (child[i + 1]->n == 3)
        {
            splitChild(i + 1, child[i + 1]);
            if (keys[i + 1] < k)
                i++;
        }
        child[i + 1]->insertNonFull(k);
    }
}

void TreeNode::splitChild(int i, TreeNode *y)
{
    TreeNode *z = new TreeNode(y->leaf);
    z->n = 1;
    z->keys[0] = y->keys[2];
    if (y->leaf == false)
    {
        for (int j = 0; j < 2; j++)
            z->child[j] = y->child[j + 2];
    }
    y->n = 1;
    for (int j = n; j >= i + 1; j--)
        child[j + 1] = child[j];
    child[i + 1] = z;
    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[1];

    n = n + 1;
}

void TreeNode::traverse()
{
    cout << endl;
    int i;
    for (i = 0; i < n; i++)
    {
        if (leaf == false)
            child[i]->traverse();
        cout << " " << keys[i];
    }
    if (leaf == false)
        child[i]->traverse();

    cout << endl;
}
int main()
{
    Tree t;
    int n, k;
    cout << "Enter the no. of elements" << endl;
    cin >> n;
    cout << "Enter the keys" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        t.insert(k);
    }
    cout << "Traversal of tree constructed is\n";
    t.traverse();
    cout << "ENter a key to exit."<<endl;
    string temp;
    cin >> temp;
    return 0;
}
