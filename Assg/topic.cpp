#include "topic.h"

Topic::Topic() {}
Topic::Topic(int i,string n, string t) { topicid = i;topicname = n; topictext = t;  }
void Topic::setTopicName(string n) { topicname = n; }
string Topic::getTopicName() { return topicname; }
void Topic::setTopicText(string t) { topictext = t; };
string Topic::getTopicText() { return topictext; }
void Topic::setTopicId(int i) { topicid = i; }
int Topic::getTopicId() { return topicid; };