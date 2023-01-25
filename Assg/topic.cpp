#include "topic.h"

Topic::Topic() {}
Topic::Topic(string n, string t) { topicname = n; topictext = t; }
void Topic::setTopicName(string n) { topicname = n; }
string Topic::getTopicName() { return topicname; }
void Topic::setTopicText(string t) { topictext = t; };
string Topic::getTopicText() { return topictext; }