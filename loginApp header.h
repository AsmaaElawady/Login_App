#ifndef LOGINAPP_HEADER_H_INCLUDED
#define LOGINAPP_HEADER_H_INCLUDED
#include <sstream>
#include <map>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <regex>
#include<fstream>
#include<map>
#include <stdio.h>
#include <conio.h>

void threeChances();
void changePass();
string userpassword, loginencryptpass,username, userpass,loginUser, loginPass, encryptnewpass, searchennew;
  ;
void threeChances();
void usernameExist();
bool newPassExist = 0;
bool userFound = 0;
bool passfound = 0;
bool oldpassFound = 0;

map<char,string> passencrypt ;

#endif // LOGINAPP_HEADER_H_INCLUDED
