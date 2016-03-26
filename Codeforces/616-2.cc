#include <bits/stdc++.h>
#define MAXN int(1e6+1)
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int beg=0,end=0,l=0,r=0,a,b,ans=1; scanf("%d %d",&a,&b);
  set<int> kn; int v[MAXN],onthe[MAXN];
  memset(v,0,sizeof v);
  for(int i = 0 ; i < a ; ++i)
    {
      // cout << beg << " " << end << "\n";
      scanf("%d",&onthe[i]);
      kn.insert(onthe[i]); ++v[onthe[i]];
      if(kn.size() <= b)
	{
	  if(end-beg+1 > ans)
	    {
	      l = beg;
	      r = end;
	      ans = end-beg+1;
	    }
	}
      else
	{
	  while(kn.size() > b)
	    {
	      if(v[onthe[beg]] <= 1)
		kn.erase(kn.find(onthe[beg]));
	      --v[onthe[beg]];
	      ++beg;
	    }
	}
      ++end;
    }
  printf("%d %d\n",l+1,r+1);
  return 0;
}
  // a.insert(1);
  // a.insert(1);
  // a.erase(a.find(1));
  // a.erase(a.find(1));
  // cout << a.size() << "\n";
