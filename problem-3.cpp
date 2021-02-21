#include <bits/stdc++.h>

using namespace std;

#define lli long long int

int main()
{
  int T;
  cin>>T;
  while(T--) {
    lli N,K;
    cin>>N>>K;

    vector<lli> laddu;

    for(int i=0; i<N; i++) {
      int t;
      cin>>t;
      laddu.push_back(t);
    }

    sort(laddu.begin(), laddu.end());

    int start = 0;
    int end = K-1;

    lli ans = 1e9+1;

    while(end < N) {
      lli diff = laddu[end] - laddu[start];
      ans = min(ans, diff);
      start++;
      end++;
    }

    cout<<ans<<endl;
  }
  return 0;
}