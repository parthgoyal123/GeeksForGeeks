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

int longestEvenLengthSubstring(string &str) {
    int n = str.length();
    
    if(n == 1) return 0;
    if(n == 2 && str[0] == str[1]) return 1;
    if(n == 2 && str[0] != str[1]) return 0;
    
    int max_length = 0;
    int max_left;
    int max_right;
    
    int mid1 = 0;
    int mid2 = 1;
    
    int left;
    int right;
    
    int left_sum = 0;
    int right_sum = 0;
    
    while(mid2 < n) {
        left = mid1;
        right = mid2;
        
        left_sum = 0;
        right_sum = 0;
        
        while(left >= 0 && right < n) {
            left_sum += (str[left] - '0');
            right_sum += (str[right] - '0');
            
            if(left_sum == right_sum) {
                int length = right-left+1;
                
                if(length > max_length) {
                    max_length = length;
                    max_left = left;
                    max_right = right;
                }
            }
            
            left--;
            right++;
        }
        
        mid1++;
        mid2++;
    }
    
    // cout << "Longest : " << str.substr(max_left, max_length) << endl;
    
    return max_length;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        
        cout << longestEvenLengthSubstring(str) << endl;
    }
}