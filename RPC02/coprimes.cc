#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; cin >> n;
  for(int i= 0 ; i < n ; ++i)
    {
      bool kk=0;
      cout << "Ticket #" << i+1  << ":\n";
      string pat; cin >> pat;
      for(int i = 1 ; i < pat.size(); ++i)
	{
	  string pri="",sec="";
	  for(int j = 0 ; j < i ; ++j)
	    pri += pat[j];
	  for(int j = i; j < pat.size() ; ++j)
	    sec += pat[j];
	  int a = stoi(pri), b = stoi(sec);
	  if(__gcd(a,b) == 1)
	    {
	      cout << a << " " << b << "\n";
	      kk = 1;
	      break;
	    }
	}
      if(!kk)
	cout << "Not relative\n";
    }
  return 0;
}
