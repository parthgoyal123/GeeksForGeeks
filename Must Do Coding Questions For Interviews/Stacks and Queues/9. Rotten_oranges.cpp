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

bool isSafeAndFresh(int x, int y, int m, int n, int **arr) {
    return (x >= 0 && x < m && y >= 0 && y < n && arr[x][y] == 1);
}

int getTimeForRotten(int **arr, int m, int n) {
    
    // store rotten oranges in queue
    queue<pair<int, int>> q;
    
    // get all the rotten oranges index
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) {
            if(arr[i][j] == 2) {
                q.push({i, j});
            }
        }
    }
    
    int ttime = 0;
    
    while(!q.empty()) {
        
        // flag denotes that some new index was added
        bool flag = false;
        
        // get current size of queue
        int curr_size = q.size();
        while(curr_size--) {
            
            // for each rotten orange, rot nearby and push to queue
            pair<int, int> top = q.front();
            q.pop();
            
            int x = top.first;
            int y = top.second;
            
            if(isSafeAndFresh(x+1, y, m, n, arr)) {
                q.push({x+1, y}); flag = true;
                arr[x+1][y] = 2;
            }
            
            if(isSafeAndFresh(x-1, y, m, n, arr)) {
                q.push({x-1, y}); flag = true;
                arr[x-1][y] = 2;
            }
            
            if(isSafeAndFresh(x, y+1, m, n, arr)) {
                q.push({x, y+1}); flag = true;
                arr[x][y+1] = 2;
            }
            
            if(isSafeAndFresh(x, y-1, m, n, arr)) {
                q.push({x, y-1}); flag = true;
                arr[x][y-1] = 2;
            }
        }
        
        if(flag) ttime++;
        else break;
    }
    
    // check final matrix for confirmation
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) {
            if(arr[i][j] == 1) return -1;
        }
    }
    
    return ttime;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        int **arr = new int*[m];
        loop(i,0,m) arr[i] = new int[n];
        loop(i,0,m) loop(j,0,n) cin >> arr[i][j];
        
        cout << getTimeForRotten(arr, m, n) << endl;
    }
}