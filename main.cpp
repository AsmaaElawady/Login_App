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

string username;
//dictionary to encrypt the password
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
//-----------------------6th function--------------------------------
// this function will be before entering the password
void   passMessage6(){
    string message ;

    message= "password should contains small and capital letters,symbols and numbers\n"
             ""
             "";
    cout <<"password should contains small and capital letters,symbols and numbers\n";


}
//------------------------------------------------------------

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
        cout<<"Choose one option 1-Login/2-Register:"<<endl;
        cin>>choice;

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
            reg<<name<<' '<<username<<' '<<encrypedpass<<' '<<email1<<endl;


            //-------------------
            fileo.open(fname.c_str());
            fileo<<username<<endl<<name<<endl<<encrypedpass<<email1<<endl;
            cout<<"You are successfully registered"<<endl;


        }else
        {
            exit=1;
        }
    }
    cout<<"Thank you for visiting"<<endl;
}




//-------------------
