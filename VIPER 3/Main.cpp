/*************************
HEADER FILES
*************************/

#include<fstream>
#include<iostream>
#include<string.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>
#include<time.h>
#include<Windows.h>

using namespace std;


/**************************************************************
COMPATIBILITY ISSUES
****************************************************************/

#define clrbuf cin.get(buffer)    //to clear the input buffer
#define getch() _getch()
#define clrscr() system("cls")
#define delay _sleep

char buffer;  //this variable clears the buffer

/***********************************************************

SYMBOLIC CONSTANTS

defining some constants like size of password,username,account

*************************************************************************/


#define pwsize 30
#define acsize 30
#define unsize 30
#define sizerec 90

//the return and the backspace key

#define ret 13
#define backspace 8

//following constants are required for displaying the things as a table

#define START_SERIAL_AT 3
#define START_USERNAME_AT 10
#define START_ACCOUNT_AT 42


/******************************************
PROTOTYES OF FUNCTIONS
*****************************************/


void acceptpass(char *);
void do_passwords_match();

void enter();
void see();
void seeun();
void seeac();
void recmodify();
void delaccount();
void see_un_ac_as_table();
void change();
void seenumberofacc();



/*************************************************************

CLASS THAT HANDLES ALL THE DATA

*****************************************************************/

class user
{
  private:
	   char pw[pwsize];
	   char username[unsize];
	   char account[acsize];
	   void genrandompassword();
	   void storepassword();

  public:
	   user()
	   {
			strcpy(pw,"NULL");
			strcpy(username,"NULL");
			strcpy(account,"NULL");
	   }

	   user(char * p)
	   {
			strcpy(pw,p);
			strcpy(username,"NULL");
			strcpy(account,"NULL");
	   }

	   user(char *password, char * uname, char * aname)
	   {
			strcpy(pw,password);
			strcpy(username,uname);
			strcpy(account,aname);

	   }

	   void getdata()
	   {
			clrbuf;
			cout<<"\nEnter the name of the account:";
			cin.getline(account,acsize);
			clrbuf;
			cout<<"\nEnter the username of account:";
			cin.getline(username,unsize);
			cout<<"\n";
			cout<<"\nEnter the password:";
			storepassword();

			cout<<"\nRecord stored";

			return;
	   }

	   void putdata()
	   {
			cout<<"\n\n\nAccount:"<<account;
			cout<<"\nUsername:"<<username;
			cout<<"\nPassword:"<<pw;
			return;
	   }

	   char * getusername()
	   {
			return username;
	   }

	   char * getpassword()
	   {
			return pw;
	   }

	   char * getaccount()
	   {
			return account;
	   }

	   void modify()
	   {
		cout<<"\n\nYou can modify the username,account and password";

		char temp[acsize],temp1[unsize];
		char ch;
		cout<<"\nOld account name:"<<account;
		cout<<"\nPress y to retain and n to change:";
		cin>>ch;

		if(ch=='n')
		{
			clrbuf;
			cout<<"\nEnter the new account name:";
			cin.getline(temp,acsize);

			strcpy(account,temp);

			cout<<"\nAccount name changed\n";
		}

		cout<<"\nOld user name:"<<username;
		cout<<"\nPress y to retain and n to change:";
		cin>>ch;

		if(ch=='n')
		{
			clrbuf;
			cout<<"\nEnter the new username:";
			cin.getline(temp1,unsize);

			strcpy(username,temp1);

			cout<<"\nUsername changed\n";
		}


		cout<<"\nOld password:"<<pw;
		cout<<"\nPress y to retain and n to change:";
		cin>>ch;

		if(ch=='n')
		{
			storepassword();
		}

		cout<<"\nRecord modified";
		return;
	}

	   bool records_same(user o,user p)
	   {
		   if(strcmp(o.getaccount(),p.getaccount()) == 0)
			   if(strcmp(o.getusername(),p.getusername()) == 0)
				   if(strcmp(o.getpassword(),p.getpassword()) == 0)
					   return true;

		   return false;
	   }

}p;

/*the following function of the class generates random passwords of
10 charachters length. these passwords have lower and upper case charachters*/

void user::genrandompassword()
{
	time_t rt;
	time(&rt);
	srand(rt);

	int j;

	for(j=0;j<10;j++)
	{

		int r=rand() % 2+1;

		/*if rand is 1 then a uppercase charachter
		is generated, else a lowercase charachter is
		generated*/

		if(r==1)

			pw[j]=(char)((rand()%26) + 65);

		if(r==2)

			pw[j]=(char)(rand() % 26 + 97);
	}

	pw[j]='\0';

	return;   //the random password has been generated

}

