/*  Group 21
* 	170012693
*	MATRIC
*	MATRIC
*	MATRIC
*	MATRIC
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "Assembler.h"
#include "Errors.h"

using namespace std;

Assembler::Assembler(){

}

Assembler::~Assembler(){

}

string Assembler::intToBinary(unsigned int dec){
	int bin[32] = { 0 };
	int i = 0;
	
	string binString = "";
	for(i=0;dec>0;i++){
		bin[i] = dec%2;
		dec = dec/2;
	}
	int j=0;
	for(j=0;j<i;j++){
		//cout<<bin[i];
		binString += std::to_string(bin[j]);
	}
	//cout<<endl;
	return binString;
}

string Assembler::hexToBinary(string hex){
	int i;
	string bin = "";
	int length = hex.length();
	for(i=0;i<length;i++){
		switch(hex[i]){
			case '0':
				bin += "0000";
			break;
			case '1':
				bin += "0001";
			break;
			case '2':
				bin += "0010";
			break;
			case '3':
				bin += "0011";
			break;
			case '4':
				bin += "0100";
			break;
			case '5':
				bin += "0101";
			break;
			case '6':
				bin += "0110";
			break;
			case '7':
				bin += "0111";
			break;
			case '8':
				bin += "1000";
			break;
			case '9':
				bin += "1001";
			break;
			case 'a':
			case 'A':
				bin += "1010";
			break;
			case 'b':
			case 'B':
				bin += "1011";
			break;
			case 'c':
			case 'C':
				bin += "1100";
			break;
			case 'd':
			case 'D':
				bin += "1101";
			break;
			case 'e':
			case 'E':
				bin += "1110";
			break;
			case 'f':
			case 'F':
				bin += "1111";
			break;
		}

	}
	return bin;
}

void Assembler::createSymbolTable(string fileName){
	string line;
	int count = 0;
	fstream readFile;
	readFile.open(fileName);

	while(getline(readFile, line)){
		//get rid of comments if any
		int commentMarker = line.find(";");
		if (commentMarker != 0)
			line = line.substr(0, commentMarker);
		else if (commentMarker == 0)
			continue;

		count++;

		int colonMarker = line.find(":");
		if (colonMarker != -1) //colon in the line which means there is a label in the line to add to a symbol table
		{
			string label = line.substr(0, colonMarker);
			// cout << label << endl;
			int labelAddress = count;

			/*	ADD LABEL TO SYMBOL TABLE 	*/
			int i = 0;
			bool finished = false;

			while(finished == false)
			{
				if (symbolLabel[i] == "null")
				{
					symbolLabel[i] = label;
					symbolAddress[i] = labelAddress;
					finished = true;
				}
			else
				i++;
			}
		}
	}
	readFile.close();
}


void Assembler::readFromFile(){
	string fileName;
	cout << "Enter the file name of the assembly code: " << endl;
	cin >> fileName;
	cout << endl;

	fstream readFile;
	readFile.open(fileName);

	ofstream writeFile;
	writeFile.open("output.txt");

	if (!readFile){
		cout << "Could not open the file" << endl;
	}
	else{
		createSymbolTable(fileName); //create the symbol table
		string line;
		int count = 0;
		int totalSourceLines = 0;
		int binaryInstruct[3];
		int binaryAddress[4];

		while(getline(readFile, line)){
			totalSourceLines++;
			// cout << line << endl;

			//get rid of comments if any
			int commentMarker = line.find(";");
			if (commentMarker != 0)
				line = line.substr(0, commentMarker);
			else if (commentMarker == 0)
				continue;

			int colonMarker = line.find(":");
			if (colonMarker != -1) //colon in the line which means there is a label in the line to add to a symbol table
			{
				string label = line.substr(0, colonMarker);
				// cout << label << endl;
				int labelAddress = count;

				line = line.substr(colonMarker+1, line.length());
				// cout << line << endl;
			}

			line.erase(remove(line.begin(), line.end(), ' '), line.end()); //removes spaces from the line

			// cout << line << endl;
			string instruct = line.substr(0, 3);
			string labelToConvert = line.substr(3, line.length());
			// cout << labelToConvert << endl;

			if(instruct == "VAR")
			{
				if (labelToConvert == "0")
					writeFile << "00000000000000000000000000000000\n";
				else
				{
					cout << labelToConvert << endl;
					string binVar = intToBinary(stoi(labelToConvert));
					string toAdd = "";
					if (binVar.length() < 32)
					{
						int total = binVar.length();
						while (total != 32)
						{
							toAdd = toAdd + "0";
							total++;
						}
					}
					writeFile << binVar << toAdd << endl;
				}
			}
			else
			{
				string binInstructCode = getInstruction(instruct);

				if (binInstructCode == "111") // stop
				{
					writeFile << "00000000000001110000000000000000" <<endl;
					continue;
				}
				else if (binInstructCode == "err") //error in assembly code
				{
					cout << "Error on line: " << totalSourceLines << endl;
					exit(1);
				}
				else //valid instruction found
				{

					int i=0;
					while (symbolLabel[i] != labelToConvert)
					{
						if (symbolLabel[i] == "null")
						{
							cout << "Error in symbol table" << endl;
							exit(1);
						}
						i++;
					}

					int instructMemAddress = symbolAddress[i];
					//convert memoryaddress to binary (4)


					//write line
					//binMemaddress, 8 0s, binInstructCode, 16 0s
					writeFile << intToBinary(instructMemAddress) << "00000000" << binInstructCode << "00000000000000000\n";
				}
			}

			count++;
		}

		cout << "The found labels are:" << endl;
		int j=0;
		while (symbolLabel[j] != "null" && j<32)
		{
			cout << symbolLabel[j] << " " << symbolAddress[j] << endl;
			j++;
		}
		readFile.close();
		writeFile.close();
	}
}

string Assembler::getInstruction(string instruction){
	if (instruction == "JMP")
		return "000";
	else if (instruction == "JRP")
		return "100";
	else if (instruction == "LDN")
		return "010";
	else if (instruction == "STO")
		return "110";
	else if (instruction == "SUB")
		return "001";
	else if (instruction == "CMP")
		return "011";
	else if (instruction == "STP")
		return "111";
	else
		return "err";
}

int main(){
	Assembler assembler;
	cout << assembler.intToBinary(10)<< endl;
	cout << assembler.hexToBinary("103F")<< endl;
	cout << "MANCHESTER BABY ASSEMBLER\n" << endl;

	for (int i=0; i<32; i++)
	{
		assembler.symbolLabel[i] = "null";
		assembler.symbolAddress[i] = 0;
	}

	assembler.readFromFile();

}