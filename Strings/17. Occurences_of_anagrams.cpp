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

bool compare(int *a, int *b, int n = 26) {
    loop(i, 0, n) {
        if(a[i] != b[i]) {
            return false;
        }
    } return true;
}

int countAnagrams(string &s, string &c) {
    int n = s.size();
    int m = c.size();
    
    if(m>n) return 0;
    
    int count = 0;
    
    int sh[26] = {0};
    int ch[26] = {0};
    
    loop(i, 0, m) {
        sh[s[i]-'a']++;
        ch[c[i]-'a']++;
    }
    if(compare(sh, ch)) count++;
    
    loop(i, m, n) {
        sh[s[i-m]-'a']--;
        sh[s[i]-'a']++;
        
        if(compare(sh, ch)) count++;
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s, c;
        cin >> s >> c;
        
        int count = countAnagrams(s, c);
        cout << count << endl;
    }
}