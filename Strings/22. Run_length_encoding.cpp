#include <bits/stdc++.h>
using namespace std;
char *encode(char *src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		char str[10000];
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this function */
char *encode(char *src)
{
    int n = strlen(src);
    // cout << n << endl;
    
    char *ans = new char[2*n +1];
    int index = 0;
    
    for(int i = 0; i<n; i++) {
        int count = 1;
        while(i < n-1 && src[i] == src[i+1])  {
            count++;
            i++;
        }
        ans[index++] = src[i];
        ans[index++] = count + '0';
    }
    
    ans[index] = '\0';
    // delete src;
    return ans;
}     