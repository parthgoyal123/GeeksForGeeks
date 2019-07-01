#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        // string temp = s;
        // string words[n];
        // words[0] = s;

        // loop(i, 1, n){
        //     int d = n-i;
        //     reverse(temp.begin(), temp.begin() + d);
        //     reverse(temp.begin() + d, temp.end());
        //     reverse(temp.begin(), temp.end());
        //     words[i] = temp;
        //     temp = s;
        // }

        // loop(i, 0, n){
        //     cout << words[i] << " ";
        // }

        int store = 0;
        while(q--){
            int type;
            cin >> type;
            int k, i;
            if(type == 1){
                cin >> k;
                k = k%n;
                k = (store%n+k%n)%n;
                store = k;
                
            } else {
                cin >> i;
                int index = 0;
                char answer;
                int flag = 0;

                for(int k = n-store; k<n; k++){
                    answer = s[k];
                    if(i == index){
                        cout << answer << endl;
                        flag = 1;
                        break;
                    }
                    index++;
                    
                    // cout << word[index-1];
                }
                if(flag == 0){
                    for(int k = 0; k<n-store; k++){
                        answer = s[k];
                        if(i == index){
                            cout << answer << endl;
                            flag = 1;
                            break;
                        }
                        index++;
                    }
                }
            }            
        }
    }
}