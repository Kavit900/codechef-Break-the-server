#include <bits/stdc++.h>

using namespace std;

int main()
{
  int T;
  cin>>T;
  while(T--) {
    string s;
    cin>>s;
    set<char> u;

    for(int i=0; i<s.length(); i++) {
      u.insert(s[i]);
    }

    if(u.size() == 3) {
      cout<<"YES"<<endl;
    } else {
      cout<<"NO"<<endl;
    }
  }
  return 0;
}