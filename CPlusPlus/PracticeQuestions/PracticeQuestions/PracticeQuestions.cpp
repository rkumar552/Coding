// PracticeQuestions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
void Subset(int *data, int n);
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

int main()
{
	char *str1 = "ABACBDAE";
	char *str2 = "ABABA";
	////int index1 = firstNonRecurringChar(str1);
	//int index2 = firstNonRecurringChar(str2);
	int arr[] = { 1,2,3 };
	vector<int> arr2 = { 1,2,3 };
	//Subset(arr, 3);
	printSubsetRecursive(arr2);
	return 0;
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



