#include <bits/stdc++.h>
using namespace std;


int main()
{
  string pat = "";
  while(1)
    {
      cin >> pat;
      if(pat == "END")
	break;
      for(int i = pat.size() -1  ; i >= 0 ; --i)
	{
	  if(pat[i] != '0')
	    {
	      pat[i] = char(pat[i] - 1);
	      break;
	    }      
	}
	cout << stoi(pat)<< "\n";
    }
  return 0;
}
