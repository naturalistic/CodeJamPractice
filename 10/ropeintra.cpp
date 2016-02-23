#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <time.h>
using namespace std;

bool intersects(pair<int,int> p1, pair<int, int> p2) {
	return (p1.first > p2.first && p1.second < p2.second) || 
			(p1.first < p2.first && p1.second > p2.second);
}

int main() {
	ifstream input("A-large-practice.in");
	ofstream output("A-large-practice.out");
	int cases, ropes, start, end;
	input >> cases;
	for(int c=1; c<=cases; c++) {
		int inters = 0;
		input >> ropes;	
		vector<pair<int,int>> vp;
		for(int r=0; r<ropes; r++) {
			input >> start >> end;	
			pair<int,int> p1(start, end);
			for(vector<pair<int,int>>::iterator it=vp.begin(); it!=vp.end(); it++) {
				if(intersects(p1, *it)) {
					inters++;
				}
			}
			vp.push_back(p1);
		}
		output << "Case #" << c << ": " << inters <<  endl;
	}
	return 0;
}
