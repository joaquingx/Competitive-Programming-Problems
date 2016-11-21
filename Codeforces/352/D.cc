#include <bits/stdc++.h>
using namespace std;
map<int,int> mapa;

int main()
{
  int n , k;
  scanf("%d %d",&n,&k);
  for(int i= 0 ;i < n ; ++i)
    {
      int l;
      scanf("%d",&l);
      ++mapa[l];
    }
  for(auto it = mapa.rbegin() ; ; ++it)
    {
      cout << "Cunato:" << k << "  ";
      cout << it->first << " " << it->second << "\n";
      if(++it == mapa.rend())
	break;
      auto maso = it;
      --it;
      int dif = it->first-maso->first;
      if(it->second * dif > k )
	{
	  int ayuda = k / it->second;
	  printf("%d\n",it->first - mapa.begin()->first);
	  return 0;
	}
      k -= it->second * dif;
      maso->second += it->second;
    }
  printf("0\n");
  return 0;
}
