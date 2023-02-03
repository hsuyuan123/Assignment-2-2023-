#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "user.h"
#include "List.h"

//#include "topic.h"
using namespace std;


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

			/*string array[2];

			split(line, array);
			if (array[0] == username)
			{
				available = false;
				break;
			}*/
			int index = 0;
			stringstream s_stream(line); //create string stream from the string
			while (s_stream.good()) {

				string substr;
				getline(s_stream, substr, ',');//get first string delimited by comma

				//cout << substr;
				if (index == 0) {

					if (username == substr)
					{
						available = false;
						break;
					}
					break;
				}
				/*else if(index ==1) {
					if (password == substr)
					{
						available = false;
						break;
					}
				}
				index++;*/
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

string loginuser() {
	string username;
	string password;
	string input;
	string line;
	ifstream myfile;
	ofstream myfile2;
	bool valid = false;

	cout << "Input username: ";

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

			/*string array[2];

			split(line, array);
			if (array[0] == username)
			{
				valid = true;
				password = array[1];
				break;
			}*/
			int index = 0;
			stringstream s_stream(line); //create string stream from the string
			while (s_stream.good()) {

				string substr;
				getline(s_stream, substr, ',');//get first string delimited by comma

				//cout << substr;
				if (index == 0) {

					if (username == substr)
					{
						valid = true;
						
					}
				}
				else if(index ==1) {
					password = substr;
					if (valid==true)
					{
						
						break;
					}
				}
				index++;
			}

		}
		myfile.close();
		
		while (valid==true)
		{
			cout << "Input password (0 to exit): ";
			cin >> input;
			if (input == password)
			{
				cout << "Welcome back, " + username << endl;
				return username;
			}
			else if (input == "0")
			{
				return "";
			}
			else
			{
				cout << "Wrong password" << endl;
			}
		}
		
		cout << "Username not in database" << endl;
		return "";
		

	}

}

//void createtopic() {
//	string topicname;
//	string topictext;
//	int topicid=0;
//	Topic topic1(topicid,topicname, topictext);
//	bool available = true;
//
//	string line;
//	ifstream myfile;
//	ofstream myfile2;
//
//	myfile.open("topic.txt");
//	if (!myfile)
//	{
//		cout << "Error" << endl;
//	}
//	myfile2.open("topic.txt", ios::app);
//	//int topicid; //find id of last post
//	cout << "Input topic title:";
//	cin >> topicname;
//	cout << "Input topic content:";
//	cin >> topictext;
//	string combined = topicid + "," + topicname + "," + topictext + "\n";
//	myfile2 << combined;
//	cout << "Topic created.";
//	myfile2.close();
//
//}
//Topic* loadtopic() {
//	string line;
//	ifstream topicfile("topic.txt");
//	static Topic topics[10] = {};
//	int counter = 0;
//	if (topicfile.is_open())
//	{
//		while (getline(topicfile, line))
//		{
//			//attempt to convert string from file into object
//			Topic topic1;
//			int index = 0;
//			stringstream s_stream(line); //create string stream from the string
//			while (s_stream.good()) {
//
//				string substr;
//				getline(s_stream, substr, ',');//get first string delimited by comma
//
//				//cout << substr;
//				if (index == 0) {
//
//					topic1.setTopicId(stoi(substr));
//				}
//				else if(index ==1) {
//					topic1.setTopicName(substr);
//				}
//				else if (index == 2) {
//					topic1.setTopicText(substr);
//				}
//				//topic1.getTopicName();
//				index++;
//				
//			}
//			cout << "" << endl;
//			topics[counter] = topic1;
//			counter++;
//		}
//		topicfile.close();
//		
//	}
//	return topics;
//
//}
//void displaytopics(Topic *alltopic) {
//	string input;
//	cout << "TOPICS" << endl;
//	for (int i = 0; i <3; i++) {
//		cout << i+1 << ". ";
//		cout << alltopic[i].getTopicName() << " ";
//		cout << alltopic[i].getTopicText() << endl;
//	}
//	cout << "Type new to Create new topic" << endl;
//	cout << "Input your choice:" << endl;
//	cin >> input;
//	if (input == "new") {
//		createtopic();
//	}
//}

