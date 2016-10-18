#include <bits/stdc++.h>
#define MAXN int(1e5*2+10)
using namespace std;
int p[MAXN],mark[MAXN],size[MAXN],ans[MAXN];
vector<pair<int , int > > a;

void dsuCreate(int x)
{
  p[x] = x;
  size[x] = 1;
}

int dsuFind(int v)
{
  return (v == p[v] ? v : p[v] = dsuFind(p[v]) );
}

void dsuUnion(int u , int v)
{
  u = dsuFind(u);
  v = dsuFind(v);
  p[v] = u;
  size[u] += size[v];
}


int main()
{
  memset(mark,0,sizeof mark);
  int n;cin >> n;
  a.resize(n);
  for(int i = 0 ;i < n ; ++i)
    {
      cin >> a[i].first;
      a[i].second = i;
    }
  sort(a.begin(), a.end() , greater< pair<int,int> > ());
  for(int i= 0 ; i < n ; ++i)
    dsuCreate(i);
  int cnt=1;
  for(int i = 0 ;i < n ; ++i)
    {
      int pos = a[i].second;
      int val = a[i].first;
      mark[pos] = 1;
      if(pos and mark[pos-1])
	dsuUnion(pos,pos-1);
      if(pos < n-1 and mark[pos + 1])
	dsuUnion(pos , pos + 1);
      int sz = size[dsuFind(pos)];
      while(cnt <= sz)
	{
	  ans[cnt] = val;
	  ++cnt;
	}	
    }
  for(int i = 1 ; i <= n ; ++i)
    cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
