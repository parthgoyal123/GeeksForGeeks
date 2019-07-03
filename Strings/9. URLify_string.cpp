#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

void urlify(string &s){

    int sndex = 0;
    while(s[sndex] == ' '){
        sndex++;
    }
    cout << sndex << " ";
    int endex = s.length()-1;
    while(s[endex] == ' '){
        // cout << "sendex : " << s[endex] << endl;
        endex--;
    }
    cout << endex << " ";
    int j = 0;
    int length_new = endex - sndex + 1;
    s[endex+1] = '\0';
    loop(i,0,length_new){
        cout << s[i+sndex] << " " << j << " ";
        s[i] = s[i+sndex]; j++;
    }
    s[length_new] = '\0';

    cout << s << "A" << endl; 

    
    // int space = 0;
    // // count spaces in between them 
    // loop(i, sndex, endex+1){
    //     if(s[i] == ' '){
    //         space++;
    //     }
    // }

    // int new_length = endex - sndex + 1 + 2*space;


}


int main(){
    int t;
    cin >> t;
    string temp;
    getline(cin, temp);
    while(t--){
        string s;
        getline(cin, s);

        urlify(s);

    }
}