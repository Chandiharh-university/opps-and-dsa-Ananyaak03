#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


Node* createBinaryTree() {
    int value;
    cout << "Enter data (-1 for no node): ";
    cin >> value;
    if (value == -1) return nullptr;

    Node* root = new Node(value);
    cout << "Enter left child of " << value << ": ";
    root->left = createBinaryTree();
    cout << "Enter right child of " << value << ": ";
    root->right = createBinaryTree();
    return root;
}

int height(Node* root) {
    if (!root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int getBalance(Node* root) {
    if (!root) return 0;
    return height(root->left) - height(root->right);
}


Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}


Node* insertAVL(Node* root, int value) {
    if (!root) return new Node(value);

    if (value < root->data)
        root->left = insertAVL(root->left, value);
    else if (value > root->data)
        root->right = insertAVL(root->right, value);
    else
        return root; 

    int balance = getBalance(root);

    if (balance > 1 && value < root->left->data)
        return rightRotate(root);

    if (balance < -1 && value > root->right->data)
        return leftRotate(root);

    if (balance > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* convertToAVL(Node* root, Node* avlRoot = nullptr) {
    if (!root) return avlRoot;
    avlRoot = insertAVL(avlRoot, root->data);
    avlRoot = convertToAVL(root->left, avlRoot);
    avlRoot = convertToAVL(root->right, avlRoot);
    return avlRoot;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    cout << "Create the binary tree:\n";
    Node* binaryTree = createBinaryTree();

    cout << "\nInorder traversal of binary tree:\n";
    inorder(binaryTree);

    cout << "\n\nConverting to AVL tree...\n";
    Node* avlTree = convertToAVL(binaryTree);

    cout << "Inorder traversal of AVL tree:\n";
    inorder(avlTree);

    return 0;
}
