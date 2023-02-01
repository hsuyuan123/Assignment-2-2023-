#pragma once
#include <string>
using namespace std;

class Topic {
private:
	string topicname;
	string topictext;
	int topicid;
public:
	Topic();
	Topic(int,string, string);
	void setTopicName(string);
	string getTopicName();
	void setTopicText(string);
	string getTopicText();
	void setTopicId(int);
	int getTopicId();
	//create post class
};