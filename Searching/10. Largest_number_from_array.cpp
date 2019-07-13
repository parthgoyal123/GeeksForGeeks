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

bool compareStrings(const string &s1, const string &s2) {
    string x = s1+s2;
    string y = s2+s1;
    
    return (x.compare(y) > 0)? 1: 0;
}

string getLargestNumber(int *arr, int n) {
    string s[n];
    
    loop(i,0,n){
        s[i] = to_string(arr[i]);
    }
    
    sort(s, s+n, compareStrings);
    
    string ans = "";
    loop(i,0,n){
        ans += s[i];
    } 
    
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i,0,n){
            cin >> arr[i];
        }
        
        string ans = getLargestNumber(arr, n);
        cout << ans << endl;
    }
}