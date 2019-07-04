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

Node* pushInBst(Node *root, int n){
    if(root == NULL){
        Node *new_node = new Node(n);
        return new_node;
    }
    

    if(root->data > n){
        root->left = pushInBst(root->left, n);
    } else{
        root->right = pushInBst(root->right, n);
    }
    return root;
}

Node* deleteNode(Node* root, int n){
    
}

bool searchInBst(Node* root, int s){
    if(root == NULL){
        return false;
    }
    if(root->data == s){
        return true;
    }

    if(s < root->data){
        searchInBst(root->left, s);
    } else{
        searchInBst(root->right, s);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Node *root = NULL;
        while(n--){
            int n1;
            cin >> n1;
            if(root == NULL){
                root = new Node(n1);
            } else {
                root = pushInBst(root, n1);
            } 
        }
        int s;
        cin >> s;
        if(searchInBst(root, s)){
            cout << 1 << endl;
        } else{
            cout << 0 << endl;
        }
    }
}