List displayTopics()
{
	int id=1;
	List topicList;
	string name;
	string line;
	ifstream myfile;
	ofstream myfile2;
	myfile.open("topic.txt");
	if (!myfile)
	{
		cout << "Error" << endl;
	}
	else
	{
		while (getline(myfile, line))
		{
			name = line;
			cout << id << ". " + name << endl;
			topicList.add(name);
			id++;
		}
		myfile.close();	
	}
	return topicList;
}

List topicContent(string fileName)
{
	string line;
	ifstream myfile;
	string name;
	string content;
	List topicContent;
	int counter = 0;
	myfile.open(fileName+ ".txt");
	if (!myfile)
	{
		ofstream myfile2(fileName + ".txt");
		myfile2.close();
	}
	cout << fileName << endl << "------------------------------------" << endl;
	while (getline(myfile, line))
	{
			
		int index = 0;
		stringstream s_stream(line); //create string stream from the string

		while (s_stream.good()) {
			
			string substr;
			getline(s_stream, substr, ',');
			
			//cout << substr;
			if (index == 0) {
			
				content = substr;
			}
			else if(index ==1) {
				name = substr;
			}
			/*else if (index == 2) {

			}*/
			index++;
							
		}
		
		

		cout << counter+1<<". "<<content << ", by " << name << endl;
		counter++;
		topicContent.add(line);
	}
	myfile.close();
	return topicContent;
}
string postContent(string fileName) //Return owner
{
	string line;
	ifstream myfile;
	string name;
	string username;
	string content;
	int counter = 0;
	myfile.open(fileName + ".txt");
	if (!myfile)
	{
		ofstream myfile2(fileName + ".txt");
		myfile2.close();
	}
	int index = 0;
	stringstream s_stream(fileName);
	while (s_stream.good()) {

		string substr;
		getline(s_stream, substr, ','); 
		//cout << substr;

		if (index == 1) {

			name = substr;
		}
		else if (index == 2) {

			username = substr;
		}
		index++;
	}
	
	cout << name << endl << "------------------------------------" << endl;
	while (getline(myfile, line))
	{

		int index = 0;
		stringstream s_stream(line); //create string stream from the string

		while (s_stream.good()) {

			string substr;
			getline(s_stream, substr, '`'); //Delimiter is `

			//cout << substr;
			if (index == 0) {

				name = substr;
			}
			else if (index == 1) {
				content = substr;
			}
			/*else if (index == 2) {

			}*/
			index++;

		}


		cout <<counter+1<<". "+ name << ": " << content << endl;
		counter++;
	}
	myfile.close();
	return username;
}
void replyPost(string fileName,string username)
{
	string line;
	ifstream myfile;
	string name;
	string content;
	myfile.open(fileName + ".txt");
	if (!myfile)
	{
		ofstream myfile2(fileName + ".txt");
		myfile2.close();
	}
	ofstream myfile2;
	myfile2.open(fileName+".txt", ios::app);
	string reply;
	cout << "Replying: ";
	cin.ignore();
	getline(cin, reply);
	string combined = username + "`" + reply + "\n";
	myfile2 << combined;
	cout << "Reply sent" << endl;
	myfile2.close();
}
void deleteReply(string fileName, string username)
{
//	string line;
//	ifstream myfile;
//	string name;
//	string content;
//	bool valid = false;
//	myfile.open(fileName + ".txt");
//	if (!myfile)
//	{
//		ofstream myfile2(fileName + ".txt");
//		myfile2.close();
//	}
//	while (getline(myfile, line))
//	{
//		int index = 0;
//		stringstream s_stream(line); //create string stream from the string
//		while (s_stream.good()) {
//			string substr;
//			getline(s_stream, substr, ',');//get first string delimited by comma
//			//cout << substr;
//			if (index == 0) {
//
//				if (username == substr)
//				{
//					valid = true;
//					break;
//
//				}
//			}
//			
//					
//++;
//		}
//
//	}
//	myfile.close();
//	ofstream myfile2;
//	myfile2.open(fileName + ".txt", ios::app);
//	string reply;
//	cout << "Number to delete: ";
//	cin.ignore();
//	getline(cin, reply);
//	if (stoi(reply)
//	string combined = username + "`" + reply + "\n";
//	myfile2 << combined;
//	cout << "Reply sent" << endl;
//	myfile2.close();
}
void init()// Make sure files exist so there is no error
{
	string line;
	ifstream myfile;
	string variableArray[] = {"topic","users"};
	for (int i = 0; i > sizeof(variableArray) / sizeof(variableArray[0]); i++)
	{
		myfile.open(variableArray[i]);
		if (!myfile)
		{
			
			ofstream myfile2(variableArray[i]+".txt");
			myfile2.close();
		}
		myfile.close();
		
	}
}
void displayMenuNoLogin() //When not logged in
{
	cout << "1. View Topics" << endl;
	cout << "2. Register" << endl;
	cout << "3. Login" << endl;
	cout << "0. Exit" << endl;
	cout << "What would you like to do?: ";
}
void displayMenuLogin() //When logged in
{
	cout << "1. View Topics" << endl;
	cout << "2. Topics you visited" << endl;
	cout << "3. Logout" << endl;
	cout << "0. Exit" << endl;
	cout << "What would you like to do: ";
}
void displayReplyMenu(int i)
{
	if (i == 1)
	{
		cout << "1. Reply" << endl;
		cout << "2. Edit reply" << endl;
		cout << "3. Delete reply" << endl;
		cout << "0. Exit" << endl;
		cout << "What would you like to do: ";
	}
	else
	{
		cout << "1. Reply" << endl;
		cout << "2. Edit reply" << endl;
		cout << "3. Delete reply" << endl;
		cout << "4. Delete post" << endl;
		cout << "0. Exit" << endl;
		cout << "What would you like to do: ";
	}
	
}

