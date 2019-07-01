#include<bits/stdc++.h>
using namespace std;
bool isIsogram(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        string s;
        cin>>s;
        
        cout<<isIsogram(s)<<endl;
        
    }
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
//Complete this function
bool isIsogram(string s)
{
    int hash[26] = {0};
    for(int i = 0; i<s.size(); i++){
        if(hash[s[i] - 'a'] == 0){
            hash[s[i] - 'a']++;    
        }
        else{
            return false;
        }
        
    }
    return true;
    
}