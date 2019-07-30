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

int getXorUtil(int *st, int ss, int se, int qs, int qe, int si) {
    if(qs <= ss && qe >= se) return st[si];
    if(se < qs || ss > qe) return 0;

    int mid = ss + (se - ss)/2;
    return getXorUtil(st, ss, mid, qs, qe, 2*si + 1) + getXorUtil(st, mid+1, se, qs, qe, 2*si + 2);
}

int getXor(int *st, int qs, int qe, int n) {
    if(qs < 0 || qe > n-1 || qs > qe) {
        return -1;
    }

    return getXorUtil(st, 0, n-1, qs, qe, 0);
}

void updateValueUtil(int *st, int ss, int se, int i, int prev_val, int new_val, int si) {
    if(i < ss || i > se) return;

    st[si] = (st[si] ^ prev_val) ^ new_val;

    if(ss != se) {
        int mid = ss + (se - ss)/2;

        updateValueUtil(st, ss, mid, i, prev_val, new_val, 2*si + 1);
        updateValueUtil(st, mid+1, se, i, prev_val, new_val, 2*si + 2);
    }
}

void updateValue(int *arr, int *st, int i, int n, int new_val) {
    if(i < 0 || i > n-1) {
        cout << "Invalid Input\n";
        return;
    }

    int prev = arr[i];

    arr[i] = new_val;

    updateValueUtil(st, 0, n-1, i, prev, new_val, 0);
}

int constructSTUtil(int *arr, int ss, int se, int* st, int si) {
    if(ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }

    int mid = ss + (se - ss)/2;
    st[si] = constructSTUtil(arr, ss, mid, st, 2*si + 1) ^ constructSTUtil(arr, mid+1, se, st, 2*si + 2);
    return st[si];
}

int* constructST(int *arr, int n) {
    int x = (int)ceil(log2(n));
    int max_size = 2*(int)pow(2,x) - 1;

    int *st = new int[max_size];

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
            cout << getXor(st, l, r, n) << " ";
        }

        cout << endl;
    }
}