#include <bits/stdc++.h>
#define MAXN int(1e5+10)
using namespace std;

struct caca{
  int l1,l2,l3;
};

map< pair<int,int>, pair<int,int> > mapa;


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  caca v[MAXN];
  int n ; cin >> n;
  for(int i = 0 ; i < n ; ++i)
    {
      cin >> v[i].l1 >> v[i].l2 >> v[i].l3;
    }
  int ans = -1,mini;
  vector<int> k;
  for(int i = 0 ;i < n ; ++i)
    {
      mini = min(v[i].l1,min(v[i].l2,v[i].l3));
      if(ans < mini)
	{
	  k.clear();
	  ans = mini;
	  k.push_back(i);	  
	}
    }
  for(int i =0  ;i < n ; ++i)
    {
      int l1 = v[i].l1,l2 = v[i].l2, l3=v[i].l3;
      vector< pair< pair<int,int >,int >  > perm;
      perm.clear();
      perm.push_back( { {l1,l2} , l3 } );
      perm.push_back( { {l2,l1} , l3 } );
      perm.push_back( { {l1,l3} , l2 } );
      perm.push_back( { {l3,l1} , l2 } );
      perm.push_back( { {l2,l3} , l1 } );
      perm.push_back( { {l3,l2} , l1 } );
      for(int j  =0 ; j < perm.size() ; ++j)
	{
	  if(mapa.find(perm[j].first) != mapa.end())
	    {
	      int valor = mapa[perm[j].first].first, pos = mapa[perm[j].first].second;
	      int ladoa = perm[j].first.first, ladob = perm[j].first.second ,
		ladoc = perm[j].second + valor;
	      mini = min(ladoa,min(ladob,ladoc));
	      if(ans <= mini)
		{
		  ans = mini;
		  k.clear();
		  k.push_back(i);
		  k.push_back(pos);
		}
	    }
	}
      for(int j = 0 ; j < perm.size() ; ++j)
	{
	  if(mapa.find(perm[j].first) != mapa.end())
	    {
	      int valor = mapa[perm[j].first].first, pos = mapa[perm[j].first].second;
	      if(valor < perm[j].second)
		{
		  mapa[perm[j].first] = {perm[j].second,i};
		}

	    }
	  else
	    {
	      mapa[perm[j].first] = {perm[j].second,i};
	    }
	}
      
    }
  cout << k.size() << "\n";
  for(int i = 0;i < k.size() ; ++i)
    cout << k[i]+1 << " " ;
  cout << "\n";
  return 0;
}
