
//*********************************************************************************************************************************
//       Author:            Shruti Manikrao Basutkar
//       Creation Date:     09/03/2019
//       Purpose:           This program is for conversion of Decimal number to Binary, Hexadecimal and Binary coded decimal(BCD).
//   
//*********************************************************************************************************************************

#include<iostream>		
#include<string>        
#include<sstream>	
#include <cstdlib>      
#include<fstream>

using namespace std;

ofstream output("output.txt"); 		

template <typename T>
string to_string(const T& value){
    stringstream ss;
    ss << value;
    return ss.str();
}


void decToBin(int decimalNumber, int numBit){
	
	int binArrLenth = numBit;					
	int binArr[binArrLenth]= {0};					
	
	while(decimalNumber > 0){
		binArr[--numBit] = decimalNumber%2;			
		decimalNumber = decimalNumber/2;
	}
	
	for(int i=0; i < binArrLenth; i++){				
		if(i%4 == 0){								
			cout<<' ';
			output<<' ';							
		}
		cout<<binArr[i];							
		output<<binArr[i];							
	}
}

void decToHexa(int decimalNumber){

	int numBit = 2;								
	char hexNumber[2]= {'0'};				
	if(decimalNumber == 0){
		cout<<"0";
		output<<"0";								
	}
	
	while(decimalNumber != 0){	
		int temp = 0;							
		temp = decimalNumber%16;
		
		if(temp < 10)
			hexNumber[--numBit] = temp + 48;		
		else
			hexNumber[--numBit] = temp + 55;		
		
		decimalNumber = decimalNumber/16;		
	}
	
	for(int i=0; i< 2; i++){						
	
		cout<<hexNumber[i];
		output<<hexNumber[i];						
	}		
}

void decToBCD(int decimalNumber){
	
	string numStr = to_string(decimalNumber);		
	int len = numStr.length();						
	
	for(int i=0; i< len/2; i++){															
		char temp = numStr[i];
		numStr[i] = numStr[len-i-1] ;
		numStr[len-i-1] = temp;
	}
		
	//for(int i=0; i<=len-1; i++)
	for(int i=2; i>=0; i--){					
		char a = numStr[i];					
		string str ; //b=""		
		str.append(1, a);	//b= a +b ;
		int B = atoi(str.c_str());			 
		decToBin(B,4);						
	}
}

int main(){
	
	cout<<"\n";
	cout<<"DECIMAL"<<"\t\t\t"<<" BINARY"<<"\t\t\t"<<"HEXADECIMAL"<<"\t\t"<<" BCD"<<endl;
	
	output<<"\n";
	output<<"DECIMAL"<<"\t\t\t"<<" BINARY"<<"\t\t\t"<<"HEXADECIMAL"<<"\t\t"<<" BCD"<<endl;
	
	int i;
	for(i=0; i<=255; i++){					
		
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
	output.close();							
	return 0;
}






	
