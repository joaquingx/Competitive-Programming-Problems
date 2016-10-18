#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;
vector< vector<int> > v;
int tns[MAXN+10];
int cnt[MAXN+10];
int n,m,canti,q,fst;

int give(int key)
{
  int c =0 ;
  for(int i = 1; i <= m ; ++i)
    {
      if(cnt[i] < key)
	{
	  ++c;
	}
    }
  return c;  
}

int givemin()
{
  int mini = 100000,idx;
  for(int i = 1 ; i <= m ; ++i)
    {
      if(mini > cnt[i])
	{
	  mini = cnt[i];
	  idx = i;
	}
    }
  return idx;
}

int main()
{
  int ans=0;
  cin >> n >> m;
  v.resize(m+1);
  memset(cnt,0,sizeof cnt);
  for(int i = 0; i < n ; ++i)
    {
      cin >> tns[i];
      if(tns[i] <= m)
	++cnt[tns[i]];
    }
  canti = n/m; q = n % m; fst = m - q;
  for(int i = 0 ; i < n ; ++i)
    {
      int dame = give(canti);
      if(dame > 0)
	{
	  if(tns[i] > m)
	    {
	      int k = givemin();
	      tns[i] = k;
	      ++ans;
	      ++cnt[k];
	    }
	  else if(cnt[tns[i]] > canti )
	    {
	      int k = givemin();
	      --cnt[tns[i]];
	      tns[i] = k;
	      ++ans;
	      ++cnt[k];
	    }
	}
    }
  cout << canti << " " << ans << "\n";
  for(int i = 0 ; i < n ; ++i)
    cout << tns[i] << " ";
  cout << "\n";
  return 0;
}
