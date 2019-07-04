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


void preOrder(Node *root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Node *root = NULL;
        map<int, Node*> tree;
        while(n--){
            int n1, n2;
            char ch;
            cin >> n1 >> n2 >> ch;
            Node *parent;

            if(tree.find(n1) == tree.end()){
                parent = new Node(n1);
                tree[n1] = parent;

                if(root == NULL){
                    root = parent;
                }
            } else{
                parent = tree[n1];
            }

            Node* child = new Node(n2);
            if(ch == 'L'){
                parent->left = child;
            } else {
                parent->right = child;
            }

            tree[n2] = child;
        }

        preOrder(root);
        cout << endl;
    }
}