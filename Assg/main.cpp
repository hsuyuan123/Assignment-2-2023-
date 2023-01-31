#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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
	ifstream myfile;
	ofstream myfile2;

	myfile.open("users.txt");
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
		myfile.close();
		if (available == true)
		{
			myfile2.open("users.txt", ios::app);
			cout << "Username available. " << endl;
			cout << "Input password: ";
			cin >> password;
			string combined= username + "," + password + "\n";
			myfile2 << combined;
			cout << "Account created"<<endl;
			myfile2.close();
		}
		else
		{
			cout << "Please choose another username" << endl;
		}
		
	}

	
	
}

bool loginuser() {
	string username;
	string password;
	string input;
	string line;
	ifstream myfile;
	ofstream myfile2;
	bool valid = false;

	cout << "Input username:";

	//check if username is in database
	cin >> username;
	

	myfile.open("users.txt");
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
				valid = true;
				password = array[1];
				break;
			}


		}
		
		while (valid==true)
		{
			cout << "Input password (0 to exit): ";
			cin >> input;
			if (input == password)
			{
				cout << "Welcome back, " + username << endl;
				return true;
			}
			else if (input == "0")
			{
				return false;
			}
			else
			{
				cout << "Wrong password" << endl;
			}
		}
		
		cout << "Username not in database" << endl;
		
		myfile.close();
	}

}

void createtopic() {
	string topicname;
	string topictext;
	Topic topic1(topicname, topictext);
	bool available = true;

	string line;
	ifstream myfile;
	ofstream myfile2;

	myfile.open("topic.txt");
	if (!myfile)
	{
		cout << "Error" << endl;
	}
	myfile2.open("topic.txt", ios::app);
	cout << "Input topic title:";
	cin >> topicname;
	cout << "Input topic content:";
	cin >> topictext;
	string combined = topicname + "," + topictext + "\n";
	myfile2 << combined;
	cout << "Topic created.";
	myfile2.close();

}
void displaytopics() {
	string input;
	cout << "TOPICS" << endl;
	string line;
	ifstream topicfile("topic.txt");
	if (topicfile.is_open())
	{
		while (getline(topicfile, line))
		{
			//attempt to convert string from file into object
			Topic topic1;
			stringstream s_stream(line); //create string stream from the string
			while (s_stream.good()) {
				string substr;
				getline(s_stream, substr, ','); //get first string delimited by comma
				cout << substr;
				topic1.setTopicText(substr);
				//topic1.getTopicName();
			}
		}
		topicfile.close();
	}
	//print all topic names, numbered from 1 to 5
	cout << "7. Create new topic" << endl;
	cout << "Input your choice:" << endl;
	cin >> input;
	//if input == 6, move to next page
	//if input == 7, createtopic()
	if (input == "7") {
		createtopic();
	}
}

void displayposts() {
	//create
}

//void openfiles() {
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
//}

int main(){
	while (true){
		int input;
		cout << " " << endl;
		cout << "1.Register" << endl;
		cout << "2.Login" << endl;
		cout << "3.View Topics" << endl;
		cout << "4.Exit" << endl;
		cout << "What would you like to do:";
		cin >> input;
		cout << " " << endl;
		if (input == 1) {
			registeruser();
		}
		else if (input == 2) {
			loginuser();
		}
		else if (input == 3) {
			displaytopics();
		}
		else if (input == 4) {
			break;
		}
	}
}


