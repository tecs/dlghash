/* 
 * dlghash
 * Author: Alexander Ivanov
 * 
 * This code is distributed under the WTFPL License. For more info check:
 * http://www.wtfpl.net/txt/copying/
 */

#include <iostream>
#include <string>
#include <vector>

#define PROGRAM_NAME "dlghash"
#define DEFAULT_LENGTH 32

using namespace std;

inline unsigned char toHex(int i) { return i<10 ? '0'+i : 'a'+(i-10); }

string myCrypt(const string & str, const unsigned int l = 32) {
	vector<unsigned char> hash;
	string output;
	const unsigned long long strl = str.length();
	int extra = 0;
	
	for(unsigned int k=0;k<l;++k) hash.push_back(k*k+l);
	
	for(unsigned long long i=0;i<strl;i++) {
		for(unsigned int k=0;k<l;++k) {	
			hash[k] = hash[k]%(i+2) - str[i]%(k+3);
		}
	}
	
	for(unsigned int i=0;i<100000;++i) {
		for(unsigned int k=0;k<l;++k) {			
			hash[k] += (i+2)%13 - (k+3)%11 + hash[k]%7 - extra - hash[i%l]%(i+3) + (strl>0?str[i%strl]%(k+2):0);
		}
	}
	
	
	for(unsigned int k=0;k<l;++k) output += toHex(hash[k]%16);
	
	return output;
}
void help () {
	cout << "usage: " << PROGRAM_NAME << " string [length]" << endl;
}

int main(int argc , char * argv[] ) {
	string temp = "";
	if(argc>1) temp = argv[1];		
	int l = DEFAULT_LENGTH;
	
	string lineInput = "";
	while (temp == "" && argc<=1 && cin >> lineInput) temp = lineInput;

	
	try {	
		if(argc>2) l = stoi(argv[2]);
		
		cout << myCrypt(temp,l) << endl;		
	} catch(exception e) {
		help();
		return 1;
	}
	
	return 0;
}