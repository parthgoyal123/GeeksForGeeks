#include <cstring>
#include <iostream>
#include <map>
using namespace std;
#define MAX 1000
// Structure of a tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
bool isSubtree(Node *T, Node *S);
void storeInorder(Node *, char[], int &);
void storePreOrder(Node *, char[], int &);
// Driver program to test above function
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        struct Node *child = NULL;
        map<int, Node *> m;
        int n;
        scanf(" %d", &n);
        struct Node *t2 = NULL;
        while (n--) {
            Node *parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            if (m.find(n1) == m.end()) {
                parent = new Node(n1);
                m[n1] = parent;
                if (t2 == NULL) t2 = parent;
            } else
                parent = m[n1];
            child = new Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        struct Node *child1;
        map<int, Node *> m1;
        int nodes;
        scanf("%d", &nodes);
        struct Node *t1 = NULL;
        while (nodes--) {
            Node *parent1;
            char lr1;
            int n3, n4;
            scanf("%d %d %c", &n3, &n4, &lr1);
            if (m1.find(n3) == m1.end()) {
                parent1 = new Node(n3);
                m1[n3] = parent1;
                if (t1 == NULL) t1 = parent1;
            } else
                parent1 = m1[n3];
            child = new Node(n4);
            if (lr1 == 'L')
                parent1->left = child;
            else
                parent1->right = child;
            m1[n4] = child;
        }
        cout << isSubtree(t1, t2);
        cout << endl;
    }
}


/* checks if two binary trees are identical */
bool isIdentical(Node* r1, Node* r2) {
    
    // base conditions
    if(!r1 && !r2) return true;
    if((r1 && !r2) || (!r1 && r2) || (r1->data != r2->data)) return false;
    
    // check for left and right subtrees if root's data is same
    return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
}


/* check for T2 being subtree to T1*/
bool isSubtree(Node* T1, Node* T2) {
    
    // null tree is subtree of any tree
    if(!T2) return true;
    
    // null tree cannot subroot any other root
    if(!T1) return false;
    
    if(isIdentical(T1, T2)) return true;
    
    return (isIdentical(T1->left, T2) || isIdentical(T1->right, T2));
}