#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define md 998244353
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

void getVal(ll int *arr, ll int *brr, int n) {

    int p = floor(log10(arr[0])) + 1;

    ll int sum_of_digits[p] = {0};

    loop(i,0,p) {
        loop(j,0,n) {
            sum_of_digits[p-1-i] += brr[j]%10;
            brr[j] = brr[j]/10; 
        }
    }

    printArray(sum_of_digits, p);

    ///    

    ll sum = 0;

    loop(i,0,n) {

        int power = 0;

        loopr(j,p-1,0) {
            // if(j == 0) {
            //     cout << power << endl;
            //     cout << (ll)pow(10, power);
            //     cout << (ll)pow(10, power+1);
            // }
            sum += ((ll)sum_of_digits[j] * (ll)pow(10, power));
            sum = sum%md;
            sum += ((ll)(n*(arr[i]%10)) * (ll)pow(10, power+1));
            sum = sum%md;
            arr[i] = arr[i]/10;
            power += 2;
        } 
        sum = sum%md;
    }

    cout << sum << endl;
}

int main(){
    
    int n;
    cin >> n;
    ll int arr[n];
    ll int brr[n];

    loop(i,0,n) {cin >> arr[i]; brr[i] = arr[i];}

    getVal(arr, brr, n);   
}