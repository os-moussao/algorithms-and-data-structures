#pragma once
// returns the longest proper prefix array of pattern p
// where lps[i]=longest proper prefix which is also suffix of p[0...i]
vector<int> build_lps(string p) {
	int sz = p.size();
	vector<int> lps;
	lps.assign(sz + 1, 0);
	int j = 0;
	lps[0] = 0;
	for(int i = 1; i < sz; i++) {
	while(j >= 0 && p[i] != p[j]) {
		if(j >= 1) j = lps[j - 1];
		else j = -1;
	}
	j++;
	lps[i] = j;
	}
	return lps;
}
// returns matches in vector ans in 0-indexed
vector <int> kmp(vector<int> lps, string s, string p) {
	vector <int> ans;
	int psz = p.size(), sz = s.size();
	int j = 0;
	for(int i = 0; i < sz; i++) {
	while(j >= 0 && p[j] != s[i])
		if(j >= 1) j = lps[j - 1];
		else j = -1;
	j++;
	if(j == psz) {
		j = lps[j - 1];
		// pattern found in string s at position i-psz+1
		ans.push_back(i - psz + 1);
	}
	// after each loop we have j=longest common suffix of s[0..i] which is also prefix of p
	}
	return ans;
}

vector <int> kmp(string str, string pattern) {
	return kmp(build_lps(pattern), str, pattern);
}