/*this function asks the user if she wants to enter a password of her own
or she would like VIPER to select a password for her

if he/she asks VIPER to select a password, generate a password randomly
and store it in the variable that has been
passed as parameter */


void user::storepassword()
{
	cout<<"\nYou need to select a password\n";
	_sleep(1000);
	char ch;

	cout<<"\nPress y to enter your own password \nOr press n so VIPER can";
	cout<<" select a password for you(recommended):";
	cin>>ch;

	if(ch=='y')
	{
		clrbuf;
		cout<<"\nEnter your password:";
		acceptpass(pw);
		return;
	}

	if(ch=='n')
	{
		cout<<"\nGenerating a password for you";
		delay(2000);

		genrandompassword();
		clrscr();

		cout<<"\nFor security reasons,we will display your password";
		cout<<" 5 seconds only \nIt will be safely stored";
		cout<<" by VIPER";
		cout<<"\nPassword:"<<pw;

		delay(5000);
		clrscr();

		cout<<"\nPassword selected and stored";
		cout<<"\nPress a key";
		getch();
		clrscr();

		return;

	}
}


//end of class

//the main() function

char pass[pwsize];
char masterkey[pwsize];

int main()
{
	clrscr();
	char ch;

	/*the screen*/

	system("mode 90,60");

	cout<<"\n\n\n\nVisual Interface for Password Entry and Retrieval";

	cout<<"\n\nVIPER 3.0";

	cout<<"\n\nEquipped with an exclusive table view feature for usernames and account names";

	cout<<"\n\nAlso with bug fixes for the modify account and delete account function";

	cout<<"\n\n\n\nProgrammed by Siddharth Kannan";

	cout<<"\n\nThis is a free software which runs on any DOS shell";

	cout<<"\n\n\nLoading... Please wait...";

	cout<<"\n\nReleased on 8th March,2013";

	delay(5000);
	cout<<"\n\nPress a key to continue";
	getch();

	ifstream f;
	clrscr();

	f.open("p.dat");

	if(!f)
	{
		cout<<"\n\nSorry, we can not find the master key file";
		cout<<"\nWe can't grant entry without that file";

		cout<<"\n\nGo to \'vipersoftware.blogspot.com\' and download the file \'p.dat\' ";
		cout<<"\n\nThen copy it to the folder that you have the executable in so you can start using VIPER";
		getch();
		exit(0);
	}

	f.close();
	f.open("pw.dat");
	clrscr();

	if(!f)
	{		
		cout<<"\n\nThe main file does not exist";
		cout<<"\nCreate some records, so you can use VIPER to the fullest extent";
		getch();
	}

	f.close();


	//cout<<"\n\nPress a key to continue";
	/*clrbuf;*/


	/*the following lines take the master key from the p.dat file
	and store it in a variable for further use in the program*/

	
	f.open("p.dat");
	f.read((char*)&p,sizeof(user));
	strcpy(masterkey,p.getpassword());
	f.close();

	/*master key has been stored in the variable 'masterkey'*/

	clrscr();
	do_passwords_match();

	cout<<"\nACCESS GRANTED";
	getch();
	clrscr();

	cout<<"\nI am VIPER,your password manager";

	cout<<"\nTaking you to the main interface";
	cout<<"\nPress a key, please";
	getch();
	clrscr();
	int opt;

	while(1)
	{
		clrscr();
		cout<<"\n\t\t\tMENU";
		cout<<"\n\nPress 1 to enter a new account's details";
		cout<<"\n\nPress 2 to see the password of an account";
		cout<<"\n\nPress 3 to see usernames and accounts as a table";
		cout<<"\n\nPress 4 to modify the details of an account";
		cout<<"\n\nPress 5 to delete an account";
		cout<<"\n\nPress 6 to change the master key";
		cout<<"\n\nPress 7 to see the number of accounts stored";
		cout<<"\n\nPress 8 to exit";
		cout<<"\n\nEnter your choice:";
		cin>>opt;

		clrscr();

		switch(opt)
		{
		  case 1: enter();
			  break;

		  case 2: see();
			  break;

		  case 3: do_passwords_match();
			  clrscr();
			  see_un_ac_as_table();
				break;
			  
		  case 4: recmodify();
			  break;

		  case 5: delaccount();
			  break;

		  case 6: change();
			  break;

		  case 7: seenumberofacc();
			  break;

		  case 8: cout<<"\nThank you for using this program";
			  getch();
			  clrscr();
			  cout<<"\nTrust me, I am VIPER";
			  getch();
			  return 0;

		  default:
			  cout<<"\nWrong input";
			  cout<<"\nTaking you back to the menu";
			  getch();
			  continue;
		}

	}
 /*
	cout<<"\nThank you for using this program";
	getch();
	clrscr();
	cout<<"\nTrust me, I am VIPER";*/
	delaccount();
	getch();
	return 0;

}

