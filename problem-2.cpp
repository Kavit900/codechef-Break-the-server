#include <bits/stdc++.h>

using namespace std;

int main()
{
  int T;
  cin>>T;
  while(T--) {
    int n;
    cin>>n;

    // 0 - stop, 1 - running;
    int state = 0;
    
    int flag = 1;
    for(int i=0; i<n; i++) {
      string s;
      cin>>s;
      if(s=="stop" && state == 0) {
        flag = 0;
      } if(s=="stop") {
        state = 0;
      } else {
        state = 1;
      }
    }

    if(flag) {
      cout<<"200"<<endl;
    } else {
      cout<<"404"<<endl;
    }

  }
  return 0;
}