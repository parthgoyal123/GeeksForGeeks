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

int Op(string s, string *op, int n) {
    loop(i, 0, n) {
        if(s == op[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        
        string opr1[] = {"M", "D", "C", "L", "X", "V", "I"};
        string opr2[] = {"CM", "CD", "XC", "XL", "IX", "IV"};
        int num1[] = {1000,500,100,50,10,5,1};
        int num2[] = {900,400,90,40,9,4};
        
        int number = 0;
        loop(i, 0, s.size()) {
            string temp1, temp2;
            temp1 = s[i];
            temp2 = s[i];
            
            if(i != s.size()-1)
                temp2 += s[i+1];
            
            // cout << temp1 << " " << temp2  << "  ";
            
            int i2 = Op(temp2, opr2, 6);
            int i1 = Op(temp1, opr1, 7);
            
            if(i2 != -1) {
                number += num2[i2];
                // cout << num2[i2] << " " << number << "  ";
                i++;
            } else {
                number += num1[i1];
                // cout << num1[i1] << " " << number << "  ";
            }
        }
        
        cout << number << endl;
    }
}