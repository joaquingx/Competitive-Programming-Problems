#include <bits/stdc++.h>
#define MAXN int(5*1e5+10)
using namespace std;
typedef long long ll;
pair<ll,ll> a[MAXN],rey;
pair<ll,char> dir[9];

ll manh(pair<ll,ll> point)
{
  return abs(point.first) + abs(point.second);
}


void damelo(pair<ll,ll> res , int tt, char type)
{
  // cout << res.first << "  " << res.second << "\n";
  if(manh(res) < dir[tt].first)
    {
      dir[tt].first = manh(res);
      dir[tt].second = type;
    }
}

void asignar(pair<ll,ll> point, char type)
{
  pair<ll,ll> res;
  res.first = rey.first - point.first;
  res.second = rey.second - point.second;
  if(abs(res.first) == abs(res.second))
    {
      if(res.first < 0 and res.second < 0)
	damelo(res,0,type);
      if(res.first < 0 and res.second > 0)
	damelo(res,1,type);
      if(res.first > 0 and res.second < 0)
	damelo(res,2,type);
      if(res.first > 0 and res.second > 0)
	damelo(res,3,type);
    }
  if(res.first == 0 and res.second > 0)
    damelo(res,4,type);
  if(res.first == 0 and res.second < 0)
    damelo(res,5,type);
  if(res.first > 0 and res.second == 0)
    damelo(res,6,type);
  if(res.first < 0 and res.second == 0)
    damelo(res,7,type);
    
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n; cin >> n;
  cin >> rey.first >> rey.second;
  for(int i = 0 ;i < 9 ; ++i)
    {
      dir[i].first = 100000000000;
      dir[i].second = 'K';
    }
  for(int i = 0;i <  n ; ++i)
    {
      char c; cin >> c;
      cin >> a[i].first >> a[i].second;
      asignar(a[i],c);
    }
  bool check =0;
  for(int i = 0 ;i < 8 ; ++i)
    {
      // cout << dir[i].first << " " << dir[i].second << "\n";
      if(i <= 3)
	{
	  if(dir[i].second == 'Q' or dir[i].second == 'B')
	    check=1;
	}
      else
	{
	  if(dir[i].second == 'R' or dir[i].second == 'Q')
	    check=1;
	}
    }
  if(check)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
