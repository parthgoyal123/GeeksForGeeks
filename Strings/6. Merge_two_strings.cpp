#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

string mergeStrings(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    cout << n << m;

    string s(n+m, ' ');
    cout << s;
    int index = 0;
    int i1,i2 = 0;
    while(i1<n && i2<m){
        cout << "s1" << s1[i1];
        s[index] = s1[i1];
        s[index+1] = s2[i2];
        index += 2;
        i1++;
        i2++;
        cout << s[index-1] << s[index-2];
    }

    while(i1<n){
        s[index] = s1[i1];
        index++;
        i1++;
    }
    while(i2<m){
        s[index] = s2[i2];
        index++;
        i2++;
    } 
    
    return s;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;

        int n = s1.size();
        int m = s2.size();

        int i1 = 0,i2 = 0;
        while(i1<n && i2<m){
            cout << s1[i1] << s2[i2];
            i1++;
            i2++;
        }

        while(i1<n){
            cout << s1[i1];
            i1++;
        }
        while(i2<m){
            cout << s2[i2];
            i2++;
        } 
        cout << endl;
    }
}