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

int main(){
    int t;
    cin >> t;
    string temp;
    getline(cin, temp);
    while(t--){
        string s; 
        getline(cin, s);
        
        bool hash[256] = {false};
        
        int n = s.size();
        int index = 0;
        loop(i, 0, n) {
            if(hash[tolower(s[i])] == false) {
                hash[tolower(s[i])] = true;
                s[index] = s[i];
                index++;
            } else {
                hash[tolower(s[i])] = false;
            }
        }
        
        s.erase(index);
        cout << s << endl;
    }
}