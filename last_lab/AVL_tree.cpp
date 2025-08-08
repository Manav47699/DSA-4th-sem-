#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode *leftChild;
    TreeNode *rightChild;
    int height;
};

int maxHeight(int a, int b);

// Calculate height
int getHeight(TreeNode *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int maxHeight(int a, int b) {
    return (a > b) ? a : b;
}

// Create a new node
TreeNode *createNode(int value) {
    TreeNode *newNode = new TreeNode();
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->height = 1;
    return newNode;
}

// Right rotation
TreeNode *rotateRight(TreeNode *y) {
    TreeNode *x = y->leftChild;
    TreeNode *T2 = x->rightChild;

    x->rightChild = y;
    y->leftChild = T2;

    y->height = maxHeight(getHeight(y->leftChild), getHeight(y->rightChild)) + 1;
    x->height = maxHeight(getHeight(x->leftChild), getHeight(x->rightChild)) + 1;

    return x;
}

// Left rotation
TreeNode *rotateLeft(TreeNode *x) {
    TreeNode *y = x->rightChild;
    TreeNode *T2 = y->leftChild;

    y->leftChild = x;
    x->rightChild = T2;

    x->height = maxHeight(getHeight(x->leftChild), getHeight(x->rightChild)) + 1;
    y->height = maxHeight(getHeight(y->leftChild), getHeight(y->rightChild)) + 1;

    return y;
}

// Get balance factor
int getBalance(TreeNode *node) {
    if (node == NULL)
        return 0;
    return getHeight(node->leftChild) - getHeight(node->rightChild);
}

// Insert node
TreeNode *insert(TreeNode *node, int value) {
    if (node == NULL)
        return createNode(value);

    if (value < node->value)
        node->leftChild = insert(node->leftChild, value);
    else if (value > node->value)
        node->rightChild = insert(node->rightChild, value);
    else
        return node;

    node->height = 1 + maxHeight(getHeight(node->leftChild), getHeight(node->rightChild));
    int balance = getBalance(node);

    if (balance > 1 && value < node->leftChild->value)
        return rotateRight(node);

    if (balance < -1 && value > node->rightChild->value)
        return rotateLeft(node);

    if (balance > 1 && value > node->leftChild->value) {
        node->leftChild = rotateLeft(node->leftChild);
        return rotateRight(node);
    }

    if (balance < -1 && value < node->rightChild->value) {
        node->rightChild = rotateRight(node->rightChild);
        return rotateLeft(node);
    }

    return node;
}

// Node with minimum value
TreeNode *getMinValueNode(TreeNode *node) {
    TreeNode *current = node;
    while (current->leftChild != NULL)
        current = current->leftChild;
    return current;
}

// Delete node
TreeNode *deleteNode(TreeNode *root, int value) {
    if (root == NULL)
        return root;

    if (value < root->value)
        root->leftChild = deleteNode(root->leftChild, value);
    else if (value > root->value)
        root->rightChild = deleteNode(root->rightChild, value);
    else {
        if ((root->leftChild == NULL) || (root->rightChild == NULL)) {
            TreeNode *temp = root->leftChild ? root->leftChild : root->rightChild;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            TreeNode *temp = getMinValueNode(root->rightChild);
            root->value = temp->value;
            root->rightChild = deleteNode(root->rightChild, temp->value);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + maxHeight(getHeight(root->leftChild), getHeight(root->rightChild));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->leftChild) >= 0)
        return rotateRight(root);

    if (balance > 1 && getBalance(root->leftChild) < 0) {
        root->leftChild = rotateLeft(root->leftChild);
        return rotateRight(root);
    }

    if (balance < -1 && getBalance(root->rightChild) <= 0)
        return rotateLeft(root);

    if (balance < -1 && getBalance(root->rightChild) > 0) {
        root->rightChild = rotateRight(root->rightChild);
        return rotateLeft(root);
    }

    return root;
}

// Print tree
void printTree(TreeNode *root, string indent, bool last) {
    if (root != nullptr) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        } else {
            cout << "L----";
            indent += "|  ";
        }
        cout << root->value << endl;
        printTree(root->leftChild, indent, false);
        printTree(root->rightChild, indent, true);
    }
}

int main() {
    TreeNode *root = NULL;
    root = insert(root, 33);
    root = insert(root, 13);
    root = insert(root, 53);
    root = insert(root, 9);
    root = insert(root, 21);
    root = insert(root, 61);
    root = insert(root, 8);
    root = insert(root, 11);

    printTree(root, "", true);

    root = deleteNode(root, 13);
    cout << "After deleting 13:" << endl;
    printTree(root, "", true);

    return 0;
}
