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

int compare(string t1, string t2) {
    if(t1 == t2) return 0;
    if(t1 == "ng" && t2 == "ng") return 0;
    if(t1 == "ng" && t2 != "ng") {
        if(t2[0] >= 'o') return 2;
        if(t2[0] <= 'n') return 1;
    }
    
    if(t1 != "ng" && t2 != "ng") {
        if(t1[0] == t2[0]) {
            if(t1[1] == t2[1]) return 0;
            if(t1[1] > t2[1]) return 1;
            else return 2;
        } else if(t1[0] > t2[0]) return 1;
        else return 2;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string x, y;
        cin >> x >> y;
        int s1 = x.size();
        int s2 = y.size();
        int i = 0;
        int j = 0;
        bool flag = false;
        
        while(i < s1-1 && j < s2-1) {
            string t1 = string() + x[i] + x[i+1];
            string t2 = string() + y[j] + y[j+1];
            
            int big = compare(t1, t2);
            if(big == 0) {
                i++; j++;
            } else if(big == 1) {
                cout << 1 << endl;
                flag = true;
                break;
            } else {
                cout << -1 << endl;
                flag = true;
                break;
            }
        }
        if(!flag) {
            cout << 0 << endl;
        }
        
    }
}