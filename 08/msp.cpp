#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void swap(vector<int> & v, int i, int j) {
	int t = v[j];
	v[j] = v[i];
	v[i] = t;
}

int partition(vector<int> & v, int s, int e, bool desc) {
	int p = v[e];
	int i;
	for(i=s; i<e; i++) {
		if((v[i] > p)!=desc) {
			for(int j=i+1; j<=e; j++) {
				if(j == e) {
					swap(v, i, j);
					return i;
				}
				if((v[j] <= p)!=desc) {
					swap(v, i, j);
					break;
				}
			}	
		}
	}
	return i;
}

void qs(vector<int> & v, int s, int e, bool desc) {
	if(s>=e) {
		return;
	}
	int p = partition(v, s, e, desc);	
	qs(v,s,p-1, desc);
	qs(v,p+1,e, desc);	
}

void qs(vector<int> & v, bool desc) {
	qs(v, 0, v.size()-1, desc);	
}

int main(int argc, char *argv[]) {
	if(argc != 3) {
		cout << "Need input and output file" << endl;
		return 0;
	}
	ifstream input(argv[1]);	
	ofstream output(argv[2]);
	int cases, vsize, n;
	input >> cases;
	for(int c=1; c<=cases; c++) {
		input >> vsize;
		vector<int> v1, v2;
		for(int i=0; i<vsize; i++) {
			input >> n;
			v1.push_back(n);
		}			
		for(int i=0; i<vsize; i++) {
			input >> n; 
			v2.push_back(n);
		}
		qs(v1, true);
		qs(v2, false); 
		long sum = 0;	
		for(int i=0; i<vsize; i++) {
			sum += (long)v1[i]*(long)v2[i];
		}
		output << "Case #" << c << ": " << sum << endl;
	}
}
