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
	int topicid=0;
	Topic topic1(topicid,topicname, topictext);
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
Topic* loadtopic() {
	string line;
	ifstream topicfile("topic.txt");
	static Topic topics[10] = {};
	int counter = 0;
	if (topicfile.is_open())
	{
		while (getline(topicfile, line))
		{
			//attempt to convert string from file into object
			Topic topic1;
			int index = 0;
			stringstream s_stream(line); //create string stream from the string
			while (s_stream.good()) {

				string substr;
				getline(s_stream, substr, ',');//get first string delimited by comma

				//cout << substr;
				if (index == 0) {

					topic1.setTopicId(stoi(substr));
				}
				else if(index ==1) {
					topic1.setTopicName(substr);
				}
				else if (index == 2) {
					topic1.setTopicText(substr);
				}
				//topic1.getTopicName();
				index++;
				
			}
			cout << "" << endl;
			topics[counter] = topic1;
			counter++;
		}
		topicfile.close();
		
	}
	return topics;
}
void displaytopics(Topic *alltopic) {
	string input;
	cout << "TOPICS" << endl;
	for (int i = 0; i < 3; i++) {
		cout << i+1 << ". ";
		cout << alltopic[i].getTopicName() << " ";
		cout << alltopic[i].getTopicText() << endl;
	}
	cout << "Type new to Create new topic" << endl;
	cout << "Input your choice:" << endl;
	cin >> input;
	if (input == "new") {
		createtopic();
	}
}

void displayposts() {
	//create
}


int main(){
	Topic* alltopic;
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
			alltopic = loadtopic();
			//cout << alltopic[0].getTopicText() << endl;
			displaytopics(alltopic);
		}
		else if (input == 4) {
			break;
		}
	}
}


