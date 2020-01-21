#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Person {
	string name;
	int age;
};

int main() {
	ifstream inFile;
	ofstream outFile;
	int intNum = 5;
	double doubleNum = 2.3;
	string stringOne = "I love lamp.";
	int inFileNumOne;
	double inFileNumTwo;
	string inFileString;
	Person p1, p2;
	p1.name = "Timmy";
	p1.age = 30;

	// read from file
	inFile.open("myfile.txt");
	inFile >> inFileNumOne >> inFileNumTwo;
	cout << inFileNumOne + inFileNumTwo << endl;
	
	getline(inFile, inFileString);

	inFile.close();

	// write to file
	outFile.open("myfile.txt");
	outFile << doubleNum << " " << intNum << endl;
	outFile << stringOne << endl;
	outFile.close();

	// write to binary file
	outFile.open("binaryFile.bin", ios::app);
	outFile.write((char*)&p1, sizeof(p1));
	outFile.close();

	// read object from binary file
	inFile.open("binaryFile.bin", ios::in);
	inFile.read((char*)&p2, sizeof(p2));

	cout << p2.name << " " << p2.age << endl;
	return 0;
}