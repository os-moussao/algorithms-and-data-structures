#include <bits/stdc++.h>
using namespace std;
#define double long double
#define endl '\n'

// g++ -std=c++17 igen_files.cpp -I testlibPath -o igen_files
int main() {
	for (int i = 0; i < 50; i++) {
		string cmd = "./igen " + to_string(i) + " > tests_today/test_case_" + to_string(i+1);
		system(cmd.c_str());
	}
}