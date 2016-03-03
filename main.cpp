#include <iostream>
#include <string>
#include <vector>
using namespace std;


#include "isValidSudoku.cpp"


int main() {
	vector<int> s1;
	s1.push_back(0);
	s1.push_back(2);
	s1.push_back(3); q
	vector<int>::iterator iter = s1.begin(), iter2 = s1.end();
	cout << "iter:" << int(*iter) << "\n";

	s1.insert(iter, -1);
	cout << "iter:" << *iter << endl;
	
}