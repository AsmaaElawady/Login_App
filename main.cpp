#include <sstream>
#include <map>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <regex>
#include<fstream>
#include<map>

using namespace std;
bool emailFound = 0;
string email1;
void emailExist();
//----------------------
void threeChances();
void changePass();
string userpassword, loginencryptpass,username, userpass,loginUser, loginPass  ;
void threeChances();
void usernameExist();
bool newPassExist = 0;
bool userFound = 0;
bool passfound = 0;
bool oldpassFound = 0;
//dictionary to encrypt the password according to the affine cipher method
map<char,string> passencrypt =
{


        {'a',"z"},{'b',"y"},{'c',"x"},{'d',"w"},{'e',"v"},
        {'f',"u"},{'g',"t"},{'h',"s"},{'i',"r"},{'j',"q"},
        {'k',"p"},{'l',"o"},{'m',"n"},{'n',"m"},{'o',"l"},
        {'p',"k"},{'q',"j"},{'r',"i"},{'s',"h"},{'t',"g"},
        {'u',"f"},{'v',"e"},{'w',"d"},{'x',"c"},{'y',"b"},
        {'z',"a"},
        {'A',"Z"},{'B',"Y"},{'C',"X"},{'D',"W"},{'E',"V"},
        {'F',"U"},{'G',"T"},{'H',"S"},{'I',"R"},{'J',"Q"},
        {'K',"P"},{'L',"O"},{'M',"N"},{'N',"M"},{'O',"L"},
        {'P',"K"},{'Q',"J"},{'R',"I"},{'S',"H"},{'T',"G"},
        {'U',"F"},{'v',"E"},{'W',"D"},{'X',"C"},{'Y',"B"},
        {'Z',"A"},
        {'0',"9"},{'1',"8"},{'2',"7"},{'3',"6"},{'4',"5"},
        {'5',"4"},{'6',"3"},{'7',"2"},{'8',"1"},{'9',"0"},

        {'!',"|"},{'@',"`"},{'#',"~"},{'$',"."},{'%',"+"},
        {'^',"="},{'&',"/"},{'*',"?"},{'|',"!"},{'`',"@"},
        {'.',"$"},{'+',"%"},{'=',"^"},{'/',"&"},{'?',"*"},
        {'(',","},{'~',"#"},{',',")"}

};

void valid(string str)
{
    string dir;
    ifstream file;
    dir = str+"test1.txt";
    file.open(dir.c_str());
    if(!file.is_open() && file.fail())
    {
        //file.close();
        return;
    }

}
//-----------------------------
//this  function to check if the password strong or not
bool isPasswordstrong(string password){
    regex passwordformat("(?=.*[a-z)(?=.*[A-Z])(?=.*\\d)(?=.*[&*%$@!?])[A-Za-z\\d&*%$@!?]{8,}");
    return regex_match(password,passwordformat);


}
//------------------------------
//------------------------------
//function to check format email
bool is_email_valid(const string& email)
{
    // define a regular expression
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    // try to match the string with the regular expression

    return regex_match(email, pattern);
}
//-----------------------------------------------
//-----------------------6th function--------------------------------
// this function will be before entering the password
void   passMessage6(){
    string message ;

    message= "password should contains small and capital letters,symbols and numbers\n"
             ""
             "";
    cout <<"password should contains small and capital letters,symbols and numbers\n";


}
//---------------7th function---------------------------------------------
void insurepassword7(string& password){
    string insurePassword;
    cout<< "Enter the password again: ";
    cin >> insurePassword;

    while(password != insurePassword ){
        cout << "please make sure that they are the same:";
        cin >> insurePassword;
    }

}

