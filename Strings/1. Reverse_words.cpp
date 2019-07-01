#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

void reverse(char *s, int start, int end){

    while(start<end){
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        char sentence[2000];
        int ch;
        int index = 0;

        while((ch = getchar()) != EOF && ch != '\n'){
            sentence[index++] = ch;
            sentence[index] = '\0';
        }
        int length = index;

        int start_of_word = 0;
        int end_of_word = -1;

        loop(i, 0, index+1){
            if(sentence[i] != '\0' && sentence[i] != '.'){
                end_of_word ++;
            }
            if(sentence[i] == '.' || sentence[i] == '\0'){
                // cout << start_of_word << " " << end_of_word << " " << i << endl;
                reverse(sentence, start_of_word, end_of_word);
                start_of_word = i+1;
                end_of_word = i;
            }
        }
        reverse(sentence, 0, length-1);
        cout << sentence << endl;
        
    }
}