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
void printMatrix(T **arr, int m, int n){
    loop(i,0,m){
        loop(j,0,n) cout << arr[i][j] << " ";
    } cout << endl;
}

string stringNew(int n) {

    int y = 1;

    bool flag = false;
    while(1) {

        if(n%y != 0) {
            y++;
            continue;
        }
        
        int x = (1 + sqrt(1 + 8*(n/y)))/2;

        if(x*x - x - 2*(n/y) == 0) {
            string s;

            loop(i,0,y) {
                s += "1";
            }

            loop(i,0,x) {
                s = s + "3";
            }

            s = s + "7";

            return s;
        }
    }


}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        cout << stringNew(n) << endl;
    }
}