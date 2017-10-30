// SortedDriver.cpp

// tom bailey   1445  25 mar 2014
// Construct sorted sequences and call functions that
//   process the sorted sequences.


#include "RandomUtilities.h"
#include "ContainerPrinting.h"
#include "winTimer.cpp"
#include <list>
#include <iostream>
#include <vector>
#include <cmath>
//#include <algorithm>
	// already included

using namespace std;

double getMostIsolatedNumber(vector<double> &v);


// post: a sorted vector of listSize random doubles from
//         the range minNum to maxNum has been returned.
vector<double>
getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}

	sort(begin(theList), end(theList));

	return theList;
}


// post: a sorted list of numWords words of length
//         wordLength with characters chosen randomly from
//         alphabet has been returned.
list<string>
getWords(size_t numWords, size_t wordLength, string alphabet)
{
	list<string> theWords;
	for (size_t i = 0; i < numWords; ++i)
	{
		string word;
		for (size_t j = 0; j < wordLength; ++j)
		{
			word += alphabet.at(randInt(0, alphabet.size()));
		}
		theWords.push_back(word);
	}

	theWords.sort();

	return theWords;
}


// pre:  number is not empty;
//       number is sorted from smallest to largest
// post: The most isolated entry in number has been returned
double
mostIsolated(vector<double> & number)
{
	// STUB  STUB  STUB
	return -123.456;
}


// pre:  A and B are sorted.
// post: The number of strings in A that do not occur in B
//         has been returned.
int
unmatched(list<string> & A, list<string> & B)
{
	// STUB  STUB  STUB
	return -1;
}


int
main()
{
	cout << "Find the most isolated number" << endl
		<< "-----------------------------" << endl << endl;
	while (true)
	{
		cout << "Enter size for numbers: ";
		int n = 0;
		cin >> n;
		if (n <= 0)
			break;
		cout << "Enter seed for rand: ";
		unsigned int seed;
		cin >> seed;
		srand(seed);

		// Construct a sorted list of numbers
		Timer get;
		get.start();
		vector<double> numbers = getNums(n, -n, n);
		get.stop();
		cout << "Constructed in " << get() << " seconds"
			<< endl;

		if (n < 10)
			cout << numbers << endl << endl;

		// Report a most isolated isolated number
		Timer time;
		time.start();
		double isolated = getMostIsolatedNumber(numbers);
		time.stop();
		cout << "The most isolated number is "
			<< isolated << endl
			<< "calculated in " << time() << " seconds"
			<< endl << endl;
	}


	cout << endl << endl;
	cout << "Count the unmatched words" << endl
		<< "-------------------------" << endl << endl;
	while (true)
	{
		cout << "Enter size for words lists: ";
		int n = 0;
		cin >> n;
		if (n <= 0)
			break;
		cout << "Enter word length: ";
		int wordSize;
		cin >> wordSize;
		cout << "Enter alphabet: ";
		string alphabet;
		cin >> alphabet;

		cout << "Enter seed for rand: ";
		unsigned int seed;
		cin >> seed;
		srand(seed);

		// Construct two sorted vectors of words
		Timer get;
		get.start();
		list<string> A = getWords(n, wordSize, alphabet);
		list<string> B = getWords(n, wordSize, alphabet);
		get.stop();
		cout << "Constructed in " << get() << " seconds"
			<< endl;

		if (wordSize * n < 60)
		{
			cout << "A is: " << A << endl
				<< "B is: " << B << endl;
		}

		// Report the number of words in the first sorted list
		//   that are not in the second sorted list
		Timer time;
		time.start();
		int count = unmatched(A, B);
		time.stop();
		cout << count
			<< " words in A were not in B" << endl
			<< "calculated in " << time() << " seconds"
			<< endl << endl;
	}

	return 0;
}


double getMostIsolatedNumber(vector<double> &v) {

	double MINumber = 0;
	double difference = 0;
	double differenceL = 0, differenceR = 0;
	double previousNumber, nextNumber;
	// vector<double>::iterator iter = v.begin();

	// struct MINumber mostIsolatedNum;

	// while (iter <= v.end()) {
	for (vector<double>::iterator iter = begin(v); iter != end(v); iter++) {
		// cout << v.begin();
		// system(pause);
		if (iter != begin(v)) {
			// not the first number in the vector

			previousNumber = *(iter - 1);

			differenceL = abs(previousNumber - *iter);
			// iter++;
			// check distance to previous number
			// if (abs(*iter - previousNumber) > difference) {
			// 	difference = abs(*iter - previousNumber);
			// 	MINumber = *iter;
			// }
		}
		else {
			differenceL = 0;
		}

		if (iter != end(v)) {
			// not the last number in the vector

			nextNumber = *(iter + 1);
			differenceR = abs(nextNumber - *iter);
			// iter--;

			// check distance to next number
			// if (abs(nextNumber - *iter) > difference) {
			// 	difference = abs(nextNumber - *iter);
			// 	MINumber = *iter;
			// }
		}
		else {
			differenceR = 0;
		}

		// if (iter  begin(v) && iter != end(v)) {
		//
		// }

		if (iter == begin(v)) {
			if (differenceR > difference) {
				difference = differenceR;
				MINumber = *iter;
			}
		}
		else if (iter == end(v)) {
			if (differenceL > difference) {
				difference = differenceL;
				MINumber = *iter;
			}
		}
		else {
			if (differenceL <= differenceR) {
				if (differenceL > difference) {
					difference = differenceL;
					MINumber = *iter;
				}

			} else if (differenceR < differenceL) {
				if (differenceR > difference) {
					difference = differenceR;
					MINumber = *iter;
				}
			}
		}

		// iter++;
	}


	return MINumber;
}
