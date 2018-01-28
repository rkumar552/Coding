#include "stdafx.h"
#include "strings.h"

void TestPalindromicStrings()
{
	string inputString = "ABBAACBC";
	//string output = longestPalindromicStr1(inputString);
	string output = longestPalindromicStr2(inputString);
	

}

void TestRemoveDuplicateSpaces()
{
	char *str = "   Hello   world   guys  ";
	int len = strlen(str);
	//if we dont allocate memory in heap the string manipulation will give Access violation errors.
	char *newInput = new char[len+1];
	strcpy_s(newInput, len + 1, str);
	cout << newInput;
	//clean up the allocated memory
	delete[]newInput;
}