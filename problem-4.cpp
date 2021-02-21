#include <bits/stdc++.h>

using namespace std;

#define lli long long int

int main()
{
  int T;
  cin>>T;
  while(T--) {
    int n;
    cin>>n;

    vector<int> height;
    vector<int> iq;

    for(int i=0; i<n; i++) {
      int t;
      cin>>t;
      height.push_back(t);
    }

    for(int i=0; i<n; i++) {
      int t;
      cin>>t;
      iq.push_back(t);
    }

    int dp[n];
    
    for(int i=0; i<n; i++) {
      dp[i] = 1;
    }

    for(int i=1; i<n; i++) {
      for(int j=0; j<i; j++) {
        if(height[j] < height[i] && iq[j] > iq[i]) {
          dp[i] = max(dp[i], dp[j]+1);
        }
      }
    }

    int maxAns = 0;

    for(int i=0; i<n; i++) {
      maxAns = max(maxAns, dp[i]);
    }

    cout<<maxAns<<endl;
  }
  return 0;
}