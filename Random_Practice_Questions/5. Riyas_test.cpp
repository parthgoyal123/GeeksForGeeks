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
        string s;
        cin >> s;

        map<char, int> dist1;
        map<char, int> dist2;

        if(s.size()%2 == 0){
            loop(i,0,s.size()/2){
                dist1[s[i]]++;
            }
            loop(i, s.size()/2, s.size()){
                dist2[s[i]]++;
            }

            if(dist1.size() != dist2.size()){
                cout << "NO" << endl;
            } 
            else{
                map<char, int> :: iterator it1 = dist1.begin();
                map<char, int> :: iterator it2 = dist2.begin();
                int len = dist1.size();
                int flag = 0;
                while(it1 != dist1.end() && it2 != dist2.end()){
                    // cout << it1->first << " " << it1->second << endl;
                    // cout << it2->first << " " << it2->second << endl;

                    if((it1->first != it2->first) || (it1->second != it2->second)){
                        cout << "NO" << endl;
                        flag = 1;
                        break;
                    }
                    it1++;
                    it2++;
                }
                if(!flag){
                    cout << "YES" << endl;
                }
            }
        }
        else{
            loop(i,0,s.size()/2){
                dist1[s[i]]++;
            }
            loop(i, s.size()/2+1, s.size()){
                dist2[s[i]]++;
            }

            if(dist1.size() != dist2.size()){
                cout << "NO" << endl;
            } 
            else{
                map<char, int> :: iterator it1 = dist1.begin();
                map<char, int> :: iterator it2 = dist2.begin();
                int len = dist1.size();
                int flag = 0;
                while(it1 != dist1.end() && it2 != dist2.end()){
                    // cout << it1->first << " " << it1->second << endl;
                    // cout << it2->first << " " << it2->second << endl;

                    if((it1->first != it2->first) || (it1->second != it2->second)){
                        cout << "NO" << endl;
                        flag = 1;
                        break;
                    }
                    it1++;
                    it2++;
                }
                if(!flag){
                    cout << "YES" << endl;
                }
            }
        }

        dist1.clear();
        dist2.clear();
        
    }
}

// ========== BETTER =============== //

// using namespace std;
// typedef long long ll;

// int main()
//  {
// 	int t,n;
// 	cin>>t;
// 	while(t--)
// 	{
// 	    string s;
// 	    cin>>s;
// 	    int hash[26]={0};
// 	    int i=0;
// 	    for(;i<s.size()/2;i++)
// 	    {
// 	        hash[s[i]-'a']++;
// 	    }
// 	    if(s.size()%2==1) i++;
// 	    while(i<s.size())
// 	    {
// 	        hash[s[i]-'a']--;
// 	        i++;
// 	    }
	    
// 	    for(i=0;i<26;i++)
// 	    {
// 	        if(hash[i]!=0) break;
// 	    }
// 	   if(i==26) cout<<"YES\n";
// 	   else cout<<"NO\n";
	
// 	}
// 	return 0;
// }