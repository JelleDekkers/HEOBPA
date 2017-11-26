#include "stdafx.h"
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

void sortAndSplit(const vector<string>& originalVector);
void capitalizeVectorContent(const vector<string>& originalVector);
template <class T>
void removeDuplicates(const vector<T>& originalVector);

void removeNegativeNumbers(const vector<double>& originalVector);
void determineEvenOddValues(const vector<double>& originalVector);
void printSum(const vector<double>& originalVector);
void printAverage(const vector<double>& originalVector);
void printProduct(const vector<double>& originalVector);

int main() {
	vector<string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	// 1) de vector in 2 nieuwe vectoren te splitsen, 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
	// 2) alle elementen UPPERCASE te maken.
	// 3) alle dubbele te verwijderen

	vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	// 4) alle negatieve elementen te verwijderen
	// 5) voor alle elementen te bepalen of ze even of oneven zijn
	// 6) de som, het gemiddelde, en het product van alle getallen te berekenen

	cout << "Colours: ";
	for (auto &w : colours)
		cout << w << " ";
	cout << "\n" << "\n";

	cout << "Opdracht 1 (Sort & Split into 2 vectors)" << endl;
	sortAndSplit(colours);

	cout << "Opdracht 2 (Capitalize strings)" << endl;
	capitalizeVectorContent(colours);

	cout << "Opdracht 3 (Remove dusplicates)" << endl;
	removeDuplicates(colours);

	cout << "Numbers: ";
	for (auto &w : numbers)
		cout << w << " ";
	cout << "\n" << "\n";

	cout << "Opdracht 4 (Remove negative numbers)" << endl;
	removeNegativeNumbers(numbers);

	cout << "Opdracht 5 (Determine even & odd numbers)" << endl;
	determineEvenOddValues(numbers);

	cout << "Opdracht 6.1 (get sum)" << endl;
	printSum(numbers);

	cout << "Opdracht 6.2 (get average)" << endl;
	printAverage(numbers);

	cout << "Opdracht 6.3 (get product)" << endl;
	printProduct(numbers);

	return 0;
}

// opdracht 1
void sortAndSplit(const vector<string>& originalVector) {
	vector<string> vectorCopy = originalVector;
	sort(vectorCopy.begin(), vectorCopy.end());
	string sortBoundary = "purple";
	int sortFromIndex;

	for (vector<string>::const_iterator it = vectorCopy.begin(); it != vectorCopy.end(); ++it) {
		if (*it == sortBoundary) {
			sortFromIndex = it - vectorCopy.begin();
			break;
		}
	}

	// remove purple:
	vectorCopy.erase(vectorCopy.begin() + sortFromIndex);

	vector<string> vectorBelow(vectorCopy.begin(), vectorCopy.begin() + sortFromIndex);
	vector<string> vectorAbove(vectorCopy.begin() + sortFromIndex, vectorCopy.end());

	cout << "Before: " << sortBoundary << endl;
	for (vector<string>::iterator it = vectorBelow.begin(); it != vectorBelow.end(); ++it) 
		cout << *it << " ";

	cout << "\n";
	cout << "After: " << sortBoundary << endl;
	for (vector<string>::iterator it = vectorAbove.begin(); it != vectorAbove.end(); ++it) 
		cout << *it << " ";

	cout << "\n" << "\n";
}

// opdracht 2
void capitalizeVectorContent(const vector<string>& originalVector) {
	vector<string> vectorCopy = originalVector;

	for_each(vectorCopy.begin(), vectorCopy.end(), [](string& s) -> void { 
		s[0] = toupper(s[0]);
	});

	for (vector<string>::iterator it = vectorCopy.begin(); it != vectorCopy.end(); ++it) 
		cout << *it << " ";

	cout << "\n" << "\n";
}

// opdracht 3
template <class T>
void removeDuplicates(const vector<T>& originalVector) {
	vector<T> vectorCopy = originalVector;
	sort(vectorCopy.begin(), vectorCopy.end());
	auto last = unique(vectorCopy.begin(), vectorCopy.end());
	vectorCopy.erase(last, vectorCopy.end());

	for (vector<T>::iterator it = vectorCopy.begin(); it != vectorCopy.end(); ++it) 
		cout << *it << " ";

	cout << "\n" << "\n";
}

bool isNegative(double value) {
	return value < 0;
}

// opdracht 4
void removeNegativeNumbers(const vector<double>& originalVector) {
	vector<double> vectorCopy = originalVector;
	vector<double>::iterator it;
 	it = remove_if(vectorCopy.begin(), vectorCopy.end(), isNegative), vectorCopy.end();
	vectorCopy.erase(it, vectorCopy.end());

	for (vector<double>::iterator it = vectorCopy.begin(); it != vectorCopy.end(); ++it)
		cout << *it << " ";

	cout << "\n" << "\n";
}

// opdracht 5
void determineEvenOddValues(const vector<double>& originalVector) {
	vector<double> vectorCopy = originalVector;
	
	for_each(vectorCopy.begin(), vectorCopy.end(), [](double& val) -> void {
		if (fmod(val, 2)== 0)
			cout << val << " is even" << endl;
		else
			cout << val << " is odd" << endl;
	});


	cout << "\n";
}

// opdracht 6.1
void printSum(const vector<double>& originalVector) {
	double sum;
	for_each(originalVector.begin(), originalVector.end(), [&](int n) {
		sum += n;
	});
	cout << "Sum is: " << sum << endl;
	cout << "\n";
}


// opdracht 6.2
void printAverage(const vector<double>& originalVector) {
	double sum;
	for_each(originalVector.begin(), originalVector.end(), [&](int n) {
		sum += n;
	});
	cout << "Average is: " << sum / originalVector.size() << endl;
	cout << "\n";
}

// opdracht 6.3
void printProduct(const vector<double>& originalVector) {
	double product;
	for_each(originalVector.begin(), originalVector.end(), [&](int n) {
		product *= n;
	});
	cout << "Product is: " << product << endl;
	cout << "\n";
}