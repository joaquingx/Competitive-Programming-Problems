#include <bits/stdc++.h>
#define MAXN int(1e5+10)
using namespace std;
vector<int> v(MAXN);
vector<bool> mark(MAXN,0);
vector<int> nodos;
int n;
int next(int i)
{
  if(i >= n-1)
     i = 0;
  else
    ++i;
  return i;
}
int prev(int i)
{
  if(i <= 0)
    i = n-1;
  else
    --i;
  return i;
}


int main()
{
  cin >> n ;
  for(int i = 0 ; i < n ; ++i)
    cin >> v[i];
  for(int i = 0 ; i < n ;++i)
    {
      // cout << i << "\n";
      if(!mark[i] and v[i] != 0)
	{
	  nodos.push_back(v[i]);
	  mark[i]=1;
	  int j = i;
	  // derecha
	  // cout << i << "\n";
	  while(v[next(i)] != 0)
	    {
	      // cout << i << " <--- adentro\n";
	      nodos.back() += v[next(i)];
	      i = next(i);
	      mark[i]=1;
	    }
	  // cout << "mi j:" << j << "  "<<prev(j) << "<-- lo que tengo\n";
	  while(v[prev(j)] != 0)
	    {
	      // cout << v[prev(j)] << "<-- lo que tengo";
	      nodos.back() += v[prev(j)];
	      j = prev(j);
	      mark[j]=1;
	    }
	}
    }
  for(int i = 0 ; i < nodos.size() ; ++i)
    cout << nodos[i] << "\n";
}
