#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string line;
	ifstream file("default.txt");
	if(file.is_open()){
		while(file.good()){
			getline(file,line);
			cout << line << endl;
		}
		file.close();
	}
	else {
		cout << "Cant open file";
	}
	return 0;
}
