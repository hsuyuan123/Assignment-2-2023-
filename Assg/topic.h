#pragma once
#include <string>
using namespace std;

class Topic {
private:
	string topicname;
	string topictext;
public:
	Topic();
	Topic(string, string);
	void setTopicName(string);
	string getTopicName();
	void setTopicText(string);
	string getTopicText();

};