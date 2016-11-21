#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-5
typedef pair<double,double> par;

int main()
{
  par p[3];
  double ladoa,ladob,ladoc,A,nr,rad;
  for(int i = 0 ;i < 3 ; ++i)
    {
      cin >> p[i].first >> p[i].second;
    }
  cin >> rad;
  ladoa = (p[0].first-p[1].first)*(p[0].first-p[1].first) + (p[0].second - p[1].second)* (p[0].second - p[1].second);
  ladob = (p[0].first-p[2].first)*(p[0].first-p[2].first) + (p[0].second - p[2].second)*(p[0].second - p[2].second);
  ladoc = (p[1].first-p[2].first)*(p[1].first-p[2].first) + (p[1].second - p[2].second)*(p[1].second - p[2].second);
  A = 0.25 * sqrt(4 * ladoa*ladob - ((ladoa + ladob - ladoc)*(ladoa + ladob - ladoc)));
  double change =1;
  nr = 2*A/(sqrt(ladoa)+sqrt(ladob)+sqrt(ladoc));
  // cout << rad << " " << nr << "\n";
  // if(rad - nr >= EPS)
  //   change = -1;
  if(abs(rad - nr) <= EPS)
    {
      cout << 0 << "\n";
      return 0;
    }
  printf("%.9f\n",((nr - rad)/rad)*100);
  return 0;
}
