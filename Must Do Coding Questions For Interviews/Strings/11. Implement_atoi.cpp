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
int atoi(string str)
{
    int val = 0;
    
    // check first character
    int pos = (str[0] == '-')? -1: 1;
    
    for(int i = (pos == -1)? 1:0; i<str.length(); i++) {
            
        // check for valid integer
        if(str[i] >= '0' && str[i] <= '9')
            val = 10*val + (str[i] - '0');
            
        // return -1, if not valid integer string
        else return -1;
    }
    
    return pos*val;
}