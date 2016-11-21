#include <bits/stdc++.h>
#define INF int(1e9)
using namespace std;
int n;

int bs1()
{
  int ini = 0, fin = INF,whoc,whoc2;
  cout << 0 << " " << 0 << "\n";
  fflush(stdout);
  cin >> n;
  cout << 0 << " " << fin << "\n";
  fflush(stdout);
  cin >> n;
  int mid = (fin + ini) / 2;
  whoc = fin;
  int princ = n;
  int cnt = 0;
  while(true)
    {
      if(cnt >= 200)
	break;
      cout << 0 << " " << mid << "\n";
      fflush(stdout);
      cin >> n;
      whoc2 = whoc;
      whoc = mid;
      if(!n)
	{
	  if(whoc2 > mid)
	    {
	      mid = mid + mid/2;
	    }
	  else
	    {
	      mid = mid/2;
	    }
	}
      else
	{
	  if(whoc2 > mid)
	    {
	      mid = mid/2;
	    }
	  else
	    {
	      mid = mid + mid/2;
	    }
	}
      ++cnt;
    }
  return mid;
}

int bs2()
{
  int ini = 0, fin = INF,whoc,whoc2;
  cout << 0 << " " << 0 << "\n";
  fflush(stdout);
  cin >> n;
  cout << fin << " " << 0 << "\n";
  fflush(stdout);
  cin >> n;
  int mid = (fin + ini) / 2;
  whoc = fin;
  int cnt = 0;
  while(true)
    {
      if(cnt >= 10)
	break;
      cout << mid << " " <<0 << "\n";
      fflush(stdout);
      cin >> n;
      whoc2 = whoc;
      whoc = mid;
      if(!n)
	{
	  if(whoc2 > mid)
	    {
	      mid = mid + mid/2;
	    }
	  else
	    {
	      mid = mid/2;
	    }
	}
      else
	{
	  if(whoc2 > mid)
	    {
	      mid = mid/2;
	    }
	  else
	    {
	      mid = mid + mid/2;
	    }
	}
      ++cnt;
    }
  return mid; 
}



int main(){
  int l = bs1();
  int r = bs2();
  cout << l << " " << r << "\n";
  return 0;
}
