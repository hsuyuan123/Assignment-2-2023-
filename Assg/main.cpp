#include <iostream>
#include <string>
#include "user.h"
#include "topic.h"
using namespace std;

void registeruser(){
	string username;
	string password;
	cout << "Input username:";
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
	cout<<""
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

