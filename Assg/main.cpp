#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "user.h"
#include "List.h"
//#include "topic.h"
using namespace std;
string* split(string str, char del) {
	// declaring temp string to store the curr "word" upto del
	string temp = "";
	static string tempArray[5];
	int counter = 0;
	for (int i = 0; i < (int)str.size(); i++) {
		// If cur char is not del, then append it to the cur "word", otherwise
		  // you have completed the word, print it, and start a new word.
		if (str[i] != del) {
			temp += str[i];
		}
		else {
			if (str[i] != '\n')
			{
				tempArray[counter] = temp;
				temp = "";
				counter++;
			}
			
		}
	}
	tempArray[counter] = temp;
	return tempArray;
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
			string* array = split(line, ',');
			if (username == array[0])
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
			string* array=split(line,',');
			if (array[0] == username)
			{
				valid = true;
				password = array[1];
				
				break;
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
		string* array = split(line, '`');
		name = array[1];
		content = array[0];
		cout << counter + 1 << ". " << content << ", by " << name << endl;
		counter++;
		topicContent.add(line);
	}
		
	
	myfile.close();
	return topicContent;
}

List postContent(string fileName)
{
	string line;
	ifstream myfile;
	string name;
	string username;
	string content;
	int counter = 0;
	List postList;
	myfile.open(fileName + ".txt");
	if (!myfile)
	{
		ofstream myfile2(fileName + ".txt");
		myfile2.close();
	}

	string* array = split(fileName, '`');
	name = array[1];
	username = array[2];

	
	cout << name << endl << "------------------------------------" << endl;
	while (getline(myfile, line))
	{
		
		string* array = split(line, '`');
		name = array[1];
		content = array[2];
		string combined = to_string(counter + 1) + "`" + name + "`" + content + "\n";
		cout << counter + 1 << ". " + name << ": " << content << endl;
		postList.add(combined);
			
		
		counter++;
		
	}
	myfile.close();
	return postList;
}

void replyPost(string fileName,string username,List postList)
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
	string combined = to_string(postList.getLength()+1)+"`"+username + "`" + reply + "\n";
	myfile2 << combined;
	cout << "Reply sent" << endl;
	myfile2.close();
}

void editReply(string fileName, string username, List postList)
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
	myfile.close();
	
	string reply;
	cout << "Choose reply to edit: ";
	string choice;
	cin >> choice;
	string* array=split(postList.get(stoi(choice)-1),'`');
	if (array[1] == username) //Author
	{
		cout << "Edited reply: ";
		string editedReply;
		cin.ignore();
		getline(cin, editedReply);
		postList.remove(stoi(choice)-1);
		string combined= array[0] + "`"  + username + "`" +editedReply+"\n";
		if (stoi(choice) == postList.getLength()+1)
		{
			postList.add(combined);
		}
		else
		{
			postList.add(stoi(choice) - 1, combined);
		}
		
		ofstream myfile2;

		myfile2.open(fileName + ".txt");
		myfile2.close(); //remove content of file
		
		myfile2.open(fileName + ".txt", ios::app);
		
		for (int i = 0;i< postList.getLength(); i++)
		{
			myfile2 << postList.get(i);
		
		}
		cout << "Reply edited" << endl;
		myfile2.close();
	}
	else //Not author
	{
		cout << "You are not the author of this reply." << endl;
	}

	
	
	
}

void deleteReply(string fileName, string username, List postList)
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
	myfile.close();

	string reply;
	cout << "Choose reply to delete(0 to exit): ";
	int choice;
	cin >> choice;
	if (choice == 0)
	{
		
	}
	else
	{
		string* array = split(postList.get(choice - 1), '`');
		if (array[1] == username) //Author
		{

			postList.remove(choice - 1);
			ofstream myfile2;
			myfile2.open(fileName + ".txt");
			myfile2.close(); //Reset contents

			myfile2.open(fileName + ".txt", ios::app);
			for (int i = 0; i < postList.getLength(); i++)
			{
				myfile2 << postList.get(i);
			}

			myfile2.close();


		}
		else //Not author
		{
			cout << "You are not the author of this reply." << endl;
		}
	}
	




}

int deletePost(string fileName)
{
	fileName += ".txt";
	char* char_array = new char[fileName.length() + 1];
	char_array[fileName.length()] = '\0';
	for (int i = 0; i <fileName.length(); i++) {
		char_array[i] = fileName[i];
	}
	int status=remove(char_array);
	/*if (status == 0)
		cout << "Post deleted successfully!" << endl;
	else
		cout << "Error occurred!" << endl;*/
	delete[] char_array;
	return status;
}

string editPost(string fileName, string username, List postList,List topicContentList)
{
	cout << "Editing post(0 to exit): ";
	string* array = split(fileName, '`');
	string edit;
	cin.ignore();
	getline(cin, edit);
	if (edit != "0")
	{
		string line;
		ifstream myfile;
		string name;
		string content;
		string newFileName = array[0] + "`" + edit + "`" + username;
		myfile.open(newFileName + ".txt");
		if (!myfile)
		{
			ofstream myfile2(newFileName + ".txt");
			myfile2.close();
			myfile2.open(newFileName + ".txt", ios::app);
			for (int i = 0; i < postList.getLength(); i++)
			{
				myfile2 << postList.get(i);

			}

			myfile2.close();
			int status = deletePost(fileName);
			if (status == 0)
			{
				
				string* array = split(fileName, '`');
				cout << fileName << endl;
				myfile.open(array[0] + ".txt");
				int i = 0;
				while (getline(myfile, line))
				{
					if (line == array[1]+"`"+array[2])
					{
						string* array = split(newFileName, '`');
						topicContentList.remove(i);
						if (i == topicContentList.getLength())
						{
							topicContentList.add(array[1] + "`" + array[2]);
						}
						else
						{
							topicContentList.add(i, array[1] + "`" + array[2]);
						}
					}
					i++;
				}
				myfile.close();
				myfile2.open(array[0] + ".txt");
				myfile2.close(); //remove content of file

				myfile2.open(array[0] + ".txt", ios::app);

				for (int i = 0; i < topicContentList.getLength(); i++)
				{
					myfile2 << topicContentList.get(i)<<"\n";

				}
				myfile2.close();
				cout << "Post edited successfully!" << endl;

			}

			else
			{
				cout << "Error occurred!" << endl;

			}
			//return newFileName;

		}
		else
		{
			cout << "Post already exists" << endl;
		}

		


	}
	return fileName;
}

