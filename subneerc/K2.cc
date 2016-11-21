#include <bits/stdc++.h>
#define MAXN int(2*1e5+100)
using namespace std;
vector< vector<int> > AdjT;
vector<int> ans;
int cnt[MAXN];
class compare_1 { // simple comparison function
   public:
      bool operator()(const int x,const int y) { return x > y; } // returns x>y
};


set<int,compare_1> sinks;

int main()
{
  memset(cnt,0,sizeof cnt);
  int n,m,l,r; cin >> n >> m;
  AdjT.resize(n);
  for(int i = 0 ;i < m ; ++i)
    {
      cin >> l >> r;
      --l;--r;
      // Adj[l].push_back(r);      
      AdjT[r].push_back(l);
      ++cnt[l];
    }
  for(int i = 0 ;i < n ; ++i)
    {
      if(cnt[i] == 0)
	sinks.insert(i);
    }
  while(!sinks.empty())
    {
      // cout << "aaa\n";
      int u = *(sinks.begin());
      sinks.erase(sinks.begin());
      ans.push_back(u);
      for(int v : AdjT[u])
	{
	  --cnt[v];
	  if(cnt[v] == 0)
	    sinks.insert(v);
	}
    }
  reverse(ans.begin(), ans.end());
  for(int i= 0 ; i < n ; ++i)
    cout << ans[i]+1 << " ";
  cout << "\n";
  return 0;
}
