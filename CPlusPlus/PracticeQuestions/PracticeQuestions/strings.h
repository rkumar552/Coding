#pragma once
#include "stdafx.h"

//Finding the longest palindromic substring is a classic problem of coding interview.In this post, I
//will summarize 3 different solutions for this problem.
//
// Sol1. Basic brute force solution
// 1. Take all possible substrings 
//2. check each substring which is palindromic
//3. Get the one which is longest

string longestPalindromicStr1(string inputStr);
string longestPalindromicStr2(string inputStr); // approach #2
string longestPalindromicStr3(string inputStr);
void printSubsetRecursive(vector<int> &arr);
void Subset(int *data, int n);
void printRecursiveCore(vector<int> arr, vector<int> sub, int curr);
//find first non-recurring char in a given string
int firstNonRecurringChar(char *str);

//remove all dupicate spaces from the string
// for ex. input is "   Hello   world   " O/p: should be "Hello world" i.e with one space b/w words and no leading or lagging spaces

string RemoveDuplicateSpacesStr(string str);
void   RemoveDupicateSpaceC(char *str);

//Testing

void TestPalindromicStrings();
void TestRemoveDuplicateSpaces();
