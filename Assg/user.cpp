#include "user.h"

User::User() {}
User::User(string u, string p) { username = u; password = p; }
void User::setUsername(string u) { username = u; }
string User::getUsername() { return username; }
void User::setPassword(string p) { password = p; };
string User::getPassword() { return password; }