int main(){
	/*Topic* alltopic;*/
	init();
	string username="";
	//Topic topicList;
	List topicList;
	List topicContentList;
	//Initiate topics into a list
	//string line;
	//ifstream myfile;
	while (true){
		int input;
		if (username != "") //Logged in
		{
			displayMenuLogin();
			cin >> input;
			cout  << endl;
			if (input == 0) //Exit
			{
				cout << "Goodbye!" << endl;
				break;
			}
			else if (input == 1) //View Topics
			{
				//alltopic = loadtopic();
				////cout << alltopic[0].getTopicText() << endl;
				//displaytopics(alltopic);
				topicList=displayTopics();
				int choice;
				cout << "Topic to visit(0 to exit): ";
				cin >> choice;
				cout << endl;
				if (choice == 0)
				{
					continue;
				}
				else
				{
					string topic = topicList.get(choice - 1);
					topicContentList=topicContent(topic);
					cout << "Post to visit(0 to exit): ";
					cin >> choice;
					cout << endl;
					if (choice == 0)
					{
						continue;
					}
					else
					{
						string post = topicContentList.get(choice - 1);
						string owner=postContent(topic + ","+post);
						cout << endl;
						while (true)
						{
							if (username != owner)
							{
								displayReplyMenu(1);
							}
							else
							{
								displayReplyMenu(0);
							}
							cin >> choice;
							cout << endl;
							if (choice == 0)
							{
								break;
							}
							else if (choice == 1) //Reply
							{
								replyPost(topic + "," + post,username);
								break;
								
							}
							else if (choice == 2) //Edit Reply
							{
								
							}
							else if (choice == 3) //Delete Reply
							{
								//deleteReply();
							}
							else if (choice == 4&&username==owner) //Delete post
							{

							}
						}
						

					}
				}
				
			}
			else if (input == 2) // Topics you visited
			{
				//Put new things here
			}
			else if (input == 3) //Logout
			{
				string username = "";
				cout << "You have logged out. ";
			}
			
		}
		else //Not logged in
		{
			displayMenuNoLogin();
			cin >> input;
			cout << " " << endl;
			if (input == 0) //Exit
			{
				cout << "Goodbye!" << endl;
				break;
			}
			else if (input == 1) //View Topics
			{
				//alltopic = loadtopic();
				////cout << alltopic[0].getTopicText() << endl;
				//displaytopics(alltopic);
				displayTopics();

			}
			else if (input == 2)//Register
			{
				registeruser();
				cout << endl;
			}
			else if (input == 3) //Login
			{
				username=loginuser();
				cout << endl;
			}
		}
		
		
	}
}


