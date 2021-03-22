#include <bits/stdc++.h>

using namespace std;

int main()
{
  int T;
  cin>>T;
  while(T--) {
    int n;
    cin>>n;
    vector<int> A;
    for(int i=0; i<n; i++) {
      int t;
      cin>>t;
      A.push_back(t);
    }

    sort(A.begin(), A.end());

    int start = 1;
    int diff = 0;
    int winner = 0;
    int flag = 0;
    for(int i=0; i<A.size(); i++) {
      if(A[i] > start) {
        winner = 1;
        flag = 1;
        break;
      } else {
        diff += start - A[i];
      }
      start++;
    }

    if(!flag) {
      if(diff %2 == 0) {
        cout<<"Second"<<endl;
      } else {
        cout<<"First"<<endl;
      }
    } else {
      cout<<"Second"<<endl;
    }
  }
  return 0;
}