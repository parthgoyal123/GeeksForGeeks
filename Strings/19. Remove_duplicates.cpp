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

bool isCapital(char c) {
    if(c>='A' && c<='Z') return true;
    return false;
}

// BETTER SOLUTION
void removeDuplicates1(string &s) {
    unordered_map<char, int> hash;
        
    int index = 0;
    loop(i, 0, s.size()) {
        if(hash.find(s[i]) == hash.end()){
            hash[s[i]] = 1;
            s[index] = s[i];
            index++;
        }
    }
    
    s.erase(index);
}

void removeDuplicates2(string &s) {
    int hasha[26] = {0};
    int hashA[26] = {0};
        
    loop(i, 0, s.size()) {
        if(isCapital(s[i])) hashA[s[i]-'A'] = 1;
        else hasha[s[i]-'a'] = 1;
    }
    
    int index = 0;
    loop(i,0,s.size()) {
        if(isCapital(s[i]) && hashA[s[i]-'A'] == 1) {
            hashA[s[i]-'A'] = 0;
            s[index] = s[i];
            index++;
        } else if(!isCapital(s[i]) && hasha[s[i]-'a'] == 1) {
            hasha[s[i]-'a'] = 0;
            s[index] = s[i];
            index++;
        }
    }
    
    s.erase(index);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        removeDuplicates1(s);
        cout << s << endl;
    }
}