//end of main()


/*the following function serves to keep the password hidden so that the
user alone knows what he/she is entering*/

void acceptpass(char * pw)
{

		char ch;

		int i;
		for(i=0;i<pwsize;i++)
		{
			 ch=getch();

			 if(ch == ret)  //13 is the ascii code of return key
			 break;

			 //if(ch == backspace)
			 //{
				// pw[i] = NULL;
				// pw[i-1] = NULL;
				// i-=2;
				// cout<<"\b ";
				// continue;
			 //}

			 pw[i]=ch;

			 cout<<"*";
		}

		pw[i]='\0';

		/*the last line is required as without the '\0'
		charachter other functions (such as cout) will not know till
		where they need to print the string   */

		return;
}

void do_passwords_match()
{
	cout<<"\nEnter the master key to proceed:";
	acceptpass(pass);

	if(strcmp(pass,masterkey)!=0)
	{
		clrscr();
		cout<<"\nSorry, We are unable to proceed with your request";
		delay(1000);
		cout<<"\nVIPER has detected unauthorized access";
		delay(1000);
		cout<<"\nTerminating and returning to OS";
		cout<<"\nPress a key";
		getch();
		exit(0);
	}

	cout<<"\nPassword accepted, Continuing with processing\n";

	return;

}


//functions used in main()

void enter()
{
	do_passwords_match();

	p.getdata();

	ofstream f;
	f.open("pw.dat",ios::app);
	f.write((char*)&p,sizeof(user));
	long pos=f.tellp();
	f.close();


	cout<<"\nThe new record was written to the file by VIPER";
	cout<<"\n"<<pos/sizerec<<" records are there in the file";
	cout<<"\nNow we will take you back to the main interface";
	cout<<"\nPress a key";
	getch();
	clrscr();
	return;
}

void see()
{
	char ch;
	clrbuf;

	do_passwords_match();

	cout<<"\n\nVIPER will now present a list of all the usernames and accounts stored. \nPlease select the serial number of the account that you want to modify";
	delay(2000);

	see_un_ac_as_table();
	int n=0;

	cout<<"\n\nEnter the number of the record which you want to modify:";
	cin>>n;

	ifstream f;
	f.open("pw.dat");

	if(!f)
	{
		cout<<"\nFile does not exist or has been corrupted";
		getch();
		return;
	}

	f.seekg(0,ios::beg);
	f.seekg((n-1) * sizeof(user),ios::beg);

	f.read((char*)&p,sizeof(user));

	p.putdata();

	getch();

	return;
}

//functions used inside see()

//void seeun()
//{
//	clrbuf;
//	char un[unsize];
//	cout<<"\nEnter the username of the account:";
//	cin.getline(un,unsize);
//
//	ifstream f;
//
//	f.open("pw.dat");
//
//	f.seekg(0,ios::beg);
//	int flag=0;
//
//	while(f.read((char*)&p,sizeof(user)))
//	{
//		if(strcmp(p.getusername(),un)==0)
//		{
//			p.putdata();
//			flag=1;
//		}
//	}
//
//	f.close();
//
//	if(flag==0)
//
//	cout<<"\nNo match found";
//	getch();
//
//	return;
//}
//
//void seeac()
//{
//	clrbuf;
//	char ac[acsize];
//	cout<<"\nEnter the name of the account:";
//	cin.getline(ac,acsize);
//
//	ifstream f;
//
//	f.open("pw.dat");
//
//	f.seekg(0,ios::beg);
//	int flag=0;
//
//	while(f.read((char*)&p,sizeof(user)))
//	{
//		if(strcmp(p.getaccount(),ac)==0)
//		{
//			p.putdata();
//			flag=1;
//		}
//	}
//
//	f.close();
//
//	if(flag==0)
//
//	cout<<"\nNo match found";
//	getch();
//
//	return;
//}

