
//*********************************************************************************************************************************
//       Author:            Shruti Manikrao Basutkar
//       Creation Date:     09/03/2019
//       Modification Date: 09/09/2019
//       Purpose:           This program is for conversion of Decimal number to Binary, Hexadecimal and Binary coded decimal(BCD).
//       Description:       Three separate function are created for the purpose of conversion i.e
//							"void decToBin(int decimalNumber, int numBit)", "void decToHexa(int decimalNumber)" and 
//							"void decToBCD(int decimalNumber)". 
//							The output of conversion is stored into a output file of name "output.txt" , 
//							for that "fstream" header file is used.
//*********************************************************************************************************************************

#include<iostream>		// preprocessor directive required for input and output
#include<string>        // Declare String type variable
#include<sstream>		// Required for file function
#include <cstdlib>      // For converting to integer function atoi
#include<fstream>

using namespace std;	// ”using” directive

ofstream output("output.txt"); 		// Output of conversion will be displayed in "output.txt" file

/***************************************************************************************************
*string to_string(const T& value):
*Purpose: This function will returned decimal number into string form which required in function
* 		  "void decToBCD(int n)" where decimal number needs to convert in string for conversion.
***************************************************************************************************/
template <typename T>
string to_string(const T& value){
    stringstream ss;
    ss << value;
    return ss.str();
}
/***************************************************************************************************
*void decToBin(int decimalNumber, int numBit):
*Purpose: It will help to convert Decimal number to Binary number. 
*		  Passing parameter "int numBit" is used to display number of bits of binary no. 
*         for example if "int numBit"  = 8, then binary number representation will be 8 bit.
*		  By doing this, same function could be used for both i.e.decimal to Binary conversion where 8 bit 
*	      representation is required and BCD conversion where each digit converted into 4 bit 
*	   	  representation for binary number.
***************************************************************************************************/

void decToBin(int decimalNumber, int numBit){
	
	int binArrLenth = numBit;						// Binary array length same as "numBit"
	int binArr[binArrLenth]= {0};					// int array to store binary number
	
	while(decimalNumber > 0){
		binArr[--numBit] = decimalNumber%2;			// reminder will be stored in an array in reverse order
		decimalNumber = decimalNumber/2;
	}
	
	for(int i=0; i < binArrLenth; i++){				// displays binary no.
		if(i%4 == 0){								// adding a space after every 4 bits
			cout<<' ';
			output<<' ';							
		}
		cout<<binArr[i];							// displays Binary number
		output<<binArr[i];							// displays Binary number in "output.txt"
	}
}
/***************************************************************************************************
*decToHexa(int decimalNumber):
*Purpose: This function will help to convert Decimal number to Hexadecimal number.
*   	  
***************************************************************************************************/
void decToHexa(int decimalNumber){

	int numBit = 2;									// two bits representation of hexadecimal value
	char hexNumber[2]= {'0'};						// to store hexadecimal value into char array
	if(decimalNumber == 0){
		cout<<"0";
		output<<"0";								
	}
	
	while(decimalNumber != 0){	
		int temp = 0;								// to store reminder in temporary variable
		temp = decimalNumber%16;
		
		if(temp < 10)
			hexNumber[--numBit] = temp + 48;		// adding temp with 48 will convert to corresponding char value
		else
			hexNumber[--numBit] = temp + 55;		// adding temp with 55 will convert to corresponding char value	
		
		decimalNumber = decimalNumber/16;		
	}
	
	for(int i=0; i< 2; i++){						// displays hexadecimal number
	
		cout<<hexNumber[i];
		output<<hexNumber[i];						//display in "output.txt"
	}		
}
/***************************************************************************************************
*void decToBCD(int n):
*Purpose: This function will help to convert from decimal to BCD conversion.
*   	  First converting Decimal number into string. Then seprating each character of string and 
* 		  converted into 4 bit binary number using "decToBin" function.
***************************************************************************************************/
void decToBCD(int decimalNumber){
	
	string numStr = to_string(decimalNumber);	// Converting number into string		
	int len = numStr.length();					// length of string		
	
	for(int i=0; i< len/2; i++){				// reverse string to reverse decimal number												
		char temp = numStr[i];
		numStr[i] = numStr[len-i-1] ;
		numStr[len-i-1] = temp;
	}
		
	//for(int i=0; i<=len-1; i++)
	for(int i=2; i>=0; i--){					// each string char converted into corresponding binary number	
		char a = numStr[i];						// "char a" to store each string char 
		string str ; //b=""		
		str.append(1, a);	//b= a +b ;
		int B = atoi(str.c_str());			  	// convert string to integer
		decToBin(B,4);							// converting corresponding decimal number into 4 bit binary number
	}
}
/***************************************************************************************************
*int main():
*Purpose: required output will display using above functions of decimal to other base conversion. 
*   	  Output will be displayed into "output.txt" file too.
***************************************************************************************************/
int main(){
	
	cout<<"\n";
	cout<<"DECIMAL"<<"\t\t\t"<<" BINARY"<<"\t\t\t"<<"HEXADECIMAL"<<"\t\t"<<" BCD"<<endl;
	
	output<<"\n";
	output<<"DECIMAL"<<"\t\t\t"<<" BINARY"<<"\t\t\t"<<"HEXADECIMAL"<<"\t\t"<<" BCD"<<endl;
	
	int i;
	for(i=0; i<=255; i++){					// displayed decimal conversion from 0 to 255
		
		cout<<i<<"\t\t\t"; 
		output<<i<<"\t\t\t";
		
		decToBin(i,8); 
		
		cout<<"\t\t"; 
		output<<"\t\t";
		
		decToHexa(i); 
		
		cout<<"\t\t\t"; 		
		output<<"\t\t\t";
		
		decToBCD(i); 	
		
		cout<<endl;
		output<<endl;		
	}	
	output.close();							//  closeing the file
	return 0;
}






	