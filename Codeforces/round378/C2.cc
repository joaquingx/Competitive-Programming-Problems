#include <bits/stdc++.h>
using namespace std;
vector<int> v,q,nuevo;
vector< pair < int , char > >  ans;
int n , m;


bool eating(int first, int second, int curv)
{
  int mejor,tam,pos;
  char c;
  nuevo.clear();
  for(int i = first ;i <= second ; ++i)
    nuevo.push_back(v[i]);
  while(nuevo.size() > 1)
    {
      pos = -1;
      mejor = -1;
      tam = nuevo.size();
      for(int i = 0 ;i < tam - 1; ++i)
	{
	  if(nuevo[i] != nuevo[i+1])
	    {
	      if(mejor < nuevo[i] + nuevo[i+1])
		{
		  mejor = nuevo[i] + nuevo[i+1];
		  if(nuevo[i+1] > nuevo[i])
		    c = 'L';
		  else
		    c = 'R';
		  pos = i;
		}
	    }
	}
      if(pos == -1)
	return 0;
      else
	{
	  // cout << pos << " " << c << "\n";
	  nuevo[pos] = nuevo[pos] + nuevo[pos + 1];
	  for(int j = pos+1  ; j < tam -1; ++j)
	    nuevo[j] = nuevo[j+1];
	  if(c == 'R')
	    ans.push_back({ curv+pos,c });
	  else
	    ans.push_back({curv+pos+1,c});
	}
      nuevo.resize(tam-1);
    }
  return 1;
}



int main()
{
  cin >> n ;
  v.resize(n);
  for(int i = 0 ; i < n ; ++i)
    cin >> v[i];
  cin >> m;
  q.resize(m);
  for(int i= 0 ; i < m ; ++i)
    cin >> q[i];
  int idx = 0,sum=0,ptr=0;
  for(int i = 0 ; i < n ; ++i)
    {
      sum += v[i];
      if(sum > q[idx] or idx == m)
	{
	  cout << "NO\n";
	  return 0;
	}
      if(sum == q[idx])
	{
	  // cout << sum << "\n";
	  if(!eating(ptr,i,idx))
	    {
	      cout << "NO\n";
	      return 0;
	    }
	  ++idx;
	  ptr = i+1;
	  sum = 0;
	}
    }
  if(idx < m)
    {
      cout << "NO\n";
      return 0;
    }
  cout << "YES\n";
  for(int i= 0; i < ans.size() ; ++i)
    cout << ans[i].first+1 << " " << ans[i].second  << "\n";
  return 0;
}
