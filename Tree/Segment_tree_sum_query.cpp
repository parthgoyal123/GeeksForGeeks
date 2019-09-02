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
void printMatrix(T **arr, int m, int n){
    loop(i,0,m){
        loop(j,0,n) cout << arr[i][j] << " ";
    } cout << endl;
}

int getMid(int a, int b) {
    return a + (b-a)/2;
}

int getSumUtil(int *st, int ss, int se, int qs, int qe, int si) {

    // return segment[si] if complete range of segment falls into the query range
    if(qs <= ss && qe >= se) return st[si];

    // return if range totally out
    if(se < qs || ss > qe) return 0;

    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*si + 1) + getSumUtil(st, mid+1, se, qs, qe, 2*si + 2);
}

int getSum(int *st, int qs, int qe, int n) {
    if(qs < 0 || qe > n-1 || qs > qe) {
        return -1;
    }

    // int getSumUtil(int *st, int ss, int se, int qs, int qe, int si);
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}

void updateValueUtil(int *st, int ss, int se, int i, int diff, int si) {

    // index totally out of segment indexes
    if(i < ss || i > se) return;

    st[si] += diff;

    // do not recur for leaf nodes
    if(ss != se) {
        int mid = getMid(ss, se);

        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);
    }
}

void updateValue(int *arr, int *st, int i, int n, int new_val) {
    if(i < 0 || i > n-1) {
        cout << "Invalid Input\n";
        return;
    }

    // get the diff to be added to the nodes of the segment tree
    // where i falls in their range
    int diff = new_val - arr[i];

    arr[i] = new_val;

    // void updateValueUtil(int *st, int ss, int se, int i, int diff, int si);
    updateValueUtil(st, 0, n-1, i, diff, 0);
}

int constructSTUtil(int *arr, int ss, int se, int* st, int si) {

    // if segmented to a single node
    if(ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }

    // divide into two segments and construct Segment Tree recursively
    int mid = getMid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, 2*si + 1) + constructSTUtil(arr, mid+1, se, st, 2*si + 2);
    
    // return the sum of the segment ss to se
    return st[si];
}

int* constructST(int *arr, int n) {
    int x = (int)ceil(log2(n));
    int max_size = 2*(int)pow(2,x) - 1;

    int *st = new int[max_size];

    // int constructSTUtil(int *arr, int ss, int se, int* st, int si);
    constructSTUtil(arr, 0, n-1, st, 0);

    return st;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i,0,n) cin >> arr[i];

        int *st = constructST(arr, n);

        int l, r, q, new_val, ind;
        cin >> q;
        while(q--) {
            cin >> ind >> new_val >> l >> r;

            updateValue(arr, st, ind, n, new_val);
            cout << getSum(st, l, r, n) << " ";
        }

        cout << endl;
    }
}