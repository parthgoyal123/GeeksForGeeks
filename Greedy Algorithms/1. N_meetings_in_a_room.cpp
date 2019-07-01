#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back
#define MAX 1000000007

#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for(long long int i=a; i<b; i++)

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        int a[n], b[n];

        loop(i, 0, n){
            cin >> a[i];
        }
        loop(i, 0, n){
            cin >> b[i];
        }

        pair<int, pair<int, int>> time[n];
        loop(i,0,n){
            pair<int, pair<int, int>> new_pair = make_pair(b[i],make_pair(a[i],i+1));
            time[i] = new_pair;
        }

        sort(time, time+n);

        int number = 0;
        int finish = time[0].first;
        // cout << finish << endl;
        cout << time[0].second.second << " ";

        loop(i,1,n){
            // cout << time[i].second.first << endl;
            if(time[i].second.first >= finish){
                finish = time[i].first;
                // cout << finish << endl;
                cout << time[i].second.second << " ";
            }
        }
        cout << endl;
    }
}