#include <bits/stdc++.h>
using namespace std;
vector<string> IN,OU;
string s;
string li[] = {".in",".In",".IN"};
string lo[] = {".ou",".Ou",".OU",".an",".AN",".An"};

bool check(int last,string t) {
	for(int i = 0; i < 3; i++) {
		if(s[last+i] != t[i]) return false;
	}
	return true;
}

int main() {
	freopen("list.txt","r",stdin);
	freopen("input.inp","w",stdout);
	bool in,ou;
	while(getline(cin,s)) {
		in = ou = false;
		for(int i = s.size()-3; i >= 0; i--) {
			for(int j = 0; j < 3; j++)
			if(check(i,li[j])) in = true;
			for(int j = 0; j < 3; j++)
			if(check(i,lo[j])) ou = true;
			if(in || ou) break;
		}
		if(in) IN.push_back(s);
		if(ou) OU.push_back(s);
	}
	for(int i = 0; i < IN.size(); i++)
		cout << IN[i] << endl << OU[i] << endl;
	return 0;
}