//------------------------------------------------------------
int main()
{
    string encrypedpass;
    string email1 ;
    int choice,i,exit=0;
    string password,name,fname;
    ofstream fileo;
    ifstream filei;
    cout<<"Welcome to our system"<<endl;
    while(exit==0)
    {
        cout<<"Choose one option:"<<endl;
        cout<<" 1-Login "<<endl;
        cout<<" 2-Register"<<endl;
        cout<<" 3-change password"<<endl;
        cin>>choice;
//-----login part-----------
if(choice==1){
threeChances();
// cout <<userpassword;
break;

}
//-----------register part--------------
 if(choice==2)
{
    cout<<"Enter your name:";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter username:";
    cin>>username;

    valid(username);

    cout<<"Enter a password:";
    cin>>password;
    for(char letter: password){
        encrypedpass += passencrypt[letter];
    }
    //-----------//function to check whether the email exists or not//--------------------------------------------------------------------------------------
    cout << "please enter your user email:  ";
    cin >> email1;

    cout << email1 << " : " << (is_email_valid(email1) ? "valid format" : "invalid format") << endl;
    valid(email1);
    ifstream file;
    file.open("test1.txt");
    string line, line2;
    int offset, offset2;
    while (!file.eof()) {
        getline(file, line);
        if ((offset = line.find(email1, 0)) != string::npos) {
            emailFound = 1;
        }
    }
    if (emailFound) {
        cout << "failed , please try again   " << endl;
    }
    else {

        cout << "accepted" << endl;
        emailFound = 0;

        file.close();

    }
    //---------------------------------------------------------------------------------------------------------------------------------------------------------
    ofstream reg("test1.txt",ios::app);
    reg<<name<<' '<<username<<' '<<encrypedpass<<' '<<email1<<endl;


    //-------------------
    fileo.open(fname.c_str());
    fileo<<username<<endl<<name<<endl<<encrypedpass<<endl<<email1<<endl;
    cout<<"You are successfully registered"<<endl;

//---------change password part----------------
}if(choice == 3){
changePass();

}

else
{
    exit=1;
}
}
cout<<"Thank you for visiting"<<endl;
}


//---------------------------------------------
// function 12 without the getch()
//function for the login to check whether the user name and password exists or not
void usernameExist(){
// the below piece of code is to check the user name existence
cout << "please enter your user name:  ";
cin>> loginUser;
ifstream file;
file.open("test1.txt");
string line, line2;
int offset, offset2;
while (!file.eof()){
getline(file, line);
if((offset = line.find(loginUser,0)) != string::npos){
    userFound = 1;
}
    }
file.close();
ifstream file2;
file2.open("test1.txt");

// the below piece of code is to take the password and change it to *
cout<<"please enter your password:  ";
cin >> userpassword;
      /*  for(int i = 0; i<sizeof(userpass); i++){
            userpass[i]= getch();
            cout<<"*";
            userpassword +=  userpass[i];
        if(userpass[i]==' '){

            break;
        }
                   // userpassword +=  userpass[i];

        }
        userpass[i] = '\0';
        cout<<"\n";*/
// the below part is to check the password existence in the file
for(char letter: userpassword){
                loginencryptpass += passencrypt[letter];}

//cout<< loginencryptpass;
while (!file2.eof()){
getline(file2, line2);
if((offset2 = line2.find(loginencryptpass,0)) != string::npos){
    passfound = 1;

}}
file2.close();

       }
// function 13 ,14
//--------------------------------------------------
void threeChances(){

usernameExist();
if(passfound && userFound){
    cout<< "logged in successfully"<<endl;
}
else{

    cout<< "failed to login, please try again"<< endl;
userFound = 0;
passfound = 0;
loginencryptpass = "";
    usernameExist();

    if(passfound && userFound){
        cout<< "logged in successfully"<<endl;}
        else{
            cout <<"failed to login, please try again"<<endl;
            userFound=0;
            passfound =0;
            loginencryptpass = "";
            usernameExist();
            if(userFound && passfound){
                cout<<"logged in successfully"<< endl;

            }
            else{cout<< "denied access"<<endl;}
        }
    }




}

// the below function is to change the password for the user
void changePass(){
    threeChances();
        string oldpass, encryptoldpass;
        cout<<"please enter your old password: "<< endl;
        cin>> oldpass;
        for(char letter: oldpass){
                encryptoldpass += passencrypt[letter];
            }

ifstream file3;
string line3;
int offset3;
file3.open("test1.txt");
// the below part is to check the old password existence in the file
while (!file3.eof()){
getline(file3, line3);
if((offset3 = line3.find(encryptoldpass,0)) != string::npos){
    oldpassFound = 1;

file3.close();
}}
if(oldpassFound){
    string newpass1, newpass2;
cout<<"please enter the new desired password: "<< endl;// taking the new password
cin >> newpass1;
cout<< "please reenter the new password"<< endl;
cin>> newpass2;
if(newpass1 != newpass2){
    cout<< "password doesn't match" << endl;// making sure the password matches
}
else if (newpass1 == newpass2){
// searching for the new password in the file
ifstream file4;
int offset4;
string line4;
file4.open("test1.txt");
while (!file4.eof()){
getline(file4, line4);
if((offset4 = line4.find(newpass1,0)) != string::npos){
newPassExist = 1;

}


}// if the word is in the file this mean it is already used which is not accepted
if(newPassExist){
     cout<<"this password is already used"<< endl;
    cout<<"please try another password";
}
// the word is not in the file so we add the new word to the file
else{

}


}
}
else{cout<< "this password is incorrect"<< endl; }
//here to enter the new pass

}
//-----------------------------------

