#include <bits/stdc++.h>
// using namespace std;

void findlps(string str, vector<int> &lps){
	int i = 1, len = 0;
	while(i<str.size()){
		if(str[i]==str[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if(len==0){
				i++;
			}
			else{
				len = lps[len-1];
			}
		}
	}
}


int minCharsforPalindrome(string str) {
	
	string str1 = str;
	reverse(str1.begin(), str1.end());
	str = str + "$" + str1;

	vector<int> lps(str.size(), 0);
    findlps(str, lps);

	int ans = str1.size()-lps[str.size()-1];
	return ans;
	
}
