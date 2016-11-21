#include <bits/stdc++.h>
#define MAXN int(2*1e5+10)
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  int mini = 2000000000;
  int v[MAXN];
  char pat[MAXN];
  int n; scanf("%d",&n);
  scanf("%s",&pat);
  for(int i = 0 ;i < n ; ++i)
    scanf("%d",&v[i]);
  for(int i = 1 ; i < n ; ++i)
    {
      if(pat[i-1] == 'R')
	if(pat[i] == 'L')
	  {
	    mini = min((v[i]-v[i-1])/2,mini);
	  }
    }
  if(mini == 2000000000)
    printf("-1\n");
  else printf("%d\n",mini);
  return 0;
}
