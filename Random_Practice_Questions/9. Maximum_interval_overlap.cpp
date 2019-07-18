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

void printMaximumIntervalOverlap(int *entry, int *dep, int n) {
    if(n <= 0) return;
    sort(entry, entry+n);
    sort(dep, dep+n);
    
    int total_entry = 0;
    int total_exit = 0;
    
    int max_guests = 0;
    int time_of_max;
    
    int i = 0, j = 0;
    
    while(i<n && j<n) {
        if(entry[i] <= dep[j]) {
            total_entry++;
            i++;
        } else {
            total_exit++;
            j++;
        }
        
        max_guests = ((total_entry - total_exit) >= max_guests) ? (total_entry - total_exit): max_guests;
        time_of_max = ((total_entry - total_exit) == max_guests) ? entry[i-1]: time_of_max;
    }
    
    cout << max_guests << " " << time_of_max << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int entry[n], dep[n];
        loop(i,0,n) cin >> entry[i];
        loop(i,0,n) cin >> dep[i];
        
        printMaximumIntervalOverlap(entry, dep, n);
    }
}