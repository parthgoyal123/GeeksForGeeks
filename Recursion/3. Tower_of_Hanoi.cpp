#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

void printArray(int arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

void tower(int n, int from, int aux, int to){
    if(n == 1){
        cout << "move disk 1 from rod " << from << " to rod " << to << endl;
        return;
    }

    
    tower(n-1, from, to, aux);

    cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;

    tower(n-1, aux, from, to);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        char from = 1, aux = 2, to = 3;
        tower(n, from, aux, to);
        ll int count = (ll)pow(2,n) - 1;
        cout << count << endl;
    }
}