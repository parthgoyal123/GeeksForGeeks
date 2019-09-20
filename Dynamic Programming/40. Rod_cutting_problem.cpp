#include <bits/stdc++.h>

using namespace std;

void getOptimal(int n, int *price, int maxx) {
    vector<int> rev(n+1);
    vector<int> cut(n+1);
    rev[0] = 0;

    for(int i = 1; i<=n; i++) {
        int q = INT_MIN;
        for(int j = 1; j <= i; j++) {
            if(q < price[j] + rev[i-j]) {
                q = price[j] + rev[i-j];
                cut[i] = j;
            }
        }
        rev[i] = q;
    }

    cout << "Max Revenue = " << rev[n] << endl;

    cout << "Size of pieces : \n";

    while(n > 0) {
        cout << cut[n] << " ";
        n = n - cut[n];
    }
    cout  << endl;

    return;
}

int main(){
    int t;
    cin >> t;
    // cout << t;

    int maxx;
    cin >> maxx;
    int price[maxx+1];
    price[0] = 0;
    for(int i = 0; i<maxx; i++) cin >> price[i+1]; 

    while(t--) {
        int n; 
        cin >> n;

        getOptimal(n, price, maxx);
    }
}