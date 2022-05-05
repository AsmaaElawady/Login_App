// FCI – Programming 1 – 2022 - Assignment 4
// Program Name: .cpp // Last Modification Date: xx/xx/xxxx
// Author1 and ID and Group: Salma ameer jalal, 20210505, A
// Author2 and ID and Group: Marwa Sameh Taha , 20210514, A
// Author3 and ID and Group:Asmaa Elawady Ibrahim,20210068,A
// Teaching Assistant: Nesma mohamed
//program purpose: No Purpose :)
#include <iostream>
#include <string>
#include <regex>
#include<fstream>

using namespace std;

string username;

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
//------------------------------
bool is_email_valid(const string& email)
{
   // define a regular expression
   const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

   // try to match the string with the regular expression
   return regex_match(email, pattern);
//-----------
        int count;
        string email1,e;
       // system("cls");
        cout<<"please enter the following details"<<endl;

        cout<<"email :";
        cin>>email1;

        ifstream input("test1.txt");
        while(input>>e)
        {
                if(e!=email1)

                {
                        count=1;
                        //system("cls");
                }
        }
        input.close();


        if(count!=1)
        {
                cout<<"accpted"<<endl;
                cin.get();

                int main();
        }
        else
        {
                cout<<"system refuse this email"<<endl;
               int main();
        }
}
//------------------------------------
int main()
{
    string email1 ;
    int choice,i,exit=0;
    string password,name,fname;
    ofstream fileo;
    ifstream filei;
    cout<<"Welcome to our system"<<endl;
    while(exit==0)
    {
        cout<<"Choose one option 1-Login/2-Register"<<endl;
        cin>>choice;

         if(choice==2)
        {
            cout<<"Enter your name:";
            cin.ignore();
            getline(cin,name);
            cout<<"Entera username:";
            cin>>username;

            valid(username);

            cout<<"Enter a password:";
            cin>>password;
            //fname="test1.txt";
            //cout<<fname;
            //-----------
             cout<<"enter your email:"<<endl;
           cin>>email1;

           cout << email1 << " : " << (is_email_valid(email1) ?"valid" : "invalid") << endl;

            valid(email1 );
            //------------
           // ofstream reg;
            ofstream reg("test1.txt",ios::app);
            reg<<name<<' '<<username<<' '<<password<<' '<<email1<<endl;


            //-------------------
            fileo.open(fname.c_str());
            fileo<<username<<endl<<name<<endl<<password<<email1<<endl;
            cout<<"You are successfully registered"<<endl;

        }
        else
        {
            exit=1;
        }
    }
    cout<<"Thank you for visiting"<<endl;
}




//-------------------



//int main();
// ofstream reg("database.txt",ios::app);
  //      reg<<reguser<<' '<<regpass<<endl;

