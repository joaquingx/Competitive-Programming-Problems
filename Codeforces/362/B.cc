#include <bits/stdc++.h>
using namespace std;
bool esentero = 0;
string conv(string pat,int mas, int point)
{
  string rpta;
  rpta = pat.substr(0 , find(pat.begin() , pat.end(), '.') - pat.begin());
  int i;
  for(i = point ; i < (point + mas)  ;  ++i)
    {
      if(i+1 < pat.size())
	rpta += pat[i+1];
      else
	rpta += '0';
    }
  if(i + 1 < pat.size())
    {
      rpta += '.';
      for(int j = i + 1 ; j < pat.size() ; ++j)
	rpta += pat[j];
    }
  else esentero = 1;
  return rpta;
}

string noleading(string pat, int punto)
{
  string ans;
  bool iszero = 1;
  int pos;
  for(int i = 0 ;i < punto ; ++i)
    if(pat[i]!= '0')
      {
	iszero = 0;
	pos = i;
	break;
      }
  // cout << pos << "\n";
  if(iszero)
    {
      ans += '0';
      if(punto < pat.size())
	ans += '.';
      for(int i = punto + 1 ; i < pat.size() ; ++i)
	ans += pat[i];
    }
  else
    ans = pat.substr(pos,pat.end()-pat.begin());
  return ans;
}


string notrailing(string pat, int punto)
{
  string ans;
  if(punto + 1 == pat.size() - 1 and pat[punto+1] == '0')
    ans = pat.substr(0,punto);
  else
    ans = pat;
  return ans;
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  string pat,pat2,cc; cin >> pat;
  int idx = find(pat.begin() , pat.end() , '.') - pat.begin();
  int idx2 = find(pat.begin() , pat.end() , 'e')  - pat.begin();
  cc = pat.substr(idx2+1,pat.end()-pat.begin());
  int k = stoi(cc);
  pat2 = pat.substr(0 , find(pat.begin() , pat.end() , 'e') - pat.begin());
  string ans = conv(pat2,k,idx);
  idx = find(ans.begin() , ans.end() , '.') - ans.begin();
  // cout << ans << "\n";
  cout << notrailing(noleading(ans,idx),idx) << "\n";
  return 0;
}
