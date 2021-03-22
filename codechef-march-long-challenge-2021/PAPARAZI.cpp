#include <bits/stdc++.h>

using namespace std;

#define lli long long int
const double lowest_double = -DBL_MAX;

int main()
{
  lli T;
  cin>>T;
  while(T--) {
    lli N;
    cin>>N;
    vector<pair<lli, lli>> heights;

    stack<pair<lli, lli>> st;

    for(lli i=0; i<N; i++) {
      lli t;
      cin>>t;
      heights.push_back(make_pair(i+1, t));
    }

    lli max_ans = 1;
    st.push(heights[0]);
    st.push(heights[1]);
    lli index = st.size();

    for(lli i=2; i<N; i++) {
      while(st.size() >= 2) {
        pair<lli, lli> topFirst = st.top();
        st.pop();

        pair<lli, lli> topSecond = st.top();
        double slope1 = ((double)topFirst.second - (double)topSecond.second) / ((double)topFirst.first - (double)topSecond.first);

        double slope2 = ((double)heights[i].second - (double)topFirst.second) / ((double)heights[i].first - (double)topFirst.first);

        if(slope1 <= slope2) {
          index--;
        } else {
          st.push(topFirst);
          break;
        }
      }

      st.push(heights[i]);
      index++;
      pair<lli, lli> topFirst = st.top();
      st.pop();

      max_ans = max(max_ans, topFirst.first - st.top().first);
      st.push(topFirst);
    }
    cout<<max_ans<<endl;
  }
  return 0;
}