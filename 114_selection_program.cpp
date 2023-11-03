#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

// Missing features:
// Delete entries in vector

void displayMenu();
char selectionCheck(char& selection);
void addNumbers(int amount, vector<int>& collectionToAdd, int actualNumber);
void printNumbers(const vector <int>& collection);
int averageNumber(const vector <int>& collection);
void averageImpossible(const vector <int> collection);
int smallestNumber(const vector <int>& collection);
int largestNumber(const vector <int>& collection);
void defaultOutput();
void goodbye();

int main()
{
	vector <int> collection{}; // The actual "Number Storage" collection vector
	char selection; // Menu option user selection
	int amount_numbers{}; // Case a: used for amount of numbers user wants to store
	int add_number{}; // Stores the actual number user wants to store and adds it to vector "collection" via pushback

	do
	{
		displayMenu();
		cin >> selection;
		selectionCheck(selection);

		switch (selection)
		{
		case 'P':
			printNumbers(collection);
			break;
		case 'A':
			system("CLS");
			cout << "Add your numbers to the collection." << endl;
			cout << "How many numbers do you want to add to the collection? " << endl;
			cin >> amount_numbers;

			if (cin.fail()) {
				cin.clear();
				break;
			}
			else
			{
				addNumbers(amount_numbers, collection, add_number);
			}
			break;
		case 'M': // Calculate the average of all numbers in collection
			system("CLS");
			if (collection.size() == 0)
			{
				averageImpossible(collection);
			}
			else {
				cout << averageNumber(collection);
				cout << endl;
			}
			this_thread::sleep_for(chrono::seconds(3));
			break;
		case 'S': // Smallest number in vector
			system("CLS");
			cout << smallestNumber(collection);
			this_thread::sleep_for(chrono::seconds(3));
			break;
		case 'L': // Largest number in vector
			system("CLS");
			cout << largestNumber(collection);
			this_thread::sleep_for(chrono::seconds(3));
			break;
		case 'Q': // Quit program
			goodbye();
			break;
		default: // Unknown selection or illegal input - please try again
			defaultOutput();
			break;
		}
	} while (selection != 'Q');
	return 0;
}
void displayMenu() {
	system("CLS");
	cout << "Welcome to *NUMBER STORAGE*" << endl << endl;
	cout << "---------------------------------" << endl;
	cout << "P - Print numbers" << endl;
	cout << "A - Add a number" << endl;
	cout << "M - Display mean (average) of the collection" << endl;
	cout << "S - Display smallest number" << endl;
	cout << "L - Display the largest number" << endl;
	cout << "Q - Quit" << endl << endl;
	cout << "---------------------------------" << endl;
	cout << "\nEnter your choice: " << endl << endl;
}
char selectionCheck(char& selection) {
	if (!isupper(selection))
	{
		return selection = toupper(selection);
	}
	else if (isdigit(selection)) {
		defaultOutput();
	}
}
void addNumbers(int amount, vector<int>& collectionToAdd, int actualNumber) {
	system("CLS");
	for (size_t i = 0; i < amount; ++i)
	{
		cout << "Add: ";
		cin >> actualNumber;
		collectionToAdd.push_back(actualNumber);
		cout << endl << "Number * " << actualNumber << " * added to the collection." << endl;
		cout << "You still wanted to add * " << amount - i - 1 << " * more numbers to the collection." << endl;
		cout << endl;
	}
}
void printNumbers(const vector <int>& collection) {
	if (collection.size() == 0)
	{
		system("CLS");
		cout << "The database currently stores: " << collection.size() << " elements" << endl;
		cout << "\nNo numbers to print - try to enter some first, using A." << endl << endl;
		this_thread::sleep_for(chrono::seconds(4));
	}
	else
	{
		system("CLS");
		cout << "[ ";
		for (size_t i = 0; i < collection.size(); ++i)
		{
			cout << collection.at(i) << " ";
		}
		cout << "]" << endl;
		if (collection.size() == 1)
		{
			cout << "\nThe database currently stores: " << collection.size() << " element";
		}
		else
		{
			cout << "\nThe database currently stores: " << collection.size() << " elements";
		}
		this_thread::sleep_for(chrono::seconds(4));
	}
}
int averageNumber(const vector <int>& collection) {
	int total{};
	for (int number : collection)
	{
		total += number;
	}
	cout << "Average of all numbers in collection is: ";
	return total / collection.size();
}
void averageImpossible(const vector <int> collection) {
	cout << "Unable to calculate the mean - not enough data found" << endl << endl;
	cout << "Database currently holds " << collection.size() << " element(s)" << endl;
	cout << "Try adding at least 2 numbers to the collection via main menu first" << endl << endl;
}
int smallestNumber(const vector <int>& collection) {
	if (collection.size() == 0)
	{
		cout << "Unable to determine the smallest number - collection is empty" << endl;
		cout << "Collection size is: ";
		return 0;
	}
	else
	{
		int smallest = collection.at(0);
		for (size_t i{ 0 }; i < collection.size(); ++i)
		{
			if (collection.at(i) < smallest)
			{
				smallest = collection.at(i);
			}
		}
		cout << "The smallest number in your collection is: ";
		return smallest;
	}
}
int largestNumber(const vector <int>& collection) {
	if (collection.size() == 0)
	{
		cout << "Unable to determine the largest number - collection is empty" << endl;
		cout << "Collection size is: ";
		return 0;
	}
	else
	{
		int largest = collection[0];
		for (size_t i = 0; i < collection.size(); ++i)
		{
			if (collection.at(i) > largest)
			{
				largest = collection.at(i);
			}
		}
		cout << "The largest number in your collection is: ";
		return largest;
	}
}
void defaultOutput() {
	system("CLS");
	cout << "Unknown selection or illegal input - please try again\n" << endl;
	this_thread::sleep_for(chrono::seconds(2));
	return;
}
void goodbye() {
	system("CLS");
	cout << "Goodbye..." << endl;
}