#include <bits/stdc++.h>
using namespace std;
vector< pair<int,int> > vii;

int main()
{
  ios_base::sync_with_stdio(0);
  string pat;
  int n; cin >> n;
  cin >> pat;
  char act = pat[0];
  int cnt = 1;
  for(int i = 1 ; i < n ; ++i )
    {
      if(pat[i] != act)
	{
	  vii.push_back({act-'A' , cnt});
	  cnt=0;
	  act = pat[i];
	}
      ++cnt;
      if(i == n-1)
	{
	  vii.push_back({act-'A' , cnt});
	}
    }
  // for(int i = 0 ; i < vii.size() ; i++)
  //   {
  //     cout << vii[i].first << " " << vii[i].second<<"\n";
  //   }
  int a,b,na,nb;
  if(vii[0].first == 0)
    {
      a = 0;
      b = 1;
    }
  else
    {
      a = 1;
      b = 0;
    }
  for(int i = 1 ; i < vii.size() ; ++i)
    {
      // cout << vii[i].first << " " << vii[i].second<<"\n";
      if(vii[i].first == 0)
	{
	  na = min( a, b + 1);
	  nb = min(b + vii[i].second, a + 1);
	}
      else
	{
	  na = min(a + vii[i].second, b + 1);
	  nb = min(b,a+1);
	}
      a = na;
      b = nb;
    }
  cout << a << "\n";
  return 0;
}
