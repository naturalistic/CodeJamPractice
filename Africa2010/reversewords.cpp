#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	ifstream input("B-large-practice.in");	
	ofstream output("B-large-practice.out");
	int cases;
	input >> cases; 
	input.get();
	string line;
	for(int c=1; c<=cases; c++) {
		getline(input, line);	
		istringstream iss(line);
		vector<string> v;	
		string word;
		while(iss >> word)
		{
			v.push_back(word);
		}
		output << "Case #" << c << ": ";
		// assume at least one item...
		if(v.size() != 0) {
			for(vector<string>::iterator it=--v.end(); it!=v.begin(); it--) {
				output << *it << " ";
			}			
			output << v.at(0); 
		}
		output << endl;

	}
	return 0;
}
