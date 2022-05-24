/** Group 17 
* 	Timothy Lundberg 170012693
*	MATRIC
*	MATRIC
*	MATRIC
*	MATRIC
*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <exception>
#include "HardwareSimError.h"

using namespace std;

class ManchesterBaby
{
	public :

	int store [32][32]; // used to store the binary data
	int accumulator[32]; // holds the results of numerical arithmatic 
	int control[32]; // holds the address of the next instruction (control instruction)
	int presentInstruction[32]; //holds actual instruction opcode which is being execute in cycle
	int instructionFormat[32];
	int instructionSet[32];

	ManchesterBaby();
	//~ManchesterBaby();
	int onLamp = 0;
	int decimalConversion(string binary);
	string binaryConversion(int num);

	bool binaryToStore();
	int fetch(int address);
	void processor(int address);
	void execute(int address, int decoded);
	int decode(int address);
	void JMP(int input); // jump to int intput
    void JRP(int input); // 
	void LDN(int input); // 
	void STO(int input);
	void SUB(int input);
	void CMP();
    void STP();// stop function

    void showStore();
    void showAccumulator();
    void showControl();

};

ManchesterBaby::ManchesterBaby()
{
	for(int i =0; i < 32; i++)
	{
		accumulator[i]=0;
		control[i]=0;
		for(int j =0; j < 32; j++)
		{
			store[i][j] = 0;
		}
	}
}

void ManchesterBaby::processor(int address){
	fetch(address);

	int decoded = decode(address);

	execute(address,decoded);

	showAccumulator();
	showControl();
	showStore();

	for(int i = 0;i<32;i++){
		control[i]=store[address][i];
	}
	//Press enter for next cycle
	cin.get();
}


int ManchesterBaby::fetch(int address)
{
	cout<<"FETCH"<<endl;

	cout<<"Memory Dress:   " << address<<endl;

	try{
	for(int i = 0; i < 32; i++)
	{
		presentInstruction[i] = store[address][i];
		cout<<presentInstruction[i];
	}
	}
	catch(FetchException& e){
		cout << e.detail() << endl;
	}
	cout<<endl;
	return 0;
}

int ManchesterBaby::decode(int address){
	cout<<"DECODE LINE"<<endl;

	int functionNum = 0;
	int i;
	int twoPowers[3] = {1,2,4};
	//Convert Big Endian function from binary to int
	for(i=0;i<3;i++){
		functionNum = functionNum + (presentInstruction[i+13]*twoPowers[i]);
	}

	cout<< "Decoded Function Number: " << functionNum<<endl;
	if(functionNum>7)
		cout<<"Something went wrong"<<endl;


	cout<<"Instruction is: 	";
	switch(functionNum){

		case 0:
			cout<< "JMP"<<endl;
			break;
		case 1:
			cout<< "JRP"<<endl;
			break;
		case 2:
			cout<< "LDN"<<endl;
			break;
		case 3:
			cout<< "STO"<<endl;
			break;
		case 4:
			cout<< "SUB"<<endl;
			break;
		case 5:
			cout<< "SUB"<<endl;
			break;
		case 6:
			cout<< "CMP"<<endl;
			break;
		case 7:
			cout<< "STP"<<endl;
			break;
	}

	return functionNum;
}


void ManchesterBaby::execute(int address, int decoded){

	address=0;
	int binPowers[5]= {1,2,4,8,16};
	for(int i=0; i<5;i++){
		address=address+presentInstruction[i]*binPowers[i];
	}


	try{
	cout<<"Executing function:  ";
	switch(decoded){

		case 0:
			cout<< "JMP"<<endl;
			JMP(address);
			break;
		case 1:
			cout<< "JRP"<<endl;
			JRP(address);
			break;
		case 2:
			cout<< "LDN"<<endl;
			LDN(address);
			break;
		case 3:
			cout<< "STO"<<endl;
			STO(address);
			break;
		case 4:
			cout<< "SUB"<<endl;
			SUB(address);
			break;
		case 5:
			cout<< "SUB"<<endl;
			SUB(address);
			break;
		case 6:
			cout<< "CMP"<<endl;
			CMP();
			break;
		case 7:
			cout<< "STP"<<endl;
			STP();
			break;
	}

	cout<<"\n"<<endl;


	}
	catch(ExecutionException &e){
		cout << e.detail() << endl;
	}

}

bool ManchesterBaby::binaryToStore() // takes the binary from the file and puts it into the babys store
{
	string array[32];

	char bit = 't';
	int i = 0;
	int lineNum = 1;
	string line;
	string fileName;
	try{
	cout<<"Please write the name of the machine code file:";
	cin >> fileName;
	ifstream file(fileName);
	if(file.is_open())
	{
		//This will get each line and store into a string
		//Use this string as temporary storage and increment through it to store into babys store
		while(getline(file,line))
		{
			//cout << lineNum << endl;
			while (i <= 32)
			{
				
				if(line[i] == '1'){
					store[lineNum][i] = 1;
				}
				else if (line[i] == '0'){
					store[lineNum][i] = 0;
				}

				i++;
			}
			lineNum++;
			i = 0;
		}
		file.close();
	}
	else{
		throw FileException();
	}
	}
	catch(FileException &e){
		cout<< e.detail() << endl;
	}
	return true;

}


int ManchesterBaby::decimalConversion(string binary)
{
	try{
		int decimalnum = stoi(binary, 0, 2);
		return decimalnum;
	}
	catch(DecimalConvException &e){
		cout << e.detail() << endl;
	}
	return 0;
}

string ManchesterBaby::binaryConversion(int num)
{
	string binNum = "";
  
    // counter for binary array 
    int i = 0; 
    try{
    while (num > 0) 
    { 
  
        // storing remainder in binary array 
        binNum.at(i) = num % 2; 
        num = num / 2; 
        i++; 

    }
    return binNum;
    }
    catch(BinaryConvException& e){
    	cout << e.detail() << endl;
    }
    return 0;
}

void ManchesterBaby::JMP(int input)
{
	for(int i= 0; i < 32; i++)
	{
		control[i] = store[input-1][i];
	}
	for(int i= 0; i < 32; i++)
	{
	    instructionSet[i] = store[input-1][i] ;
	}

}

void ManchesterBaby::JRP(int input)
{
	int carryone =0;
	for(int i=0 ; i < 32; i++)
	{
		if(control[i] != store[input][i])
		{
			instructionSet[i] = 1;
		}

		if(control[i] == store[input][i])
		{
			if(control[i] == 1)
			{
				instructionSet[i]=1;
				carryone =1;

			}
			else
			{
				instructionSet[i] = 0;
			}
		}

		if((control[i] != store[input][i])&&(carryone ==1))
		{
			instructionSet[i] = 1;
			carryone =0;
		}

		if((control[i] == store[input][i])&&(carryone ==1))
		{
			if(control[i] == 1)
			{
				instructionSet[i]=1;
				carryone =1;

			}
			else
			{
				instructionSet[i] = 0;
				carryone =0;
			}
		}


	}
	
}

void ManchesterBaby::LDN(int input)
{
	cout<<"Memory Address: "<< input << endl;
	

	cout<<"Accumulator before bit flip"<<endl;
	for(int i = 0; i<32;i++){
		accumulator[i]=store[input][i];
		cout<<accumulator[i];
	}
	//showAccumulator();
	cout<<endl;

	cout<<"Accumulator after flip"<<endl;
	for(int j=0;j<32;j++){
		if(accumulator[31]==1){
			accumulator[31]=0;
		}else if(accumulator[j]==0){
			accumulator[31]=1;
		}
		cout<<accumulator[j];
	}
	cout<<endl;

	//WIP
	
}
void ManchesterBaby::STO(int input)
{

	for(int i = 0; i< 32; i++)
	{
		store[input][i]=accumulator[i];
		//cout << store[input][i];
}
	
}
void ManchesterBaby::SUB(int input)
{
	int carryone =0;
	for(int i=0 ; i < 32; i++)
	{
		if(accumulator[i] != store[input][i])
		{
			accumulator[i] = 1;
		}

		if(accumulator[i] == store[input][i])
		{
			if(accumulator[i] == 1)
			{
				accumulator[i]=1;
				carryone =1;

			}
			else
			{
				accumulator[i] = 0;
			}
		}

		if((accumulator[i] != store[input][i])&&(carryone ==1))
		{
			accumulator[i] = 1;
			carryone =0;
		}

		if((accumulator[i] == store[input][i])&&(carryone ==1))
		{
			if(accumulator[i] == 1)
			{
				accumulator[i]=1;
				carryone =1;

			}
			else
			{
				accumulator[i] = 0;
				carryone =0;
			}
		}


	}
	
}

void ManchesterBaby::CMP()
{
	/*int carryone = 0;
	
		
		for(int i=0;i<32;i++){
			if(control[i]==0){
				control[i]=1;
			}else{

			}
			
		}
	*/
}

