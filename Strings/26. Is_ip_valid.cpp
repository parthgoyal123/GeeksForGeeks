#include <bits/stdc++.h>
using namespace std;
int isValid(char *);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		char s[10000];
		cin>>s;
		cout<<isValid(s)<<endl;
	}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* The function returns 1 if 
IP string is valid else return 0 
You are required to complete this method */

bool checkNum(string &s) {
    
    if(s.size() == 1) return true;
    if(s.size() == 2 && s[0] != '0') return true;
    if(s.size() == 2 && s[0] == '0') return false;
    
    if(s.size() > 3) return false;
    if(s.size() == 3) {
        if(s[0] == '0') return false;
        if((s[0]-'0') >= 3) return false;
        if((s[0]-'0') < 2) return true;
        if(s[0] == '2' && (s[1] - '0') <= 5 && (s[2] - '0') <= 5) return true;
        return false;
    }
}

int isValid(char *ip)
{
    int n = strlen(ip);
    string s = "";
    int count_dot = 0;
    
    for(int i = 0; i<n; i++) {
        if(ip[i] == '.') {
            if (!checkNum(s)) {
                return false;
            }
            s = "";
            count_dot++;
        }
        else if (ip[i] != '.') {
            if(ip[i] >= '0' && ip[i] <= '9')
                s = s + ip[i];
            else return false;
        }
        
        if(ip[i] == '.' && ip[i+1] == '.') return false;
    }
    if(!checkNum(s)) return false;
    if(count_dot != 3) return false;
    return true;
}