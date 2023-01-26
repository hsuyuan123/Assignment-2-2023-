#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "user.h"
#include "topic.h"
using namespace std;

void split(string str, string arr[2]) {
	// declaring temp string to store the curr "word" upto del
	string temp = "";
	string name;
	string password;
	for (int i = 0; i < (int)str.size(); i++) {
		// If cur char is not del, then append it to the cur "word", otherwise
		  // you have completed the word, print it, and start a new word.
		if (str[i] != ',') {
			temp += str[i];
		}
		else if (str[i] == '\n')
		{
			break;
		}
		else {
			name = temp;
			temp = "";
		}
	}

	password= temp;
	arr[0] = name;
	arr[1] = password;
}
void registeruser(){

	string username;
	string password;
	bool available=true;

	cout << "Input username:";
	//check if username is in database
	cin >> username;
	string line;
	fstream myfile;

	myfile.open("users.txt", ios::app);
	if (!myfile)
	{
		cout << "Error" << endl;
	}


	else
	{
		while (getline(myfile, line))
		{

			string array[2];

			split(line, array);
			if (array[0] == username)
			{
				available = false;
				break;
			}

			
		}
		if (available == true)
		{
			cout << "Username available. " << endl;
			cout << "Input password:";
			cin >> password;
			string combined= username + "," + password + "\n";
			myfile << combined;
			
			myfile.close();
		}
		else
		{
			cout << "Please choose another username" << endl;
		}
		
	}
	
		//// opening file using fstream
		//f.open("Geeks for Geeks.txt");
		//while (f >> word) {
		//	cout << word << " ";
		//}
		//f.close();
	
	
}

void createtopic() {
	string topicname;
	string topictext;
	cout << "Input topic title:";
	cin >> topicname;
	cout << "Input topic content:";
	cin >> topictext;
	Topic topic1(topicname, topictext);
}
void displaytopics() {
	string input;
	cout << "TOPICS";
	//print all topic names, numbered from 1 to 5
	cin >> input;
	//if input == 6, move to next page
	//if input == 7, createtopic()
}

void openfiles() {
	////open file
	//ofstream fw("topic.txt", std::ofstream::out);
	////write into file
	//if (fw.is_open())
	//{
	//	//store array contents to text file
	//	for (int i = 0; i < sizeof(Topic); i++) {
	//		fw << Topic[i] << "\n";
	//	}
	//	fw.close();
	//}
	//else cout << "Problem with opening file";
	////read from file
	//string line;
	//ifstream myfile("topic.txt");
	//if (myfile.is_open())
	//{
	//	while (getline(myfile, line))
	//	{
	//		cout << line << '\n';
	//		vector<string> arr;
	//		arr.push_back(line);
	//	}
	//	myfile.close();
	//}
}

int main(){
	
	int input;
	cout << "1.Register" << endl;
	cout << "2.Login" << endl;
	cout << "3.View Topics" << endl;
	cout << "What would you like to do:";
	cin >> input;
	if (input == 1) {
		registeruser();
	}
	else if (input == 3) {
		displaytopics();
	}
}