void ManchesterBaby::STP(){
	cout<<"STOP";
	onLamp=0;
}
void ManchesterBaby::showStore()
{
	try{
	cout<<"STORE"<<endl;
	int size = 32;
	int i,j;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<store[j][i];
		}
		cout<<endl;
	}
	cout<<"\n";
	}
	catch(StoreAccessException &e){
		cout << e.detail() << endl;
	}
}
void ManchesterBaby::showAccumulator()
{
	try{
	cout<<"ACCUMULATOR"<<endl;
	int size = 32;
	int i;
	for(int i=0;i<size;i++){
		
		cout<<accumulator[i];
	}
	cout<<endl;
	cout<<"\n";
	}
	catch(AccumulatorAccessException& e){
		cout << e.detail() << endl;
	}
}
void ManchesterBaby::showControl()
{
	try{
	cout<<"CONTROL INSTRUCTION"<<endl;
	int size = 32;
	int i;
	for(int i=0;i<size;i++){
		
		cout<<control[i];
	}
	cout<<endl;
	cout<<"\n";
	}
	catch(ControlAccessException& e){
		cout << e.detail() << endl;
	}
}

int main(){
	//Initialise the mancBaby class
	ManchesterBaby test;
	test.onLamp=1;
	int cycle = 0;
	
	//Store binary to the mancBaby store
	test.binaryToStore();

	//

	cout << test.store[9][0] << endl;
	while(test.onLamp==1){
		cycle++;
		cout<<"Cycle Number: "<<cycle<<endl;
		test.processor(cycle);

	}
}