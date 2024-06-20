#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

class BST {
public:
    Node* root;

    BST() : root(NULL) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    void deleteNode(int value) {
        root = deleteRec(root, value);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    void postorder() {
        postorderRec(root);
        cout << endl;
    }

private:
    Node* insertRec(Node* node, int value) {
        if (node == NULL) return new Node(value);
        if (value < node->data) node->left = insertRec(node->left, value);
        else if (value > node->data) node->right = insertRec(node->right, value);
        return node;
    }

    Node* deleteRec(Node* root, int key) {
        if (root == NULL) return root;

        if (key < root->data)
            root->left = deleteRec(root->left, key);
        else if (key > root->data)
            root->right = deleteRec(root->right, key);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteRec(root->right, temp->data);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    void inorderRec(Node* root) {
        if (root != NULL) {
            inorderRec(root->left);
            cout << root->data << " ";
            inorderRec(root->right);
        }
    }

    void preorderRec(Node* root) {
        if (root != NULL) {
            cout << root->data << " ";
            preorderRec(root->left);
            preorderRec(root->right);
        }
    }

    void postorderRec(Node* root) {
        if (root != NULL) {
            postorderRec(root->left);
            postorderRec(root->right);
            cout << root->data << " ";
        }
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder traversal: ";
    tree.inorder();

    cout << "Preorder traversal: ";
    tree.preorder();

    cout << "Postorder traversal: ";
    tree.postorder();

    cout << "Delete 20\n";
    tree.deleteNode(20);
    cout << "Inorder traversal: ";
    tree.inorder();

    return 0;
}

