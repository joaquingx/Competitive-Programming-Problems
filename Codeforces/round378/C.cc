#include <bits/stdc++.h>
using namespace std;
vector<int> v,q,nv;
vector< pair<int,char> > res;

bool comiendo(int l , int r,int curv)
{
  nv.clear();
  for(int i = l ; i <= r; ++i)
    nv.push_back(v[i]);
  char c;
  while(nv.size() > 1)
    {
      bool fue=1;
      int ans =-1;
      int n = nv.size();
      int k;
      for(int i = 0 ; i < n - 1 ; ++i)
	{
	  if(nv[i] > nv[i+1] or nv[i] < nv[i+1])
	    {
	      fue=0;
	      if(ans < nv[i]+nv[i+1])
		{
		  ans = nv[i] + nv[i+1];
		  if(nv[i] > nv[i+1])
		    {
		      c = 'R';
		      k = i;
		    }
		  else
		    {
		      c = 'L';
		      k = i+1;
		    }
		}
	    }
	} 
      if(fue)
	return 0;
      if(c == 'R')
	{
	  nv[k] = nv[k] + nv[k+1];
	  for(int j = k+1 ; j < n-1; ++j)
	    nv[j] = nv[j+1];
	}
      else
	{
	  nv[k-1] = nv[k-1] + nv[k];
	  for(int j = k ; j < n-1 ; ++j)
	    nv[j] = nv[j+1];
	}
      nv.resize(nv.size() - 1);
      res.push_back({k+curv,c});
    }
  return 1;
}

int main()
{
  int n,m; cin >> n;
  v.resize(n);
  for(int i = 0 ;i < n ; ++i)
    {
      cin >> v[i];
    }
  cin >> m;
  q.resize(m);
  for(int i = 0 ;i < m ; ++i)
    cin >> q[i];
 if(n == m)
   {
     bool is=1;
     for(int i = 0 ;i < n ; ++i)
       if(v[i] != q[i])
	 is=0;
     if(is)
       cout << "YES\n";
     else
       cout << "NO\n";
     return 0;
   }
 int idx= 0;
 int cur = q[idx],sum=0,first=0;
  for(int i = 0 ; i < n ; ++i)
    {
      sum += v[i];
      if(sum == cur)
	{
	  if(!comiendo(first,i,idx))
	    {
	      cout << "NO\n";
	      return 0;
	    }
	  // cout << first << " " << i << "< indices\n";
	  ++idx;
	  // if(idx > m)
	  //   {
	  //     cout << "NO\n";
	  //     return 0;
	  //   }
	  first = i+1;
	  cur = q[idx];
	  sum = 0;
	}
      if(sum > cur)
      	{
      	  cout << "NO\n";
      	  return 0;
      	}
    }
  // if(idx < m)
  //   {
  //     cout << "NO\n";
  //     return 0;
  //   }
  cout << "YES\n";
  for(int i = 0 ;i < res.size() ; ++i)
    cout << res[i].first+1 << " " << res[i].second << "\n";
  return 0;
}
