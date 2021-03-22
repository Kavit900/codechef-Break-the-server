#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define INF 1e18

lli calc(lli N, lli E, lli H, lli A, lli B, lli C) {
  lli ans = INF;

  if(N <= 0) {
    return 0;
  }

  // case 1, take all omelletes
  if(E >= 2*N) {
    ans = min(ans, A*N);
  }

  // case 2, take all milshakes
  if(H >= 3*N) {
    ans = min(ans, B*N);
  }

  // case 3, take all cakes
  if(H>=N && E >= N) {
    ans = min(ans, C*N);
  }

  // case 4, take milkshake and cake 
  if((H-N)/2 >= 1 && ((H-N)/2 >= N-E)) {
    if(B<C) {
      lli t = min(N-1, (H-N)/2);
      ans = min(ans, t*(B-C) + N*C);
    } else {
      lli t = max((lli)1, (N-E));
      ans = min(ans, t*(B-C) + N*C);
    }
  }

  // case 5 omellete and milkshake
  if(E/2 >= 1 && E/2 >= (3*N-H+2)/3) {
    if(A<B) {
      lli t = min(N-1, E/2);
      ans = min(ans, t*(A-B) + N*B);
    } else {
      lli t = max((lli)1, (3*N-H+2)/3);
      ans = min(ans, t*(A-B) + N*B);
    }
  }

  // case 6 omellte and cake 
  if((E-N) >= 1 && (E-N) >= N-H) {
    if(A<C) {
      lli t = min(N-1, E-N);
      ans = min(ans, t*(A-C) + N*C);
    } else {
      lli t = max((lli)1, N-H);
      ans = min(ans, t*(A-C) + N*C);
    }
  }

  // case 7 omellte, milkshake and cake 
  if(N>=3 && E>=3 && H>=4) {
    ans = min(ans, (A+B+C) + calc(N-3, E-3, H-4, A,B,C));
  }

  return ans;
}

int main()
{
  lli T;
  cin>>T;
  while(T--) {
    lli N,E,H,A,B,C;
    cin>>N>>E>>H>>A>>B>>C;
    lli ans = calc(N,E,H,A,B,C);

    if(ans == INF) {
      cout<<-1<<endl;
    } else {
      cout<<ans<<endl;
    }
  }
  return 0;
}

/*
1
4 5 5 3 2 1
*/