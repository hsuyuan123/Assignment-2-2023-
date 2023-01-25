#pragma once
#include <string>
using namespace std; 

class User {
private:
	string username;
	string password;
public:
	User();
	User(string, string);
	void setUsername(string);
	string getUsername();
	void setPassword(string);
	string getPassword();

};