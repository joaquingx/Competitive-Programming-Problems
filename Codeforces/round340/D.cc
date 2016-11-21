#include <bits/stdc++.h>
using namespace std;

int colinear(pair<int,int> p1 , pair<int,int> p2 )
{
  if(p1.first == p2.first)
    return 1;
  if(p1.second == p2.second)
    return 2;
  return 0;      
}

bool extremo(pair<int,int> p1,pair<int,int> p2,pair<int,int> p3 ,int tipo)
{
  if(tipo == 2)
    {
      if( (p1.first <= p3.first and p2.first <= p3.first) or
	  (p1.first >= p3.first and p2.first >= p3.first) )
	return 1;
    }
  else
    {
      if( (p1.second <= p3.second and p2.second <= p3.second) or
	  (p1.second >= p3.second and p2.second >= p3.second) )
	return 1;
    }
  return 0;
}


int main()
{
  int res = 3;
  pair<int,int> p[3];
  for(int i = 0 ;i < 3 ; ++i)
    cin >> p[i].first >> p[i].second;
  for(int i  = 0; i < 3 ; ++i)
    {
      for(int j = 0 ; j < 3 ; ++j)
	{
	  if(j != i)
	    {
	      int tipo = colinear(p[i],p[j]);
	      if(tipo)
		{
		  for(int k = 0 ; k < 3 ; ++k)
		    {
		      if(k != i and k!= j)
			{
			  if(extremo(p[i],p[j],p[k],tipo))
			    {
			      res = min(res,2);
			      int tipaso1 = colinear(p[i],p[k]);
			      int tipaso2 = colinear(p[j],p[k]);
			      if(tipaso1 == tipo and tipaso2 == tipo)
				{
				  res = min(res,1);
				}
			    }
			}
		    }
		}
	    }
	}
    }
  cout << res <<"\n";
  return 0;
}
