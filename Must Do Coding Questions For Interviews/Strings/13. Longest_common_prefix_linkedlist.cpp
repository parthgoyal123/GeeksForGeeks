#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define md 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)
#define loopr(i,a,b) for(int i = a; i>=b; i--)
#define iterate(it, v) for (auto it = v.begin(); it!= v.end(); it++)
#define mk make_pair
#define pb push_back

template <typename T>
void printArray(T *arr, int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

template <typename T>
void printMatrix(T **arr, int n, int m){
    loop(i,0,n){
        loop(j,0,m) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    } 
    cout << endl;
}

struct Node{
    char data;
    Node* next;
    Node(char c) {
        this->next = NULL;
        this->data = c;
    }
};

void deleteNodes(Node *root) {
    
    // delete all nodes at root and hanging at root
    while(root) {
        Node* next = root->next;
        delete(root);
        root = next;
    }
}

string commonPrefix(string *arr, int n) {
    
    // make a head
    Node *head = new Node('!');
    Node *cur = head;
    
    // ---  INITIALISE --- //
    
    // make linked list for first string
    string str = arr[0];
    
    for(int i = 0; i<str.length(); i++) {
        cur->next = new Node(str[i]);
        cur = cur->next;
    }

    // move head to next and free the prev position
    Node* temp = head;
    head = head->next;
    delete temp;
    
    // traverse for all other strings
    for(int i = 1; i<n; i++) {
        str = arr[i];
        
        Node* curr = head;
        Node* prev = NULL;
        
        for(int j = 0; j<str.length(), curr != NULL; curr = curr->next, j++) {
            if(curr->data != str[j]) {
                deleteNodes(curr);
                if(prev != NULL) prev->next = NULL;
                else if(prev == NULL) return "-1";
                
                break;
            }
            prev = curr;
        }
        
        if(prev == NULL) return "-1";
    }
    
    // traverse the string
    Node *curr = head;
    string final = "";
    
    while(curr) {
        string temp(1, curr->data);
        final.append(temp);
        curr = curr->next;
    }
    
    if(final == "") return "-1";
    return final;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string arr[n];
        loop(i,0,n) cin >> arr[i];
        
        string str = commonPrefix(arr, n);
        cout << str << endl;
    }
}