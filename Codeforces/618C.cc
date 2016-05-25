#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define MAXN ld(4*1e18+5)
#define N int(1e5+10)
typedef complex<ld> point;
#define x real()
#define y imag()
vector<point> triangle(4);
vector< pair< point , int> > pp(N);
vector< point > tt(3);
vector<int> ans(3);

bool compare(pair<point,int> & a , pair<point,int> & b)
{
  if(a.first.x  == b.first.x)
    return (a.first.y < b.first.y);
  return (a.first.x < b.first.x);
}

bool comptan(point & a, point & b)
{
  return ( atan2(a.y,a.x) < atan2(b.y,b.x) );
}

ld area()
{
  // for(int i = 0 ; i < triangle.size() ; ++i)
  //   cout << triangle[i] << " <--- Triangle\n";
  ld acum=0;
  for(int i = 0 ; i < 3 ; ++i)
    {
      acum += triangle[i].x* triangle[i+1].y - triangle[i].y*triangle[i+1].x;
    }
  return abs(acum/2);
}



int main()
{
  ios_base::sync_with_stdio(0);
  int n; cin >> n;
  for(int  i = 0 ; i < n ; ++i)
    {
      cin >> pp[i].first.x >> pp[i].first.y;
      pp[i].second = i;
    }
  sort(pp.begin(),pp.begin()+n,compare);
  ld mini = MAXN,rpta;
  ans[0] = pp[0].second;
  ans[1] = pp[1].second;
  // for(int i = 0 ; i < n ; ++i)
  //   {
  //     cout << pp[i].first << "\n";
  //   }
  for(int i = 2 ; i < n ; ++i)
    {
      tt[0] = pp[0].first;
      tt[1] = pp[1].first;
      tt[2] = pp[i].first;
      sort(tt.begin(),tt.end(),comptan);
      triangle[0] = tt[0];
      triangle[1] = tt[1];
      triangle[2] = tt[2];
      triangle[3] = tt[0];
      rpta = area();
      // cout << rpta << "\n";
      if(rpta != 0) // no colineares
	{
	  if(rpta < mini)
	    {
	      ans[2] = pp[i].second;
	      mini = rpta;
	    }
	}
    }
  for(int i = 0 ; i < ans.size() ; ++i)
    cout << ans[i]+1 << " ";
  cout << "\n";
  return 0;
}
