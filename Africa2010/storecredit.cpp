#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

// really do need to read the question better. 
// Have a slightly ugly edge case with multiple responses from map.
// Probably have to switch to using vector, then check amongst reponses?
// Only two, so maybe a hack I can use?
// If items equal, need to somehow record both.
// Whats the 'right' way to record the different indexes for same price?
// Probably an array of the found, then at end if multiple then pick first and second.
// Want a simpleton approach. 
// how about if two, then put in second map

int main() {
	ifstream input("A-large-practice.in");
	ofstream output("A-large-practice.out");
	string line;
	int cases;
	input >> cases;
	for(int i=0; i<cases; i++) {
		int credit, items;
		input >> credit >> items;
		string prices_str;
		input.get(); // rm newline
		getline(input, prices_str);
		stringstream ss;
		ss.str(prices_str);
		map<int,int> p1;	// value, index
		map<int,int> p2; // for if multiple of same value
		for(int j=0; j<items; j++) {
			int price;
			ss >> price;
			if(p1.find(price)==p1.end()) {
				p1.insert({price,j});
			} else if(p2.find(price)==p2.end()) {
				p2.insert({price,j});
			}
		}
		map<int,int>::iterator item1;
		for(item1=p1.begin(); item1!=p1.end(); item1++) {
			int price2 = credit-item1->first;
			bool found = false;
			map<int,int>::iterator item2 = p2.find(price2);
			if(item2!=p2.end()) {
				found = true;
			} else {
				item2=p1.find(price2);
				if(item2!=p1.end()) {
					found = true;
				}
			}
			if(found) {
				int index1, index2;
				if(item1->second < item2->second) {
					index1 = item1->second+1;
					index2 = item2->second+1;
				} else {
					index1 = item2->second+1;	
					index2 = item1->second+1;
				}
				output << "Case #" << i+1 << ": " << index1 << " " << index2 << endl;		
				break;
			}			
		}
	}
	return 0;
}