//end of functions used inside see()

//void seeusernames()
//{
//	clrscr();
//	cout<<"\nVIPER will now show you all the usernames stored";
//	delay(3000);
//	clrscr();
//
//	ifstream f;
//	f.open("pw.dat");
//
//	if(!f)
//	{
//		cout<<"\nFile could not be opened";
//		getch();
//		return;
//	}
//
//	f.seekg(0,ios::beg);
//	int i=1;
//
//	while(f.read((char*) &p,sizeof(user)))
//	{
//		cout<<"\n\n"<<i<<". "<<p.getusername();
//		i++;
//
//		if(i%9==0)
//		{
//		    cout<<"\n\nPlease press a key";
//			getch();
//			clrscr();
//			i;
//		}
//	}
//
//	cout<<"\n\nEnd of file";
//	getch();
//
//	return;
//}
//
//void seeaccountnames()
//{
//	clrscr();
//	cout<<"\nVIPER will now show you all the account names stored";
//	delay(3000);
//	clrscr();
//
//	ifstream f;
//	f.open("pw.dat");
//
//	if(!f)
//	{
//		cout<<"\nFile could not be opened";
//		getch();
//		return;
//	}
//
//	f.seekg(0,ios::beg);
//	int i=1;
//
//	while(f.read((char*) &p,sizeof(user)))
//	{
//		cout<<"\n\n"<<i<<". "<<p.getaccount();
//		i++;
//
//		if(i%9==0)
//		{
//		//the screen will be cleared for better viewing of data
//	    cout<<"\n\nPlease press a key";
//			getch();
//			clrscr();
//		}
//	}
//
//	cout<<"\n\nEnd of file";
//	getch();
//
//	return;
//}


void see_un_ac_as_table()
{	
	ifstream f;
	f.open("pw.dat");

	if(!f)
	{
		cout<<"\n\nThe file does not exist or has been corrupted";
		getch();
		return;
	}

	cout<<"\n\nVIPER will now present a table of usernames and accounts together";
	cout<<"\nPress a key to continue";
	getch();

	system("mode 90,60");
	

	COORD origin = {0,0},serial = {START_SERIAL_AT-2,1},username ={START_USERNAME_AT,1},account = {START_ACCOUNT_AT,1};

	int i=1;

	cout<<"\n\n\nInitiating table display, with coordinate variables....";
	delay(1200);
	clrscr();

	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(hOutput,serial);

	cout<<"SERIAL";

	SetConsoleCursorPosition(hOutput,username);

	cout<<"USERNAME";

	SetConsoleCursorPosition(hOutput,account);

	cout<<"ACCOUNT NAME";

	f.seekg(0,ios::beg);

	serial.X = START_SERIAL_AT;
	serial.Y =2 + i;
	username.X = START_USERNAME_AT;
	username.Y = 2 + i;
	account.X = START_ACCOUNT_AT;
	account.Y = 2 + i;

	int j = 1;
	
	while(f.read((char*)&p,sizeof(user)))
	{
		SetConsoleCursorPosition(hOutput,serial);

		cout<<i<<".";

		SetConsoleCursorPosition(hOutput,username);

		cout<<p.getusername();

		SetConsoleCursorPosition(hOutput,account);

		cout<<p.getaccount();

		++i;
		j+=2;

		if(i % 21 == 0)
		{
			cout<<"\n\nPress a key so we can show you the further records";
			getch();
			j = 1;
			clrscr();

			//printing the headers again

			serial.X = START_SERIAL_AT-2;
			serial.Y = 1;
			username.X = START_USERNAME_AT;
			username.Y = 1;
			account.X = START_ACCOUNT_AT;
			account.Y = 1;

			SetConsoleCursorPosition(hOutput,serial);

			cout<<"SERIAL";

			SetConsoleCursorPosition(hOutput,username);

			cout<<"USERNAME";

			SetConsoleCursorPosition(hOutput,account);

			cout<<"ACCOUNT NAME";
		}

		serial.X = START_SERIAL_AT;
		serial.Y =2 + j;
		username.X = START_USERNAME_AT;
		username.Y = 2 + j;
		account.X = START_ACCOUNT_AT;
		account.Y = 2 + j;

	}

	cout<<"\n\nEnd of file\n\n";
	getch();
	f.close();
	return;

}


