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

// compare function that sorts on the basis of ending time
bool compare(pair<int, int> const &p1, pair<int, int> const &p2) {
    
    // if ending time is same, then check for starting time
    if(p2.second == p1.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int getMaxJobs(int *s, int *e, int n) {
    
    // make starting and ending time pairs
    pair<int, int> pairs[n];
    loop(i,0,n) {
        pairs[i] = {s[i], e[i]};
    }
    
    // sort on basis of ending time;
    sort(pairs, pairs+n, compare);
    
    int count = 1;
    int ending_time = pairs[0].second;
    
    loop(i, 1, n) {
        
        // if next job's starting time is >= than previous ending
        if(pairs[i].first >= ending_time) {
            count++;
            ending_time = pairs[i].second;
        }
    }
    
    return count;
}


int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int start[n], end[n];
        loop(i,0,n) cin >> start[i];
        loop(i,0,n) cin >> end[i];
        
        cout << getMaxJobs(start, end, n) << endl;
    }
}