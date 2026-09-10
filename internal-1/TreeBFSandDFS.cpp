#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) {
        val=v;
        left=right=NULL;
    }
};
 
Node* buildTree() {
    int rootVal;
    cout<<"Enter root value: ";
    cin>>rootVal;
    if (rootVal == -1) return NULL;
    Node* root=new Node(rootVal);

    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        Node* curr = q.front(); 
        q.pop();

        int leftVal, rightVal;
        cout << "Enter left child of " << curr->val << " (-1 if none): ";
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }
 
        cout << "Enter right child of " << curr->val << " (-1 if none): ";
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }
    return root;
}
 
// DFS Traversals-Inorder,Preorder,Postorder
void preorder(Node* r)  {
    if (!r) return;
    cout << r->val << " ";
    preorder(r->left); 
    preorder(r->right); 
}
void inorder(Node* r)   { 
    if (!r) return; 
    inorder(r->left);   
    cout << r->val << " ";
    inorder(r->right); 
}
void postorder(Node* r) { 
    if (!r) return;
    postorder(r->left);
    postorder(r->right);
    cout << r->val << " "; 
}
 
// BFS Traversal - Level Order Printing
void levelOrder(Node* root) {
    if (!root) return;
    
	queue<Node*> q;
    q.push(root);
    
	int level = 1;
    while (!q.empty()) {
        int levelSize = q.size();
        cout << "Level:"<<level<<": ";
        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front(); 
            q.pop();
            
            cout << curr->val << " ";
            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << "\n";
        level++;
    }
}
 
int main() {
    Node* root = buildTree();
    cout << "\nPreorder:   "; preorder(root);
    cout << "\nInorder:    "; inorder(root);
    cout << "\nPostorder:  "; postorder(root);
    cout << "\nLevelOrder: "; levelOrder(root);
    cout << endl;

//     Enter root value: 1
// Enter left child of 1 (-1 if none): 2
// Enter right child of 1 (-1 if none): 3
// Enter left child of 2 (-1 if none): 4
// Enter right child of 2 (-1 if none): -1
// Enter left child of 3 (-1 if none): -1
// Enter right child of 3 (-1 if none): -1

// Preorder:   1 2 4 3 
// Inorder:    4 2 1 3 
// Postorder:  4 2 3 1 
// LevelOrder: Level:1: 1 
// Level:2: 2 3 
// Level:3: 4

    return 0;
}