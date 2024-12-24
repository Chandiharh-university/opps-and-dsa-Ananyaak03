#include <iostream>
using namespace std;

// Definition of a node in the binary tree
struct Node {
    int data;         // Data stored in the node
    Node* left;       // Pointer to the left child
    Node* right;      // Pointer to the right child

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to create a new node
Node* createNode(int value) {
    return new Node(value);
}

// Function to perform an inorder traversal of the tree
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    inorderTraversal(root->left);     // Visit left subtree
    cout << root->data << " ";        // Visit root
    inorderTraversal(root->right);    // Visit right subtree
}

// Function to perform a preorder traversal of the tree
void preorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";        // Visit root
    preorderTraversal(root->left);    // Visit left subtree
    preorderTraversal(root->right);   // Visit right subtree
}

// Function to perform a postorder traversal of the tree
void postorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    postorderTraversal(root->left);   // Visit left subtree
    postorderTraversal(root->right);  // Visit right subtree
    cout << root->data << " ";        // Visit root
}

int main() {
    
    Node* root = createNode(1);

   
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
