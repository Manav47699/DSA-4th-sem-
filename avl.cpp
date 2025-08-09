#include <iostream>
using namespace std;

class TreeNode {
    public:
        int value;
        TreeNode *left;
        TreeNode *right;
    
    // default constructor
        TreeNode() {
            value = 0;
            left = NULL;
            right = NULL;
        }

    //parameterized constructor
        TreeNode(int v)
        {
            value = v;
            left = NULL;
            right = NULL;
        }
};


class AVLtree 
{
    public:
        TreeNode *root;   
        AVLtree()
        {
            root = NULL;
        }

// Boolen function returns true or false
        bool isTreeEmpty()
        {
            if (root==NULL)
            {
                return true;
            }
            else{
                return false;
            }
        }

//gets the height of left and right subtree recursivley
        int get_height(TreeNode *r)
        {
            if (r == NULL)
            {
                return -1;
            }
            else{
                // calculating height of subtrees
                int lheight = get_height(r->left);
                int rheight = get_height(r->right);

                //using only the longer subnode
                if (lheight > rheight)
                {
                    return (lheight + 1);
                }
                else 
                {
                    return (rheight + 1);
                }
            }
        }
//
        int balance_factor(TreeNode *n)
        {
            if (n == NULL)
            {
                return -1;
            }
            return get_height(n->left) - get_height(n->right);
        }

        TreeNode *right_rotate(TreeNode *y)
        {
            TreeNode *x = y->left;
            TreeNode *T2 = x->right;

            x->right = y;
            y->left = T2;

            return x;
        }
        TreeNode *left_rotate(TreeNode *x)
        {
            TreeNode *y = x->right;
            TreeNode *T2 = y->left;

            y->left = x;
            x->right = T2;

            return y;
        }
        TreeNode *insert(TreeNode *r, TreeNode *new_node)
        {
            if (r == NULL)
            {
                r = new_node;
                cout << "Value inserted successfully" << endl;
                return r;
            }
            if (new_node->value < r->value)
            {
                r->left = insert(r->left, new_node);
            }
            else if(new_node->value > r->value)
            {
                r->right = insert(r->right, new_node);
            }
            else{
                cout << "Duplicate values are invalid" << endl;
                return r;
            }

            int bf = balance_factor(r);

            // LL Case
            if (bf > 1 && new_node->value < r->left->value)
            {
                return right_rotate(r);
            }
            // RR Case
            if (bf < -1 && new_node->value > r->right->value)
            {
                return left_rotate(r);
            }
            // LR Case
            if (bf > 1 && new_node->value > r->left->value)
            {
                r->left = left_rotate(r->left);
                return right_rotate(r);
            }
            // RL Case
            if (bf < -1 && new_node->value < r->right->value)
            {
                r->right = right_rotate(r->right);
                return left_rotate(r);
            }

            return r;
        }
        void insert_value(int v) {
        TreeNode *new_node = new TreeNode(v);
        root = insert(root, new_node);
    }

    // Display in different orders
    void inorder(TreeNode *r) {
        if (r == NULL) return;
        inorder(r->left);
        cout << r->value << " ";
        inorder(r->right);
    }

    void preorder(TreeNode *r) {
        if (r == NULL) return;
        cout << r->value << " ";
        preorder(r->left);
        preorder(r->right);
    }

    void postorder(TreeNode *r) {
        if (r == NULL) return;
        postorder(r->left);
        postorder(r->right);
        cout << r->value << " ";
    }
};

int main() {
    AVLtree avl;

    avl.insert_value(30);
    avl.insert_value(20);
    avl.insert_value(40);
    avl.insert_value(10);
    avl.insert_value(25);
    avl.insert_value(50);

    cout << "\nInorder   : ";
    avl.inorder(avl.root);

    cout << "\nPreorder  : ";
    avl.preorder(avl.root);

    cout << "\nPostorder : ";
    avl.postorder(avl.root);

    cout << endl;
    return 0;
}