//List changeTopicContent(string fileName,string newFileName,string oldFileName)
//{
//	string line;
//	ifstream myfile;
//	string name;
//	string content;
//	List topicContent;
//	int counter = 0;
//	myfile.open(fileName + ".txt");
//	if (!myfile)
//	{
//		ofstream myfile2(fileName + ".txt");
//		myfile2.close();
//	}
//	string* array = split(oldFileName, '`'); //FileNames
//	string oldName = array[1];
//	array = split(newFileName, '`'); //FileNames
//	string newName = array[1];
//	string topicName = array[0];
//	myfile.open(topicName + ".txt");
//	if (!myfile)
//	{
//		ofstream myfile2(topicName + ".txt");
//		while (getline(myfile, line))
//		{
//			array = split(line, '`');
//			content = array[0];
//			name = array[1];
//
//			if (content == oldName)
//			{
//				line = newName + "`" + name;
//
//			}
//			topicContent.add(line);
//		}
//		myfile2.close();
//	}
//	while (getline(myfile, line))
//	{
//		array = split(line, '`');
//		content = array[0];
//		name = array[1];
//		
//		if (content==oldName)
//		{
//			line = newName + "`" + name;
//			
//		}
//		topicContent.add(line);
//	}
//
//
//	myfile.close();
//	return topicContent;
//}

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
	if (i == 1) //Not owner
	{
		cout << "1. Reply" << endl;
		cout << "2. Edit reply" << endl;
		cout << "3. Delete reply" << endl;
		cout << "0. Exit" << endl;
		cout << "What would you like to do: ";
	}
	else //Owner
	{
		cout << "1. Reply" << endl;
		cout << "2. Edit reply" << endl;
		cout << "3. Delete reply" << endl;
		cout << "4. Edit post" << endl;
		cout << "5. Delete post" << endl;
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
	List postList;
	//Initiate topics into a list
	//string line;
	//ifstream myfile;
	while (true){
		try
		{
			string input="Hello";
			if (username != "") //Logged in
			{
				displayMenuLogin();
				cin >> input;
				cout << endl;
				if (input == "0") //Exit
				{
					cout << "Goodbye!" << endl;
					break;
				}
				else if (input == "1") //View Topics
				{
					//alltopic = loadtopic();
					////cout << alltopic[0].getTopicText() << endl;
					//displaytopics(alltopic);
					topicList = displayTopics();
					string choice;
					cout << "Topic to visit(0 to exit): ";
					cin >> choice;
					cout << endl;
					if (choice == "0")
					{
						continue;
					}
					else
					{
						string topic = topicList.get(stoi(choice) - 1);
						topicContentList = topicContent(topic);
						cout << "Post to visit(0 to exit): ";
						cin >> choice;
						cout << endl;
						if (choice == "0")
						{
							continue;
						}
						else
						{
							string post = topicContentList.get(stoi(choice) - 1);
							string fileName = topic + "`" + post;
							postList = postContent(fileName);
							string* array = split(fileName, '`');
							string owner = array[2];
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
								if (choice == "0")
								{
									break;
								}
								else if (choice == "1") //Reply
								{
									replyPost(fileName, username, postList);
									break;

								}
								else if (choice == "2") //Edit Reply
								{
									editReply(fileName, username, postList);
									break;
								}
								else if (choice == "3") //Delete Reply
								{
									deleteReply(fileName, username, postList);
									break;
								}
								else if (choice == "4" && username == owner) //Edit post
								{
									string newFileName=editPost(fileName, username, postList,topicContentList);

									break;
								}
								else if (choice == "5" && username == owner) //Delete post
								{
									int status=deletePost(fileName);
									fileName = " ";
									break;
								}
								else
								{
									cout << "Give a proper input" << endl;
								}
							}


						}
					}

				}
				else if (input == "2") // Topics you visited
				{
					//Put new things here
				}
				else if (input == "3") //Logout
				{
					string username = "";
					cout << "You have logged out. ";
				}
				else
				{
					cout << "Give a proper input" << endl;
				}
			}
			else //Not logged in
			{
				displayMenuNoLogin();
				cin >> input;
				cout << " " << endl;
				if (input == "0") //Exit
				{
					cout << "Goodbye!" << endl;
					break;
				}
				else if (input == "1") //View Topics
				{
					//alltopic = loadtopic();
					////cout << alltopic[0].getTopicText() << endl;
					//displaytopics(alltopic);
					displayTopics();

				}
				else if (input == "2")//Register
				{
					registeruser();
					cout << endl;
				}
				else if (input == "3") //Login
				{
					username = loginuser();
					cout << endl;
				}
				else
				{
					cout << "Give a proper input" << endl;
				}
			}
		}
		catch (exception)
		{
			cout << "Give a proper input" << endl;
		}
		
		
	}
}


