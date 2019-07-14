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
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

int countMaxGold(int **gold, int n, int m) {

    int count[n][m];
    memset(count, 0, sizeof(count));
    
    int maximum = INT_MIN;
    
    loopr (col, m-1, 0) {
        loop (row, 0, n) {
            int right = (col == m-1)? 0 : count[row][col+1];
            
            int right_up = (col == m-1 || row == 0)? 0 : count[row-1][col+1];
            
            int right_down = (col == m-1 || row == n-1)? 0 : count[row+1][col+1];
            
            count[row][col] = gold[row][col] + max(max(right, right_up), right_down);
            
            if (count[row][col] > maximum) {
                maximum = count[row][col];
            }
        }
    }
    
    return maximum;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        
        int **arr = new int*[n];
        loop(i,0,n) arr[i] = new int[m];
        
        loop(i,0,n) {
            loop(j,0,m) cin >> arr[i][j];
        }
        
        int count = countMaxGold(arr, n, m);
        cout << count << endl;
    }
}