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

int getNum(string *s, int n = 3) {
    int hash_m[10] = {0};
    int hash_s[10] = {0};
    int hash_p[10] = {0};

    loop(i,0,3) {
        if(s[i][1] == 'm') {
            hash_m[s[i][0]-'0']++;

            if(hash_m[s[i][0]-'0'] == 3) {
                return 0;
            }
        }
        else if(s[i][1] == 's') {
            hash_s[s[i][0]-'0']++;

            if(hash_s[s[i][0]-'0'] == 3) {
                return 0;
            }
        }
        else if(s[i][1] == 'p') {
            hash_p[s[i][0]-'0']++;

            if(hash_p[s[i][0]-'0'] == 3) {
                return 0;
            }
        }
    }

    bool flag = false;
    loop(i,1,8) {
        if(hash_m[i] >= 1 && hash_m[i+1] >= 1 && hash_m[i+2] >= 1) return 0;
        if(hash_s[i] >= 1 && hash_s[i+1] >= 1 && hash_s[i+2] >= 1) return 0;
        if(hash_p[i] >= 1 && hash_p[i+1] >= 1 && hash_p[i+2] >= 1) return 0;

        if((hash_m[i] >= 1 && hash_m[i+1] >=1) || (hash_m[i] >= 1 && hash_m[i+2] >= 1) || (hash_m[i+1] >= 1 && hash_m[i+2] >= 1)) flag = true;
        if((hash_s[i] >= 1 && hash_s[i+1] >=1) || (hash_s[i] >= 1 && hash_s[i+2] >= 1) || (hash_s[i+1] >= 1 && hash_s[i+2] >= 1)) flag = true;
        if((hash_p[i] >= 1 && hash_p[i+1] >=1) || (hash_p[i] >= 1 && hash_p[i+2] >= 1) || (hash_p[i+1] >= 1 && hash_p[i+2] >= 1)) flag = true;

        if(hash_m[i] > 1 || hash_m[i+1] > 1 || hash_m[i+2] > 1) flag =  true;
        if(hash_s[i] > 1 || hash_s[i+1] > 1 || hash_s[i+2] > 1) flag =  true;
        if(hash_p[i] > 1 || hash_p[i+1] > 1 || hash_p[i+2] > 1) flag = true;
    }

    if(flag) return 1;
    else return 2;
}

int main(){
    string s[3];
    loop(i,0,3) cin >> s[i];

    cout << getNum(s) << endl;
}