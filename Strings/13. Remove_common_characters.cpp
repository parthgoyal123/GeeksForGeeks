#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)
#define iterate(it, v) for (auto it = v.begin(); it!= v.end(); it++)

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        unordered_map <char, int> hash1;
        unordered_map <char, int> hash2;
        
        loop(i, 0, s1.size()){
            hash1[s1[i]] = 1;
        } loop(i, 0, s2.size()){
            if(hash1.find(s2[i]) != hash1.end()){
                hash1[s2[i]] = 0;
            } else{
                hash2[s2[i]] = 1;
            }
        }
        
        bool flag = false;
        
        iterate(it, hash1){
            if(it->second == 1){
                flag = true;
                break;
            }
        }
        if(!flag){
            iterate(it, hash2){
                if(it->second == 1){
                    flag = true;
                    break;
                }
            }
        }
        
        if(!flag){
            cout << -1 << endl;
        } else {
            loop(i, 0, s1.size()){
                if(hash1[s1[i]] == 1){
                    cout << s1[i];
                }
            }
            loop(i, 0, s2.size()){
                if(hash2[s2[i]] == 1){
                    cout << s2[i];
                }
            } cout << endl;
        
        }
    }
}