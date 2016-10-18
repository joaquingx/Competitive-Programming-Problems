#include <bits/stdc++.h>
#define MAXN int(1e5+10)
using namespace std;
int p[MAXN],d[MAXN],mark[MAXN],hito[MAXN],m,n,cc=0;
set<int> rec;


bool sepuede(int fin)
{
  int cnt=0;
  memset(mark , 0, sizeof mark);
  memset(hito , 0 , sizeof hito);
  for(int i = fin ; i >= 0 ; --i)
    {
      if(d[i] != 0)
	{
	  if(!mark[d[i]])
	    {
	      mark[d[i]] = 1;
	      hito[i] = 1;
	      rec.insert(d[i]);
	    }
	}
    }

  for(int i = 1 ; i <= m ; ++i)
    {
      if(rec.find(i) == rec.end())
	return 0;
    }
  rec.clear();
  // for(int i = 0 ; i < n  ; ++i)
  //   cout << hito[i]<< "\n";
  for(int i = 0 ; i <= fin ; ++i)
    {
      if(hito[i])
	{
	  // cout << " " << d[i] << " "  << p[d[i]] << " " << cnt << "\n";
	  if(cnt < p[d[i]])
	    return 0;
	  cnt -= p[d[i]];
	}
      else
	++cnt;
    }
  return 1;

}

int bs(int ini , int fin )
{
  while(fin - ini > 0)
    {
      ++cc;
      if(cc > 90)
	return -1;
      int mid = (fin + ini)/2;
      if(!sepuede(mid))
	ini =  mid + 1;
      else
	{
	  // cout << "sepudo\n";
	  // cout << mid << "\n";
	  fin = mid;
	}
    }
  return ini;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  for(int i = 0 ; i < n;  ++i)
    cin >> d[i];
  for(int i = 1 ; i <= m ; ++i)
    cin >> p[i];
  int res = bs(0,n+1);
  if(res > n or res == -1)
    cout << -1 << "\n";
  else
    cout << res+1 << "\n";
  return 0;
}
