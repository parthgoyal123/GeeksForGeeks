#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int x){
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

void mirrorTree(Node *node) {

    if (node == NULL) {
        return;
    }
    
    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;
    
    if(node->left != NULL) mirrorTree(node->left);
    if(node->right != NULL) mirrorTree(node->right);
}

void inOrder(Node *root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        map<int, Node*> tree;
        Node *root = NULL;
        while(n--) {
            Node *parent;
            Node *child;
            int n1, n2;
            char ch;
            cin >> n1 >> n2 >> ch;
            
            if(tree.find(n1) == tree.end()) {
                parent = new Node(n1);
                tree[n1] = parent;

                if(root == NULL) {
                    root = parent;
                }
            } else {
                parent = tree[n1];
            }

            child = new Node(n2);

            if (ch == 'L') {
                parent->left = child;
            } else {
                parent->right = child;
            }

            tree[n2] = child;
        }

        cout << "Traversal Original : "; inOrder(root); cout << endl;
        mirrorTree(root);
        cout << "Traversal after Mirror Image : "; inOrder(root); cout << endl;
    }
}