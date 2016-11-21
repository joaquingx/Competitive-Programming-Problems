#include <bits/stdc++.h>
using namespace std;
string car = "ogo";
string sig = "go";
string pat;


int maxigo(int i,int n)
{
  int idx = i;
  // cout << pat.substr(i,3) << "\n";
  if(pat.substr(idx,3) == car)
    {
      // cout << i << " ";
      // cout <<  pat.substr(i,3) << " "<< car << "\n";
      idx += 3;
      if(i + 2 < n)
	while(pat.substr(idx,2) == sig)
	  idx+=2;
    }
  if(idx == i)
    return i+1;
  return idx;
}

int main()
{
  int n;
  string res="";
  cin >> n;
  cin >> pat;
  for(int i= 0 ;i < n;)
    {
      int k = maxigo(i,n);
      // cout << k << "\n";
      // cout << maxigo(i,n)  << "\n";
      if(k> i+1)
	res+= "***";
      else
	res+= pat[i];
      i = k;
    }
  cout << res << "\n";
  return 0;
}
