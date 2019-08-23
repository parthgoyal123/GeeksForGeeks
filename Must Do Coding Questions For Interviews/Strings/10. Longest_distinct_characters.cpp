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
void printMatrix(T **arr, int n, int m){
    loop(i,0,n){
        loop(j,0,m) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    } 
    cout << endl;
}

int longestDistinctSubstringLength(string &str) {
    
    // make map to store the character and its occurence index
    unordered_map<char, int> map;
    
    int start = 0;
    int end = 0;
    
    int curr_length = 0;
    int max_length = 0;
    
    for(int i = 0; i<str.length(); i++) {
        
        // if its a new char in map, add to length and map
        if(map.find(str[i]) == map.end()) {
            curr_length++;
            
            // store its index
            map[str[i]] = i;
            end = i;
        } 
        
        // if already exists in map, move the substring start and curr_length
        else {
            
            // change the max_length
            max_length = max(max_length, curr_length);
            
            int curr = map[str[i]];
            
            for(int j = start; j<curr; j++) {
                map.erase(str[j]);
            }
            
            // change the starting point of the substring
            start = map[str[i]] + 1;
            
            // change the index of the char
            map[str[i]] = i;
            
            // change the curr_length
            end = i;
            
            curr_length = end-start+1;
        }
    }
    
    // see for last
    max_length = max(max_length, curr_length);
    
    return max_length;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        
        cout << longestDistinctSubstringLength(str) << endl;
    }
}