#include "stdafx.h"
#include "strings.h"

//
// includes the string related problems
//

bool IsPalindromic(string str)
{
	int start = 0; 
	int end = str.size() - 1;
	while (start <= end)
	{
		if (str[start] == str[end]) {
			start++;
			end--;
		}
		else {
			return false;
		}
	}
	return true;
}
string longestPalindromicStr1(string inputStr)
{
	//
	// validate input str
	//
	if (inputStr.empty())
		return inputStr;

	//
	// we will have two loops to traverse through the input string
	//
	size_t len = inputStr.size();
	string maxPalindromic = ""; //start with empty string
	size_t maxLen = 0;

	for (size_t i = 0; i < len; i++) {
		for (size_t j =  i+1; j < len; j++) {
			string temp = inputStr.substr(i, j);
			//
			// check if this string is palindromic
			if (IsPalindromic(temp)) {
				if (temp.size() > maxLen) {
					maxLen = temp.size();
					maxPalindromic = temp;
				}
			}
		}

	}
	return maxPalindromic;
}
//
// second approach to find longest palindromes is to look at substrings of len = 0 to n-1 and 
// try to expand then from center and see if they are palindrome this will avoid one loop and 
// will have compelxity of O(N^2) as compare to N^3 with approach #1
// each string can have 2N+1 centers one for each char and one between each chars.
// If strings are even length two centers, while if they are odd it will have one center
//

string expandAtCenter(string str, int start, int end)
{
	
	//
	// we need to start at center and expand outwards and compare the chars
	//

	int len = str.length();
	while (start >= 0 && end <= len-1 && str[start] == str[end])
	{
		start--;
		end++;
	}
	//int len = (start > 0) ? end - start : end;
	string temp = str.substr(start+1, (end-start-1));
	return temp;
}
string longestPalindromicStr2(string inputstr)
{
	if (inputstr.empty()) return inputstr;

	size_t len = inputstr.size();

	if (len == 1) return inputstr;

	int maxLen = 1;
	string maxLenStr = inputstr.substr(0,1);
	for (int i = 0; i < len; i++) {

		// here i denotes the traversal across each char, and we will have two potential centers
		// we need to write a function which expands at given centers and finds out max len and also substrings
		//
		// longest palindrome string at center i
		string temp = expandAtCenter(inputstr, i, i);
		if (temp.length() > maxLenStr.length()) {
			maxLenStr = temp;
		}
		//longest palindrome string with centers i, and i+1
		temp = expandAtCenter(inputstr, i, i + 1);
		if (temp.length() > maxLenStr.length()) {
			maxLenStr = temp;
		}
	}
	return maxLenStr;
}





//find first non-recurring char in a given string

int firstNonRecurringChar(char *str)
{
	if (str == NULL) return -1;

	int minIndex = -1; //index of first non recurring char

	int len = strlen(str);
	char charMap[256] = { 0 };

	for (int i = len - 1; i >= 0; i--) {

		//if char is not present or already scanned once
		if (charMap[str[i]] == 0) {
			charMap[str[i]]++;
			if (charMap[str[i]] == 1) {
				minIndex = i;
			}
		}
		else {
			charMap[str[i]]++;
			//if the min so far got duplcated 
			if (str[minIndex] == str[i]) {
				//we got duplicated
				minIndex = -1; //reset it
			}
		}
	}
	if (minIndex != -1) {
		cout << "The first non recurring char is" << str[minIndex];
	}
	return minIndex;

}

void printRecursiveCore(vector<int> arr, vector<int> sub, int curr)
{
	//if we reached end of array print it

	if (curr == arr.size()) {
		for (int i = 0; i < sub.size(); i++) {
			if (sub[i] != 0)
				cout << sub[i] << ",";
		}
		cout << endl;
	}
	else {
		//we have two choices either add current element in set or not
		// first do not add element in set
		//dont do anything and recurse to next
		printRecursiveCore(arr, sub, curr + 1);

		//if we add current element in set
		sub[curr] = arr[curr];
		printRecursiveCore(arr, sub, curr + 1);
	}
}
void printSubsetRecursive(vector<int> &arr)
{
	vector<int> arr2(arr.size());
	cout << "-";
	printRecursiveCore(arr, arr2, 0);

}


void Subset(int *data, int n)
{
	cout << "-" << endl;
	for (int i = 1; i < (1 << n); i++) {

		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				cout << data[j] << ",";
			}
		}
		cout << endl;
	}
}




void   RemoveDupicateSpaceC(char *str)
{
	char *start = str;
	char *end = str;

	while (*end != '\0') {

		while ( *end != '\0' && *end != ' ') {
			*start++ = *end++;
		}

		//skip white spaces
		while ( *end != '\0' && *end == ' ')
			   end++;

		if (start != str && *end != '\0') {
			// if this is not start or end,  add extra space b/w word
			*start++ = ' ';
		}
	}
	*start = '\0';
}