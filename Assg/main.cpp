#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "user.h"
#include "topic.h"
using namespace std;

void registeruser(){
	string username;
	string password;
	cout << "Input username:";
	//check if username is in database
	cin >> username;
	cout << "Input password:";
	cin >> password;
	User user1(username, password);
	//return user1;
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
	//open file
	ofstream fw("topic.txt", std::ofstream::out);
	//write into file
	if (fw.is_open())
	{
		//store array contents to text file
		for (int i = 0; i < sizeof(Topic); i++) {
			fw << Topic[i] << "\n";
		}
		fw.close();
	}
	else cout << "Problem with opening file";
	//read from file
	string line;
	ifstream myfile("topic.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
			vector<string> arr;
			arr.push_back(line);
		}
		myfile.close();
	}
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