void recmodify()
{
	cout<<"\nYou have chosen to modify the details of an account\n";

	do_passwords_match();

	cout<<"\n\nVIPER will now present a list of all the usernames and accounts stored. \nPlease select the serial number of the account that you want to modify";
	delay(2000);

	see_un_ac_as_table();
	int n=0;

	cout<<"\n\nEnter the number of the record which you want to modify:";
	cin>>n;

	ifstream f;
	f.open("pw.dat");

	if(!f)
	{
		cout<<"\nFile does not exist or has been corrupted";
		getch();
		return;
	}

	f.seekg(0,ios::beg);
	f.seekg((n-1) * sizeof(user),ios::beg);

	f.read((char*)&p,sizeof(user));

	user o = p;
	user r = p;

	/*cout<<"\n p contains \n";
	p.putdata();*/
	
	o.modify();

	/*cout<<"\nModified record contains\n";
	o.putdata();*/

	ofstream g;
	
	g.open("temp.dat");
	user q = p;
	f.seekg(0,ios::beg);
	g.seekp(0,ios::beg);

	while(f.read((char *)&p,sizeof(user)))
	{
		if(q.records_same(r,p))
		{
			/*cout<<"\n\nThe match was found.";
			p.putdata();

			cout<<"\n\nThis record will not be writtten";
			getch();*/
			continue;
		}

		/*p.putdata();
		cout<<"\n\nThis record will be written";
		getch();*/
		g.write((char*)&p,sizeof(user));

	}

	f.close();	
	g.write((char*)&o,sizeof(user));
	g.close();

	cout<<"\n\nThe record has been modified and written to file.";

	remove("pw.dat");

	rename("temp.dat","pw.dat");

	getch();
	return;
	
}

void delaccount()
{
	clrscr();
	cout<<"\nYou have chosen to delete an account\n";

	do_passwords_match();

	cout<<"\n\nVIPER will now present a list of all the usernames and accounts stored. \nPlease select the serial number of the account that you want to delete";
	delay(2000);

	see_un_ac_as_table();
	int n=0;

	cout<<"\n\nEnter the number of the record which you want to delete:";
	cin>>n;

	ifstream f;
	f.open("pw.dat");

	if(!f)
	{
		cout<<"\nFile does not exist or has been corrupted";
		getch();
		return;
	}
	

	user o;
	int flag = 0;

	f.seekg( (n-1) * sizeof(user),ios::beg);
	f.read((char*)&o,sizeof(user));

	o.putdata();

	cout<<"\n\nThis is the account that you have selected for deletion";

	cout<<"\nOnce deleted we will not be able to recover it back";

	char ch;
	cout<<"\n\nAre you sure that you want to delete this record?(y/n):";
	cin>>ch;

	if(ch == 'n')
	{
		cout<<"\nYour request has been discarded";
		cout<<"\nNo account has been deleted";
		getch();
		return;
	}

	cout<<"\nThis record will now be deleted";
	
	ofstream g;
	g.open("temp.dat");
	g.seekp(0,ios::beg);
	f.seekg(0,ios::beg);
	user q;

	while(f.read((char*)&p,sizeof(user)))
	{
		if(q.records_same(o,p))
		{
			continue;
		}

		g.write((char*)&p,sizeof(user));

	}

	g.close();
	f.close();

	remove("pw.dat");
	rename("temp.dat","pw.dat");

	getch();
	return;
}

void change()
{
	clrscr();

	do_passwords_match();

	cout<<"Enter the new master key:";
	acceptpass(pass);

	user temp(pass);

	remove("p.dat");

	ofstream f;
	f.open("p.dat");

	f.write((char*)&temp,sizeof(user));

	f.close();

	cout<<"\nPassword changed";
	cout<<"\nPress a key";
	getch();
	clrscr();

	//thought the file has been modifed, the password is unchanged
	//in the varibale here. so we must change that too.

	ifstream g;
	g.open("p.dat");
	g.read((char*)&p,sizeof(user));
	strcpy(masterkey,p.getpassword());
	g.close();

	return;
}

void seenumberofacc()
{
	ifstream f;

	f.open("pw.dat");

	f.seekg(0,ios::end);

	long pos=f.tellg();

	int x=pos/sizeof(user);

	cout<<"\n"<<x<<" accounts are presently stored";

	getch();
	return;
}
