#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,int> m;
string conversion(string num)
{
  string nv;
  for(int i = num.size() - 1; i >= 0  ; --i)
    {
      nv += (num[i] % 2 == 0 ? '0' : '1');
    }
  for(int i = nv.size() ; i < 18 ; ++i)
    {
      nv += '0';
    }
  return nv;
}

void insert(string num)
{
  string dd = conversion(num);
  // printf("%s",dd.c_str());
  if(m.find(dd) != m.end())
    ++m[dd];
  else
    m[dd]=1;
}

void erase(string num)
{
  string dd = conversion(num);
  --m[dd];
}

int query(string num)
{
  reverse(num.begin(), num.end());
  for(int i = num.size() ; i < 18 ; ++i)
    num += '0';
  if(m.find(num) != m.end())
    return m[num];
  return 0;
}


int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  string dame;
  ll num; scanf("%d",&n);
  for(int i= 0; i < n; ++i)
    {
      char c;
      scanf(" %c",&c);
      scanf("%lld",&num);
      dame = to_string(num);
      // printf("%d %lld",c,num);
      switch(int(c))
	{
	case 43:
	  insert(dame);
	  break;
	case 45:
	  erase(dame);
	  break;
	case 63:
	  printf("%d\n",query(dame));
	  break;
	}
    }
  return 0;
}
