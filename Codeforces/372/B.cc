#include <bits/stdc++.h>
using namespace std;

int main()
{
  string pat; cin >> pat;
  int ptr = 0,ptr2,cc=0;
  set<char> s;
  bool si=0;
  for(int i = 0; i <= pat.size() ; ++i)
    {
      if(s.size() + cc >= 26)
	{
	  ptr2=i;
	  si=1;
	  break;
	}
      if(i == pat.size())
	break;	
      if(pat[i] == '?')
	{
	  ++cc;
	  continue;
	}
      if(s.find(pat[i]) == s.end())
	s.insert(pat[i]);
      else
	{
	  if(pat[ptr] == pat[i])
	    {
	      s.erase(pat[ptr]);
	      ++ptr;
	    }
	  else
	    {
	      while(pat[ptr] != pat[i])
		{
		  // cout << "iteracion :" << i << "\n";
		  // cout << pat[ptr] << " " << pat[i] << "\n";
		  if(pat[ptr] == '?')
		    {
		      --cc;
		    }
		  else s.erase(pat[ptr]);
		  ++ptr;
		}
	      ++ptr;
	    }
	  s.insert(pat[i]);
	}
    }
  // cout << ptr << "\n";
  if(si)
    {
      // cout << ptr << " " << ptr2 << "\n";
      for(int i = 0 ; i < ptr ; ++i)
	{
	  if(pat[i] == '?')
	    cout << "A";
	  else cout << pat[i];
	}
      for(int i = ptr; i < ptr2 ; ++i)
      	{
	  if(pat[i] == '?')
	    {
	      for(int j = 0 ; j < 26 ; ++j)
		{
		  if(s.find(char(j+'A')) == s.end())
		    {
		      s.insert(char(j+'A'));
		      cout << char(j+'A');
		      break;
		    }
		}
	    }
	  else cout << pat[i];
      	}
      for(int i = ptr2 ; i < pat.size() ; ++i)
	{
	  if(pat[i] == '?')
	    cout << "A";
	  else cout << pat[i];
	}
      cout <<"\n";    
    }
  else
    cout << "-1\n";
  return 0;
}
