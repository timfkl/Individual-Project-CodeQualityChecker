/** Group 17
* 	170012693
*	MATRIC
*	MATRIC
*	MATRIC
*	MATRIC
*/
#include <iostream>
#include <string>

using namespace std;

class Assembler { 
	

public:
	string symbolLabel[32];
	int symbolAddress[32];
	Assembler();
	~Assembler();

	void readFromFile();
	string getInstruction(string);
	void createSymbolTable(string);

	string intToBinary(unsigned int);
	string hexToBinary(string);
};