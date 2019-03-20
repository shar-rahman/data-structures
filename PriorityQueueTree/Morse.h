#pragma once
#include <string>
using namespace std;
#define ALPHA_SIZE 36

struct MorseSequence
{
	string symbol;
	string binary;
	int priority;
};

MorseSequence MorseEncode[ALPHA_SIZE] = {
	{"A", "1001", 9},
	{"B", "01101010", 106},
	{"C", "01100110", 102},
	{"D", "011010", 26},
	{"E", "10", 2},
	{"F", "10100110" , 166},
	{"G", "10110", 22},
	{"H", "10101010", 170},
	{"I", "1010", 10},
	{"J", "10010101", 149},
	{"K", "011001", 25},
	{"L", "10011010", 154},
	{"M", "0101", 5},
	{"N", "0110", 6},
	{"O", "010101", 21},
	{"P", "10010110", 150},
	{"Q", "01011001", 89},
	{"R", "100110", 38},
	{"S", "101010", 42},
	{"T", "01", 1},
	{"U", "101001", 41},
	{"V", "01010110", 86},
	{"W", "011010", 26},
	{"X", "01101001", 105},
	{"Y", "01100101", 101},
	{"Z", "01011010", 90},
	{"0", "0101010101", 341},
	{"1", "1001010101", 597},
	{"2", "1010010101", 661},
	{"3", "1010100101", 677},
	{"4", "1010101001", 681},
	{"5", "1010101010", 682},
	{"6", "0110101010", 426},
	{"7", "0101101010", 362},
	{"8", "0101011010", 346},
	{"9", "0101010110", 342}
};

//class EncodeSequence
//{
//private:
//	MorseSequence sequence;
//public:
//	EncodeSequence()
//	{
//		sequence.binary = 0;
//		sequence.priority = 0;
//		sequence.symbol = '';
//	}
//	EncodeSequence(string symbol)
//	{
//		for (int i = 0; i < ALPHA_SIZE; i++)
//		{
//			if (symbol == MorseEncode[i].symbol)
//				sequence = MorseEncode[i];
//		}
//	}
//
//	void setSymbol(char sym)
//	{
//		sequence.symbol = sym;
//	}
//	void setBinary(int bin)
//	{
//		sequence.binary = bin;
//	}
//	void setDecimal(int dec)
//	{
//		sequence.priority = dec;
//	}
//
//	int getBinary() { return sequence.binary; }
//	string getSymbol() { return sequence.symbol; }
//	int getDecimal() { return sequence.priority; }
//
//};