#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  multiset<int> aux;
  set<int> rec;
  vector<int> v,r,where;
  int n , k ,l; cin >> n >> k;
  v.resize(n),where.resize(n);r.resize(k);
  for(int i = 0;i < n ; ++i)
    {
      cin >> v[i];
    }
  for(int i = 0; i < k ; ++i)
    {
      cin >> l >> r[i];
      --r[i];
      // cout << r[i] << "\n";
      where[r[i]] = l;
    }
  for(int i= 0 ;i < k ; ++i)
    {
      while(!rec.empty() and  *(rec.begin()) < r[i] )
	rec.erase(rec.begin());
      rec.insert(r[i]);
    }
  rec.insert(-1);
  // cout << *(rec.rbegin()) << "\n";
  for(int i = 0;i <= *(rec.rbegin()) ; ++i)
    {
      aux.insert(v[i]);
    }
  auto it = rec.rbegin();
  int last = *(it);
  ++it;
  std::multiset<int>::iterator borr;
  for(; it != rec.rend(); ++it)
    {
      // cout << last << " " << (*it) << "\n";
      for(int i  = last ; i > (*it)  ; --i )
      	{
      	  if(where[last] == 2)
      	    {
      	      v[i] = (*aux.begin());
	      borr = aux.begin() ;
	      aux.erase(borr); 
      	    }
      	  else
      	    {
      	      v[i] = *(aux.rbegin());
	      borr = (aux.end());
	      --borr;
	      aux.erase(borr); 
      	    }
      	}
      last = *(it);
    }
  for(int i= 0; i < n ; ++i)
    cout << v[i] << " ";
  cout << "\n" ;
  return 0;
}
