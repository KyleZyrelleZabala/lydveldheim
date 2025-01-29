#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <iomanip>
using namespace std;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
enum Colors {blk, dblu, dgrn, dcyn, dred, dmag, dyel, lgry, dgry, lblu, lgrn, lcyn, lred, lmag, lyel, wht};
const char* file = "APPLICATION FORM TECH 2019-2020.csv";
char ch;
fstream fs;
string C = ",";

string date;
int num=0;
string name1;
string name2;
string midd;

int ntmp;

void valid();
void txt(int,int,int,string,bool);
void bar(int,int,int,string,bool);

void write();
void start();
void atNum();
void number();
void lname();
void fname();
void middle();
void program();
void more();

void valid() {
	cin.clear();
	cin.ignore();
	txt(lred,blk,800,"\n\tInvalid Input!!!",1);
	txt(lred,blk,1000,"\tTry again...",1);
}
void txt(int f, int b, int d, string s, bool n) {
	int color=(f+(b*16));
	SetConsoleTextAttribute(h,color);
	cout<<s;
	Sleep(d);
	SetConsoleTextAttribute(h,7);
	if(n==TRUE) cout<<endl;
}
void bar(int f, int b, int l, string s, bool n) {
	for (int i=0; i<=l; i++) txt(f,b,0,s,0);
	if(n==TRUE) cout<<endl;
}

main() {
	system("pause");
	start();
	number();
	program();
}

void start() {
	system("cls");
	txt(lgrn,dblu,0,"\nAcademic Year Start: ",1);
	cout<<"\t[1] 2018\n\t[2] 2019\n\t[3] 2020\n";
	ch=_getch();
	if(ch=='1') date = "2018-";
	else if(ch=='2') date = "2019-";
	else if(ch=='3') date = "2020-";
	else {
		valid();
		start();
	}
}
void number() {
	cin.clear();
	txt(lgrn,dblu,0,"\nStart Encoding at:\t",0);
	cin>>ntmp;
	if(cin.fail()) {
		valid();
		number();
	}
	else num=ntmp;
	cin.ignore();
}
void lname() {
	txt(lgrn,dblu,0,"\n\tLast Name:\t",0);
	getline(cin,name1);
}
void fname() {
	txt(lgrn,dblu,0,"\n\tFirst Name:\t",0);
	getline(cin,name2);
}
void middle() {
	txt(lgrn,dblu,0,"\n\tMiddle Initial:\t",0);
	getline(cin,midd);
}

void write() {
	system("cls");
	txt(lmag,0,0,"\n\tNUMBER:\t\t",0); cout<<date<<num<<endl;
	txt(lmag,0,0,"\tLAST NAME:\t",0); cout<<name1<<endl;
	txt(lmag,0,0,"\tFIRST NAME:\t",0); cout<<name2<<endl;
	txt(lmag,0,0,"\tMIDDLE INITIAL:\t",0); cout<<midd<<endl;
	cout<<"\n\nAre you sure about this entry?\n";
	cout<<"Press"; txt(lgrn,0,0," Enter ",0); cout<<"if YES\n";
	cout<<"Press"; txt(lred,0,0," 1 ",0); cout<<"if "; txt(lmag,0,0,"LAST NAME",0); cout<<" is incorrect\n";
	cout<<"Press"; txt(lred,0,0," 2 ",0); cout<<"if "; txt(lmag,0,0,"FIRST NAME",0); cout<<" is incorrect\n";
	cout<<"Press"; txt(lred,0,0," 3 ",0); cout<<"if "; txt(lmag,0,0,"MIDDLE INITIAL",0); cout<<" is incorrect\n";
	ch=_getch();
	if(ch==13) {
		fs.open(file,ios::app);
		fs<<date<<num<<C<<name1<<C<<name2<<C<<midd<<"\n";
		fs.close();
		txt(lgrn,0,0,"\nNew Entry Successfully Added!!!\n",1);
		num++;
	} else {
		if(ch=='1') lname();
		else if(ch=='2') fname();
		else if(ch=='3') middle();
		write();
	}
}
void more() {
	txt(lgrn,0,0,"\nWould you like to add more?",1);
	cout<<"Press"; txt(lgrn,0,0," Enter ",0); cout<<"if YES\n";
	cout<<"Press"; txt(lred,0,0," Space ",0); cout<<"if NO\n";
	ch=_getch();
	if(ch==13) program();
	else if(ch==' ') exit(1);
	else {
		valid();
		more();
	}
}
void program() {
	system("cls");
	txt(lgrn,dblu,0,"\n\tCurrent Number:\t",0); cout<<date<<num<<endl;
	lname();
	fname();
	middle();
	write();
	more();
}
