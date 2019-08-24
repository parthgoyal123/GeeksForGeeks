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

/* this compare function is the heart of the question*/
bool compare(const int a, const int b) {
    string s1 = to_string(a);
    string s2 = to_string(b);
    
    // number formed by s1+s2 should be greater than s2+s1
    return (s1.append(s2) > s2.append(s1));  
}

string largestNumberFormed(int *arr, int n) {
    
    // sort on the basis of the compare functions=
    sort(arr, arr+n, compare);
    
    string str = "";
    loop(i,0,n) {
        str.append(to_string(arr[i]));
    }
    
    return str;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i,0,n) cin >> arr[i];
        
        string largest_num = largestNumberFormed(arr, n);
        cout << largest_num << endl;
    }
}