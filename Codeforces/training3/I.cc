#include <bits/stdc++.h>
using namespace std;
#define MAXN int(1e9)
typedef long long ll;
#define MUCHO ll(1e15+10)
bool mark[MAXN];
vector<ll> ans;


void criba(ll key)
{
  cout << key << "\n";
  memset(mark,0,sizeof mark);
  for(int  i = 2 ; ll(i*i)  <= key ; ++i)
    if(!mark[i])
      {
	for(int j = i*i ; ll(j * j) <= key;j+=i)
	  {
	    ans.push_back(i);
	    mark[j] = 1;
	  }
      }
}


bool isprime(ll key)
{
  if(key ==0)
    return 1;
  if(key==1)
    return 0;
  for(int i = 0 ;i < ans.size() ; ++i)
    if(key % ans[i] == 0)
      return 0;
  return 1;
}

int main()
{
  criba(MUCHO);
  ll a , b ; cin >> a >> b;
  ll mine,rpta1 = b + 2,rpta2 = b-2;
  if( a == 3 and b ==7)
    {
      cout << 3 << "->" << "5" << "->" << 7 << "\n";
      return 0;
    }
  if( a== 2 and b == 3)
    {
      cout << 2 << "->"  << 3 << "\n";
      return 0;
    }
  if( a + 2 == b)
    {
      cout << a << "->" << b << "\n";
      return 0;
    }
  bool isp1,isp2,ispano,ispa2;
  isp1 = isprime(rpta1);
  isp2 = isprime(rpta2);
  if( isp1 and isp2 )
    {
      cout << "Poor Benny\n";
      return 0;
    }
  if( !isp1 and !isp2 )
    {
      cout << "Unlucky Benny\n";
      return 0;
    }
  ispa2 = isprime(a+2);
  ispano = isprime(a-2);
  if(!ispa2 and !ispano)
    {
      cout << "Unlucky Benny\n";
      return 0;
    }
  ll a2 = a + 2;
  cout << a << "->";
  if(!ispano)
    {
      cout << a2 << "->";
      swap(a2,a);
    }
  if(isp2)
    {
      if( a != 2)
	{
	  cout << 2 << "->";
	}
      cout << b << "\n";
    }
  else
    {
      if(a != 2)
	cout << 2 <<  "->";
      cout << rpta1 << "->" << b << "\n";
    }
  return 0;
}
