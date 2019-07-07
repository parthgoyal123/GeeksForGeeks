#include <bits/stdc++.h>
using namespace std;
int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this method */
int atoi(string str) {
    int n = str.size();
    int integer = (str[0] != '-') ? (str[0]-48) : 0;
    int sign = (str[0] == '-')? -1:1;
    for(int i =1; i<n; i++){
        if(str[i]<48 || str[i]>57){
            return -1;
        } else{
            integer = 10*integer + (str[i] - 48);
        }
    }
    return sign*integer;
}