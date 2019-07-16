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

ll getNumberPattern(string &s) {
    
    int curr_num = 1;
    int index = 0;
    int n = s.size();
    ll answer = 0;
    int count = 0;
    int curr_index = 0;
    
    while(curr_index < n) {
        if(s[curr_index] == 'I') {
            count = 0;
            while(curr_index < n && s[curr_index] == 'I') {
                count++; curr_index++;
            }
            
            loop(j,0,count) {
                answer = 10*answer + curr_num;
                curr_num++;
            }
            
            if(curr_index == n) {
                answer = 10*answer + curr_num;
            }
            
            // cout << answer << endl;
            
        } else if (s[curr_index] == 'D') {
            count = 0;
            while(curr_index < n && s[curr_index] == 'D') {
                count++; curr_index++;
            }
            
            int temp = count;
            
            loop(j,0,count+1) {
                answer = 10*answer + (curr_num + temp);
                temp -= 2; curr_num++;
            }
            
            curr_index++;
            
            if(curr_index == n) {
                answer = 10*answer + curr_num;
            }
            
            // cout << answer << endl;
        }
    }
    return answer;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        
        cout << getNumberPattern(s) << endl;
    }
}