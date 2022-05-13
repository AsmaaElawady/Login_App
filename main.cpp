#include "loginApp header.h"

using namespace std;
bool emailFound = 0;
string email1;
void emailExist();
//----------------------
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
//dictionary to encrypt the password according to the affine cipher method


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
//function to check format phone number
bool is_phone_number1_valid(const string& phone_number)
{
   // define a regular expression
   const regex pattern( "^([0]([\\s-./\\\\])?)?(\\(?[0-9]\\d{1}\\)?|[1-9]\\d{2})([\\s-./\\\\])?([0-9]{3}([\\s-./\\\\])?[0-9]{4}|[a-zA-Z0-9]{7}|([0-9]{3}[-][a-zA-Z0-9]{4}))");

   // try to match the string with the regular expression
   return regex_match(phone_number, pattern);

}
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
{ string phone_number;
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
        cout<< "4- Exit"<< endl;
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
    //---------------------------
    cout<<"enter your phone_number:";
           cin>>phone_number;

           cout << phone_number << " : " << (is_phone_number1_valid(phone_number) ?"valid format" : "invalid format") << endl;

            valid(phone_number );

    //-----------------------------
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
    reg<<name<<' '<<phone_number<<' '<<username<<' '<<encrypedpass<<' '<<email1<<endl;


    //-------------------
    fileo.open(fname.c_str());
    fileo<<username<<endl<<phone_number<<endl<<name<<endl<<encrypedpass<<endl<<email1<<endl;
    cout<<"You are successfully registered"<<endl;

//---------change password part----------------
}if(choice == 3){
changePass();

}

if (choice == 4)
{
    exit=1;
}
}
cout<<"Thank you for visiting"<<endl;
}


//---------------------------------------------
