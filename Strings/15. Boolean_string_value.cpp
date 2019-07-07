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

char operate(int d1, char o, int d2) {
    switch(o){
        case 'A' : {
            return (d1 & d2) + '0';
            break;
        }
        case 'B' : {
            return (d1 | d2) + '0';
            break;
        }
        case 'C' : {
            return (d1 ^ d2) + '0';
            break;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        
        int answer;
        
        loop(i, 0, s.size()-2){
            int digit1 = s[i] - 48;
            char operation = s[i+1];
            int digit2 = s[i+2] - 48;
            
            // cout << digit1 << " " << operation << " "<< digit2 << "  ";
            
            s[i+2] = operate(digit1, operation, digit2);
            i += 1;
        }
        
        cout << s[s.size()-1] << endl;
    }
}