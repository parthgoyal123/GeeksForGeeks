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

struct Activity{
    int start;
    int finish;
    int index;
};

// compare function that sorts on the basis of ending time
bool compare(Activity const &p1, Activity const &p2) {
    
    // if ending time is same, then check for starting time
    if(p2.finish == p1.finish) {
        return p1.start < p2.start;
    }
    return p1.finish < p2.finish;
}

void getMaxJobsIndex(int *s, int *e, int n) {
    
    // make starting and ending time pairs
    Activity pairs[n];
    loop(i,0,n) {
        pairs[i].start = s[i];
        pairs[i].finish = e[i];
        pairs[i].index = i+1;
    }
    
    // sort on basis of ending time;
    sort(pairs, pairs+n, compare);

    int ending_time = INT_MIN;
    
    loop(i, 0, n) {
        
        // if next job's starting time is >= than previous ending
        if(pairs[i].start >= ending_time) {
            ending_time = pairs[i].finish;
            
            cout << pairs[i].index << " ";
        }
    }
    cout << endl;
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
        
        getMaxJobsIndex(start, end, n);
    }
}