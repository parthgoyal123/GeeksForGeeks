#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

int getindex(char temp){
    switch(temp){
        case '!':{
            return 1;
            break;
        }case '#':{
            return 2;
            break;
        }case '$':{
            return 3;
            break;
        }case '%':{
            return 4;
            break;
        }case '&':{
            return 5;
            break;
        }case '*':{
            return 6;
            break;
        }case '@':{
            return 7;
            break;
        }case '^':{
            return 8;
            break;
        }case '~':{
            return 9;
            break;
        }
    }
}

char getcharacter(int k){
    switch(k){
        case 1:{
            return '!';
            break;
        }case 2:{
            return '#';
            break;
        }case 3:{
            return '$';
            break;
        }case 4:{
            return '%';
            break;
        }case 5:{
            return '&';
            break;
        }case 6:{
            return '*';
            break;
        }case 7:{
            return '@';
            break;
        }case 8:{
            return '^';
            break;
        }case 9:{
            return '~';
            break;
        }
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_map<char, pair<int, int>> hash;
        
        loop(i,0,n){
            char temp;
            cin >> temp;
            int k = getindex(temp);
            hash[temp] = make_pair(k, 1);
            // cout << hash[temp].first << " " << temp << " " << hash[temp].second << endl;
        }
        int store[9] = {0};
        
        int index = 0;
        loop(i,0,n){
            char temp;
            cin >> temp;
            // cout << hash[temp].first << " " << temp << " " << hash[temp].second << endl;
            if(hash[temp].second == 1){
                store[index++] = hash[temp].first;
            }
        }
        sort(store, store+9);
        // loop(i,0,9){
        //     cout << store[i] << " ";
        // } cout << endl;
        index = 0;
        while(index<9 && store[index] == 0){
            index++;
        }

        loop(i, index, 8){
            char c = getcharacter(store[i]);
            cout << c << " ";
        } cout << getcharacter(store[8]);

        cout << endl;
        loop(i, index, 8){
            char c = getcharacter(store[i]);
            cout << c << " ";
        } cout << getcharacter(store[8]);

        cout << endl;
        hash.clear();
    }
}