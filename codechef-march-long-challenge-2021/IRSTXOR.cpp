#include <bits/stdc++.h>

using namespace std;
#define lli long long int

vector<int> calcBits(lli x) {
  vector<int> ans;
  while(x>0) {
    int r = x%2;
    x /= 2;
    ans.push_back(r);
  }
  reverse(ans.begin(),ans.end());
  return ans;
}

lli calcNum(vector<int> num) {
  lli x = 0;
  lli p = 1;
  for(int i=num.size()-1; i>=0; i--) {
    x += num[i]*p;
    p *= 2;
  }
  return x;
}

int main()
{
  lli T;
  cin>>T;
  while(T--) {
    lli C;
    cin>>C;
    if(C==1) {
      cout<<0<<endl; 
    } else {
      lli p = 1;
      while(p <= C) {
        p = p*2;
      } 
      p--;
      vector<int> cbits = calcBits(C);
      vector<int> abits = calcBits(p);

      // cout<<"printing C bits"<<endl;
      // for(int i=0; i<cbits.size(); i++) {
      //   cout<<cbits[i]<<" ";
      // }
      // cout<<endl;

      vector<int> bbits;

      if(cbits[0] == 1) {
        bbits.push_back(1);
      } else {
        bbits.push_back(0);
      }

      for(int i=1; i<cbits.size(); i++) {
        if(cbits[i] == 1) {
          bbits.push_back(0);
        } else {
          bbits.push_back(1);
        }
      }

      // cout<<"printing B bits"<<endl;
      // for(int i=0; i<bbits.size(); i++) {
      //   cout<<bbits[i]<<" ";
      // }
      // cout<<endl;

      lli numB = calcNum(bbits);
      lli numA = numB ^ C;

      //cout<<C<<" "<<numB<<" "<<numA<<endl;

      cout<<numA * numB<<endl;
    }
  }
  return 0;
}

/*
1
10
*/