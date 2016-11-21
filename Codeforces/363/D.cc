#include <bits/stdc++.h>
using namespace std;
vector<int> p,rating,v,ans,flag;
set<int> s;

void dsuCreate(int u)
{
  p[u] = u;
  rating[u] = 0;
}

int dsuFind(int v)
{
  return (v == p[v] ? v : p[v] = (dsuFind(p[v])) );
}

void dsuUnion(int u , int v)
{
  u = dsuFind(u);
  v = dsuFind(v);
  p[u] = v;
  // if(rating[u] > rating[v])
  //   p[v] = u;
  // else
  //   if(rating[u] == rating[v])
  //     {
  // 	p[u] = v;
  // 	++rating[u];
  //     }
  //   else
  //     p[u] = v;  
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n ,dif=0,parent; cin >> n;
  p.resize(n);rating.resize(n);v.resize(n);flag.assign(n,0);
  for(int i = 0 ;i < n ; ++i)
    dsuCreate(i);
  for(int i = 0 ;i < n; ++i)
    {
      cin >> v[i];
      --v[i];

      if(dsuFind(v[i]) != dsuFind(i))
	{
	  dsuUnion(i,v[i]);
	}
      else
	if(v[i] != i)
	  {
	    flag[i] = 1;
	  }
    }
  for(int i = 0 ;i < n ; ++i)
    {
      if(s.find(dsuFind(i)) == s.end())
	{
	  s.insert(dsuFind(i));
	}
    }
  parent = (*s.begin());
  if(s.size() > 1)
    {
      for(auto it = s.begin() ; it != s.end() ; ++it)
	if(!flag[(*it)]) {
	  parent = (*it);
	  break;
	}
    }
  // cout << s.size()-1 << "\n";
  for(int i = 0 ;i < n ; ++i)
    {
      if(s.find(i) == s.end())
	ans.push_back(v[i]+1);
      else
	ans.push_back(parent+1);;
      if(ans[i]-1 != v[i])
	++dif;
    }
  cout << dif << "\n";
  for(int i = 0 ;i < n ; ++i)
    {
      cout << ans[i] << " ";
    }
  cout << "\n";
  return 0;
}
