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
HANDLE hand=GetStdHandle(STD_OUTPUT_HANDLE);
enum Colors {blk, dblu, dgrn, dcyn, dred, dmag, dyel, lgry, dgry, lblu, lgrn, lcyn, lred, lmag, lyel, wht};
enum Letters {X, A, B, C, D, E, N};
enum Data {tt, va, sp, na, ar, gender, course, school, prov, frsh, stat};
string t[] = {"","VERBAL ABILITY","SCIENCE PROFICIENCY","NUMERICAL ABILITY","ABSTRACT REASONING"};
const char* file[] = {"Highlighted.csv","CAT Analysis 1 Verbal Ability Summary.csv","CAT Analysis 2 Science Proficiency Summary.csv","CAT Analysis 3 Numerical Ability Summary.csv","CAT Analysis 4 Abstract Reasoning Summary.csv","Table.csv","Answer key.txt"};
int tab[80][23], ntmp, part[6]={};
int anskey[80]={};
char ch;
const char* u[] = {"\xC9","\xBB","\xC8","\xBC","\xBA","\xCD","\xB3","\xCC","\xB9","\xC7","\xC4","\xB6"};
fstream fs;
FILE *fp;
string stmp;

struct Student {
	string ln,fn,mi,re;
	int ans[80], data[11];
}*xmn;

void valid();
void txt(int,int,int,string,bool);
void bar(int,int,int,string,bool);
void chooser();
void key();

void valid() {
	cin.clear();
	cin.ignore();
	txt(lred,blk,1000,"\n\tInvalid Input!!!",1);
	txt(lred,blk,1200,"\tTry again...",1);
}
void txt(int f, int b, int d, string s, bool n) {
	int color=(f+(b*16));
	SetConsoleTextAttribute(hand,color);
	cout<<s;
	Sleep(d);
	SetConsoleTextAttribute(hand,7);
	if(n==TRUE) cout<<endl;
}
void bar(int f, int b, int l, string s, bool n) {
	for (int i=0; i<=l; i++) txt(f,b,0,s,0);
	if(n==TRUE) cout<<endl;
}
void key() {
	fp=fopen(file[6],"r");
	if(fp) {
		fclose(fp);
		fs.open(file[6],ios::in);
		int item=-1;
		while(!fs.eof()) {
			item++;
			getline(fs,stmp,'\n');
			if(stmp=="A") anskey[item]=A;
			else if(stmp=="B") anskey[item]=B;
			else if(stmp=="C") anskey[item]=C;
			else if(stmp=="D") anskey[item]=D;
			else if(stmp=="E") anskey[item]=E;
			else anskey[item]=N;
		}
		fs.close();
	}
	if(!fp) {
		txt(lred,blk,1000,"\tThe Answer Key does not exist!!!",1);
		txt(lred,blk,1200,"\tPlease create one now.",1);
		exit(1);
	}
}

class Header {
	public:
		void rec(bool,int);
		void ana(int,int,int);
}h;
class Answer {
	public:
		void get(int);
		void choice(int);
		void change();
		void num();
		void another();
		void show(int,int);
};
class Record {
	public:
		void show();
		string detail(int,int);
		void get(int);
		void write();
		void formal();
		Answer ans;
}r;
class Analyst {
	public:
		void update();
		int compare(int,int);
		void read();
		void write();
		void formal();
		void show();
}a;

main() {
	fp=fopen(file[0],"r");
	if(!fp) {
		fs.open(file[0],ios::out);
		fs<<"Last Name,First Name,M.I.,Gender,VA,SP,NA,AR,TOTAL,Preferred Course,School Type,Residence Area,Enrollment Status\n";
		fs.close();
	}
	if(fp) fclose(fp);
	fp=fopen(file[5],"r");
	if(!fp) {
		a.write();
		fs.close();
	}
	if(fp) fclose(fp);
	cout<<"\nGo "; txt(lgrn,0,0,"Fullscreen",0);
	cout<<" then type "; txt(lmag,0,0,"quit",0); cout<<" before continuing...\n\n";
	key();
	system("wmic");
	a.read();
	a.show();
	system("pause");
	xmn=new Student;
	xmn->data[tt]=0;
	for(int i=-1; i<10; i++) r.get(i);
	return 0;
}

void Header::ana(int l,int x,int r) {
	txt(15,0,0,u[4],0); bar(0,0,l," ",0); txt(lcyn,0,0,t[x],0); bar(0,0,r," ",0); txt(15,0,0,u[4],1); txt(15,0,0,u[7],0); 
	txt(15,0,0,"\xCD\xCD\xCD\xCB",0); bar(15,0,6,u[5],0);
	txt(15,0,0,"\xCB",0); bar(15,0,24,u[5],0); txt(15,0,0,"\xCB",0); bar(15,0,18,u[5],0);
	txt(15,0,0,"\xCB",0); bar(15,0,22,u[5],0); txt(15,0,0,"\xCB",0); bar(15,0,19,u[5],0);
	txt(15,0,0,"\xCB",0); bar(15,0,12,u[5],0); txt(15,0,0,"\xCB",0); bar(15,0,17,u[5],0);
	txt(15,0,0,"\xCB",0); bar(15,0,4,u[5],0);
	txt(15,0,0,u[8],1); txt(15,0,0,u[4],0);
	txt(lmag,0,0," ##",0); txt(15,0,0,u[4],0);
	txt(lmag,0,0,"Correct",0); txt(15,0,0,u[4],0);
	txt(lmag,0,0,"A   B   C   D   E   N/A  ",0); txt(15,0,0,u[4],0);
	txt(lmag,0,0,"Province NCR  N/A  ",0); txt(15,0,0,u[4],0);
	txt(lmag,0,0,"Freshman Transfer N/A  ",0); txt(15,0,0,u[4],0);
	txt(lmag,0,0,"Public Private N/A  ",0); txt(15,0,0,u[4],0);
	txt(lmag,0,0,"M   F   N/A  ",0); txt(15,0,0,u[4],0);
	txt(lmag,0,0,"Eng'g  I.T.  N/A  ",0); txt(15,0,0,u[4],0);
	txt(lmag,0,0,"Total",0); txt(15,0,0,u[4],1);
	txt(15,0,0,u[9],0); bar(15,0,2,u[10],0);
	txt(15,0,0,"\xD7",0); bar(15,0,6,u[10],0);
	txt(15,0,0,"\xD7",0); bar(15,0,24,u[10],0); txt(15,0,0,"\xD7",0); bar(15,0,18,u[10],0);
	txt(15,0,0,"\xD7",0); bar(15,0,22,u[10],0); txt(15,0,0,"\xD7",0); bar(15,0,19,u[10],0);
	txt(15,0,0,"\xD7",0); bar(15,0,12,u[10],0); txt(15,0,0,"\xD7",0); bar(15,0,17,u[10],0);
	txt(15,0,0,"\xD7",0); bar(15,0,4,u[10],0);
	txt(15,0,0,u[11],1);
}
void Header::rec(bool n,int i) {
	if(n==1) system("cls");
	bar(lcyn,blk,50,u[5],1);
	if(i==1) txt(lgrn,0,0,xmn->fn+" "+xmn->mi+" "+xmn->ln,1);
	if(i==1) txt(lcyn,0,0,"ANSWER SHEET ",1);
	if(i==2) txt(lcyn,0,0,"EXAMINEE DETAILS ",1);
	bar(lcyn,blk,50,u[5],1);
}

void Answer::get(int n) {
	for(int i=n; i<=80; i++) {
		h.rec(1,1);
		if(i<20) r.ans.show(i,i);
		if(i>=20) r.ans.show(i,20);
		if(i<80) r.ans.choice(i);
	}
	bar(lcyn,0,50,u[5],1);
	cout<<"Press "; txt(lgrn,0,0,"ENTER",0); txt(lgry,0,0," to continue\npress ",0); txt(lred,0,0,"B",0); txt(lgry,0,0," to change a number of your choice",1);
	bar(lcyn,0,50,u[5],1);
	ch=_getch();
	if(ch==13) r.show();
	if(ch=='B') r.ans.change();
	else r.ans.get(80);
}
void Answer::choice(int i) {
	txt(lyel,0,0," IMPORTANT NOTE: ",0); cout<<" If you made a mistake...\n Just press the "; txt(lyel,0,0,"[LEFT]",0); cout<<" arrow key to change\n";
	bar(lcyn,blk,50,u[5],1);
	cout<<setw(3)<<i+1<<":"; txt(lyel,0,0," [1]A  [2]B  [3]C  [4]D  [5]E  [6]N/A  ",0);
	ch=_getch();
	if(ch=='1') xmn->ans[i]=A;
	else if(ch=='2') xmn->ans[i]=B;
	else if(ch=='3') xmn->ans[i]=C;
	else if(ch=='4') xmn->ans[i]=D;
	else if(ch=='5') xmn->ans[i]=E;
	else if(ch=='6') xmn->ans[i]=N;
	else if(i>0 && ch==75) r.ans.get(i-1);
	else r.ans.get(i);
}
void Answer::change() {
	h.rec(1,1);
	r.ans.show(80,20);
	cout<<"Which number do you want to change? ";
	cin>>ntmp;
	if(ntmp>=1 && ntmp<=80 && !cin.fail()) {
		h.rec(1,1);
		r.ans.show(80,20);
		r.ans.choice(ntmp-1);
		r.ans.another();
	}
	else {
		valid();
		cin.ignore();
		r.ans.change();
	}
}
void Answer::another() {
	h.rec(1,1);
	r.ans.show(80,20);
	cout<<"Do you wish to change another number? [Y/N] ";
	cin>>ch;
	if(ch=='y' || ch=='Y') r.ans.change();
	if(ch=='n' || ch=='N') r.show();
	else {
		valid();
		r.ans.another();
	}

}
void Answer::show(int i, int limit) {
	for(int j=0; j<limit; j++) {
		if(i<=20) {
			cout<<setw(3)<<j+1<<": ";
			txt(a.compare(xmn->ans[j], anskey[j]),0,0,r.detail(xmn->ans[j],40),1);
		}
		else if(i<=40) {
			cout<<setw(3)<<j+1<<": ";
			txt(a.compare(xmn->ans[j], anskey[j]),0,0,r.detail(xmn->ans[j],40),0);
			if(j+20<i) {
				cout<<setw(11)<<j+21<<": ";
				txt(a.compare(xmn->ans[j+20], anskey[j+20]),0,0,r.detail(xmn->ans[j+20],40),1);
			}
			if(j+20>=i) cout<<endl;
		}
		else if(i<=60) {
			cout<<setw(3)<<j+1<<": ";
			txt(a.compare(xmn->ans[j], anskey[j]),0,0,r.detail(xmn->ans[j],40),0);
			cout<<setw(11)<<j+21<<": ";
			txt(a.compare(xmn->ans[j+20], anskey[j+20]),0,0,r.detail(xmn->ans[j+20],40),0);
			if(j+40<i) {
				cout<<setw(11)<<j+41<<": ";
				txt(a.compare(xmn->ans[j+40], anskey[j+40]),0,0,r.detail(xmn->ans[j+40],40),1);
			}
			if(j+40>=i) cout<<endl;
		}
		else if(i<=80) {
			cout<<setw(3)<<j+1<<": ";
			txt(a.compare(xmn->ans[j], anskey[j]),0,0,r.detail(xmn->ans[j],40),0);
			cout<<setw(11)<<j+21<<": ";
			txt(a.compare(xmn->ans[j+20], anskey[j+20]),0,0,r.detail(xmn->ans[j+20],40),0);
			cout<<setw(11)<<j+41<<": ";
			txt(a.compare(xmn->ans[j+40], anskey[j+40]),0,0,r.detail(xmn->ans[j+40],40),0);
			if(j+60<i) {
				cout<<setw(11)<<j+61<<": ";
				txt(a.compare(xmn->ans[j+60], anskey[j+60]),0,0,r.detail(xmn->ans[j+60],40),1);
			}
			if(j+60>=i) cout<<endl;
		}
	}
	bar(lcyn,0,50,u[5],1);
}

string Record::detail(int t, int c) {
	if(c==40) {
		if(t==A) return "A";
		if(t==B) return "B";
		if(t==C) return "C";
		if(t==D) return "D";
		if(t==E) return "E";
		if(t==N) return "N";
	}
	else if(t==school) {
		if(c==1) return "Public High School";
		if(c==2) return "Science High School";
		if(c==3) return "State University";
		if(c==4) return "College High School";
		if(c==5) return "Private Sectarian";
		if(c==6) return "Private Non-Sectarian";
		else return " ";
	}
	else if(t==course) {
		if(c==1) return "BSCE";
		if(c==2) return "BSCpE";
		if(c==3) return "BSEEE";
		if(c==4) return "BSECE";
		if(c==5) return "BSME";
		if(c==6) return "BSIT";
		if(c==7) return "BSCS";
		if(c==8) return "BSEMC";
		if(c==9) return "ACT";
		else return " ";
	}
	else if(c==1) {
		if(t==prov) return "Province";
		if(t==frsh) return "Freshman";
		if(t==gender) return "Male";
		if(t==stat) return "Enrolled";
		else return " ";
	}
	else if(c==2) {
		if(t==prov) return "NCR";
		if(t==frsh) return "Transferee";
		if(t==gender) return "Female";
		if(t==stat) return "Not enrolled";
		else return " ";
	}
	else return " ";
}
void Record::get(int x) {
	h.rec(1,2);
	if(x<0) {
		txt(lgrn,blk,0,"Last Name: ",0);
		if(x<0) getline(cin,xmn->ln);
	}
	if(x>=0) cout<<right<<"        Last Name: "<<xmn->ln<<endl;
	if(x>0) cout<<"       First Name: "<<xmn->fn<<endl;
	if(x>1) cout<<" Middle Initial/s: "<<xmn->mi<<endl;
	if(x>2) cout<<"           Gender: "<<r.detail(gender,xmn->data[gender])<<endl;
	if(x>3) cout<<" Preferred Course: "<<r.detail(course,xmn->data[course])<<endl;
	if(x>4) cout<<"  Previous School: "<<r.detail(school,xmn->data[school])<<endl;
	if(x>5) cout<<"Type of Residence: "<<r.detail(prov,xmn->data[prov])<<endl;
	if(x>6) cout<<"Area of Residence: "<<xmn->re<<endl;
	if(x>7) cout<<" Type of Examinee: "<<r.detail(frsh,xmn->data[frsh])<<endl;
	if(x>8) cout<<"Enrollment Status: "<<r.detail(stat,xmn->data[stat])<<endl;
		bar(lcyn,blk,50,u[5],1);
	if(x==0) txt(lyel,0,0,"First Name: ",0);
	if(x==1) txt(lyel,0,0,"Middle Initial/s: ",0);
	if(x==2) txt(lyel,0,0,"Gender:",1);
	if(x==3) txt(lyel,0,0,"Preferred Course: ",1);
	if(x==4) txt(lyel,0,0,"Previous School: ",1);
	if(x==5) txt(lyel,0,0,"Type of Residence: ",1);
	if(x==6) txt(lyel,0,0,"Area of Residence: ",0);
	if(x==7) txt(lyel,0,0,"Type of Examinee: ",1);
	if(x==8) txt(lyel,0,0,"Enrollment Status: ",1);
		if(!(x==0||x==1||x==6)) bar(lcyn,blk,50,u[5],1);
	if(x==2) txt(lgrn,0,0,"\t[1] Male\n\t[2] Female\n\t[3] N/A",1);
	if(x==3) txt(lgrn,0,0,"\t[1] BSCE\t[6] BSIT\n\t[2] BSCpE\t[7] BSCS\n\t[3] BSEEE\t[8] BSEMC\n\t[4] BSECE\t[9] ACT\n\t[5] BSME\t[0] N/A",1);
	if(x==4) txt(lgrn,0,0,"[1] Public High School\t  [5] Private Sectarian\n[2] Science High School\t  [6] Private Non-Sectarian\n[3] State University\n[4] College High School\t  [0] N/A",1);
	if(x==5) txt(lgrn,0,0,"\t[1] Province\n\t[2] NCR\n\t[3] N/A",1);
	if(x==7) txt(lgrn,0,0,"\t[1] Freshman\n\t[2] Transferee",1);
	if(x==8) txt(lgrn,0,0,"\t[1] Enrolled\n\t[2] Not Enrolled",1);
		if(!(x==0||x==1||x==6)) bar(lcyn,blk,50,u[5],1);
	if(x==0) getline(cin,xmn->fn);
	if(x==1) getline(cin,xmn->mi);
	if(x==2) {
		ch=_getch();
		if(ch=='1') xmn->data[gender]=1;
		else if(ch=='2') xmn->data[gender]=2;
		else if(ch=='3') xmn->data[gender]=3;
		else r.get(x);
	}
	if(x==3) {
		ch=_getch();
		if(ch=='1') xmn->data[course]=1;
		else if(ch=='2') xmn->data[course]=2;
		else if(ch=='3') xmn->data[course]=3;
		else if(ch=='4') xmn->data[course]=4;
		else if(ch=='5') xmn->data[course]=5;
		else if(ch=='6') xmn->data[course]=6;
		else if(ch=='7') xmn->data[course]=7;
		else if(ch=='8') xmn->data[course]=8;
		else if(ch=='9') xmn->data[course]=9;
		else if(ch=='0') xmn->data[course]=10;
		else r.get(x);
	}
	if(x==4) {
		ch=_getch();
		if(ch=='1') xmn->data[school]=1;
		else if(ch=='2') xmn->data[school]=2;
		else if(ch=='3') xmn->data[school]=3;
		else if(ch=='4') xmn->data[school]=4;
		else if(ch=='5') xmn->data[school]=5;
		else if(ch=='6') xmn->data[school]=6;
		else if(ch=='0') xmn->data[school]=10;
		else r.get(x);
	}
	if(x==5) {
		ch=_getch();
		if(ch=='1') xmn->data[prov]=1;
		else if(ch=='2') xmn->data[prov]=2;
		else if(ch=='3') xmn->data[prov]=3;
		else r.get(x);
	}
	if(x==6) getline(cin,xmn->re);
	if(x==7) {
		ch=_getch();
		if(ch=='1') xmn->data[frsh]=1;
		else if(ch=='2') xmn->data[frsh]=2;
		else r.get(7);
	}
	if(x==8) {
		ch=_getch();
		if(ch=='1') xmn->data[stat]=1;
		else if(ch=='2') xmn->data[stat]=2;
		else r.get(8);
	}
	if(x==9) {
		if(!xmn->data[tt]) {
			cout<<"Press "; txt(lgrn,0,0,"ENTER KEY",0); cout<<" to get answers\n";
		}
		else if(xmn->data[tt]) {
			cout<<"Press "; txt(lred,0,0,"Q",0); cout<<" to show all examinee data\n";
		}
		txt(lyel,0,0,"Pick a letter",0); cout<<" to change examinee information\n";
		bar(lcyn,blk,50,u[5],1);
		txt(lyel,0,0,"\t[L] L",0); cout<<"ast Name\n";
		txt(lyel,0,0,"\t[F] F",0); cout<<"irst Name\n";
		txt(lyel,0,0,"\t[M] M",0); cout<<"iddle Initial/s\n";
		txt(lyel,0,0,"\t[G] G",0); cout<<"ender\n";
		txt(lyel,0,0,"\t[P] P",0); cout<<"referred Course\n";
		txt(lyel,0,0,"\t[S]",0); cout<<" Previous "; txt(lyel,0,0,"S",0); cout<<"chool\n";
		txt(lyel,0,0,"\t[R]",0); cout<<" Type of "; txt(lyel,0,0,"R",0); cout<<"esidence\n";
		txt(lyel,0,0,"\t[A] A",0); cout<<"rea of Residence\n";
		txt(lyel,0,0,"\t[T] T",0); cout<<"ype of Examinee\n";
		txt(lyel,0,0,"\t[E] E",0); cout<<"nrollment Status\n";
		bar(lcyn,blk,50,u[5],1);
		ch=_getch();
		if(ch==13 && !xmn->data[tt]) r.ans.get(0);
		if(ch=='L') r.get(-1);
		if(ch=='F') r.get(0);
		if(ch=='M') r.get(1);
		if(ch=='G') r.get(2);
		if(ch=='P') r.get(3);
		if(ch=='S') r.get(4);
		if(ch=='R') r.get(5);
		if(ch=='A') r.get(6);
		if(ch=='T') r.get(7);
		if(ch=='E') r.get(8);
		if(ch=='Q' && xmn->data[tt]) r.show();
		else r.get(9);
	}
}
void Record::show() {
	for(int i=0; i<5; i++) xmn->data[i]=0;
	h.rec(1,2);
	cout<<"        Last Name: "<<xmn->ln
		<<"\n       First Name: "<<xmn->fn
		<<"\n Middle Initial/s: "<<xmn->mi
		<<"\n           Gender: "<<r.detail(gender,xmn->data[gender])
		<<"\n Preferred Course: "<<r.detail(course,xmn->data[course])
		<<"\n  Previous School: "<<r.detail(school,xmn->data[school])
		<<"\nType of Residence: "<<r.detail(prov,xmn->data[prov])
		<<"\nArea of Residence: "<<xmn->re
		<<"\n Type of Examinee: "<<r.detail(frsh,xmn->data[frsh])
		<<"\nEnrollment Status: "<<r.detail(stat,xmn->data[stat])<<endl;
	h.rec(0,1);
	r.ans.show(80,20);
	for (int q=1; q<5; q++) {
		int off1(0), off2(0);
		if(q==3) off2=5;
		if(q==4) off1=5;
		for(int i=(20*(q-1))+off1; i<(20*q)+off2; i++) {
			if(xmn->ans[i]==anskey[i] || (i==69 && xmn->ans[69]==E)) {
				xmn->data[q]++;
				xmn->data[tt]++;
			}
		}
		cout<<setw(21)<<t[q]<<": "<<setw(2)<<xmn->data[q]<<" out of ";
		if(q==1) cout<<"20\n";
		if(q==2) cout<<"20\n";
		if(q==3) cout<<"25\n";
		if(q==4) cout<<"15\n";
	}
	cout<<setw(23)<<"TOTAL: "<<setw(2)<<xmn->data[tt]<<" out of 80\n";
	bar(lcyn,blk,50,u[5],1);
	cout<<"Press "; txt(lgrn,0,0,"ENTER KEY",0); cout<<" to update database\n";
	cout<<"Press "; txt(lyel,0,0,"B",0); cout<<" to change examinee information\n";
	cout<<"Press "; txt(lred,0,0,"A",0); cout<<" to change examinee answer sheet\n";
	bar(lcyn,blk,50,u[5],1);
	ch=_getch();
	if(ch==13) r.write();
	else if(ch=='B') r.get(9);
	else if(ch=='A') r.ans.change();
	else r.show();
}
void Record::write() {
	fs.open(file[0],ios::app);
	fs<<xmn->ln<<","<<xmn->fn<<","<<xmn->mi<<","<<r.detail(gender,xmn->data[gender]);
	for(int i=1; i<5; i++) fs<<","<<xmn->data[i];
	fs<<","<<xmn->data[tt]<<","<<r.detail(course,xmn->data[course])<<","<<r.detail(school,xmn->data[school])<<","<<xmn->re<<","<<r.detail(stat,xmn->data[stat])<<endl;
	fs.close();
	a.update();
}

void Analyst::update() {
	for(int i=0; i<80; i++) {
		tab[i][22]++;
		for(int j=1; j<7; j++) if((xmn->ans[i])==j) tab[i][j]++;
		if((xmn->ans[i]==anskey[i]) || (i==69 && xmn->ans[69]==E)) {
			tab[i][0]++;
			if(xmn->data[prov]==1) tab[i][7]++;
			else if(xmn->data[prov]==2) tab[i][8]++;
				else tab[i][9]++;
			if(xmn->data[frsh]==1) tab[i][10]++;
			else if(xmn->data[frsh]==2) tab[i][11]++;
				else tab[i][12]++;
			if(xmn->data[school]<5) tab[i][13]++;
			else if(xmn->data[school]>4) tab[i][14]++;
				else tab[i][15]++;
			if(xmn->data[gender]==1) tab[i][16]++;
			else if(xmn->data[gender]==2) tab[i][17]++;
				else tab[i][18]++;
			if(xmn->data[course]<6) tab[i][19]++;
			else if(xmn->data[course]>5) tab[i][20]++;
				else tab[i][21]++;
		}
	}
	a.write();
	a.formal();
	a.read();
	for(int i=0; i<80; i++) xmn->ans[i]=0;
	for(int i=0; i<11; i++) xmn->data[i]=0;
	delete xmn;
	a.show();
	txt(lgrn,0,0,"DATABASE UPDATED!!!",1);
	cout<<"Press "; txt(lgrn,0,0,"ENTER KEY",0); cout<<" to continue\n";
	cout<<"Press "; txt(lred,0,0,"X",0); cout<<" to exit program.\n";
	xmn=new Student;
	ch=_getch();
	if(ch==13) for(int i=-1; i<10; i++) r.get(i);
	else if(ch=='X') exit(1);
}
int Analyst::compare(int n, int c) {
	int color;
	if(n==c) color=lgrn;
	if(n!=c) color=lred;
	return color;
}
void Analyst::read() {
	fs.open(file[5],ios::in);
	getline(fs,stmp,'\n');
	for(int i=0; i<80; i++) {
		getline(fs,stmp,',');
		for(int j=0; j<22; j++) {
			getline(fs,stmp,',');
			tab[i][j]=atoi(stmp.c_str());
		}
		getline(fs,stmp,'\n'); 
		tab[i][22]=atoi(stmp.c_str());
	}
	fs.close();
}
void Analyst::write() {
	fs.open(file[5],ios::out);
	fs<<"Item,Correct,A,B,C,D,E,N,Province,NCR,N/A,Freshman,Transferee,N/A,Public,Private,N/A,Male,Female,N/A,Engineering,IT,N/A,Total\n";
	for(int i=0; i<80; i++) {
		fs<<i+1;
		for(int j=0; j<23; j++) fs<<","<<tab[i][j];
		fs<<"\n";
	}
	fs.close();
}
void Analyst::formal() {
	for(int m=1; m<=4; m++) {
		int off1=0, off2=0;
		fs.open(file[m],ios::out);
		if(m==3) off2=5;
		if(m==4) off1=5;
		for(int i=(20*(m-1))+off1; i<(20*m)+off2; i++) {
			fs<<","<<t[m]<<endl;
			fs<<i+1<<","<<tab[i][0]<<" out of "<<tab[i][22]<<" got the correct answer.,A,"<<tab[i][1]<<"\n"
			  <<","<<tab[i][7]<<" are from Province and "<<tab[i][8]<<" are from NCR.,B,"<<tab[i][2]<<"\n"
			  <<","<<tab[i][10]<<" are Freshmen and "<<tab[i][11]<<" are Transferee.,C,"<<tab[i][3]<<"\n"
			  <<","<<tab[i][13]<<" are from Public and "<<tab[i][14]<<" are from Private.,D,"<<tab[i][4]<<"\n"
			  <<","<<tab[i][16]<<" are Male and "<<tab[i][17]<<" are Female.,E,"<<tab[i][5]<<"\n"
			  <<",There are "<<tab[i][19]<<" examinees who preferred Engineering courses.,N/A,"<<tab[i][6]<<"\n"
			  <<",There are "<<tab[i][20]<<" examinees who preferred IT courses.,Total,"<<tab[i][22]<<"\n\n";
		}
		fs.close();
	}
}
void Analyst::show() {
	for(int i=0; i<80; i++) {
		if(i==0) {
			txt(15,0,0,u[0],0); bar(15,blk,140,u[5],0); txt(15,0,0,u[1],1);
			h.ana(63,1,62);
		}
		if(i==20) {
			txt(15,0,0,u[7],0); bar(15,blk,140,u[5],0); txt(15,0,0,u[8],1);
			h.ana(60,2,60);
		}
		if(i==40) {
			txt(15,0,0,u[7],0); bar(15,blk,140,u[5],0); txt(15,0,0,u[8],1);
			h.ana(61,3,61);
		}
		if(i==65) {
			txt(15,0,0,u[7],0); bar(15,blk,140,u[5],0); txt(15,0,0,u[8],1);
			h.ana(61,4,60);
		}
		txt(15,0,0,u[4],0);
		cout<<left<<setw(3)<<i+1; txt(15,0,0,u[4],0);
		cout<<setw(7)<<tab[i][0]; txt(15,0,0,u[4],0);
		for(int j=A; j<=N; j++) {
			if(j==anskey[i] || (i==69 && j==E)) SetConsoleTextAttribute(hand,15+(dgrn*16));
			cout<<setw(4)<<tab[i][j];
			SetConsoleTextAttribute(hand,7);
			if(j==N) txt(15,0,0," \xBA",0);
		}
		cout<<setw(9)<<tab[i][7]	<<setw(5)<<tab[i][8]	<<setw(5)<<tab[i][9]; txt(15,0,0,u[4],0);
		cout<<setw(9)<<tab[i][10]	<<setw(9)<<tab[i][11]	<<setw(5)<<tab[i][12]; txt(15,0,0,u[4],0);
		cout<<setw(7)<<tab[i][13]	<<setw(8)<<tab[i][14]	<<setw(5)<<tab[i][15]; txt(15,0,0,u[4],0);
		cout<<setw(4)<<tab[i][16]	<<setw(4)<<tab[i][17]	<<setw(5)<<tab[i][18]; txt(15,0,0,u[4],0);
		cout<<setw(7)<<tab[i][19]	<<setw(6)<<tab[i][20]	<<setw(5)<<tab[i][21]; txt(15,0,0,u[4],0);
		cout<<setw(5)<<tab[i][22]; txt(15,0,0,u[4],1);
	}
	txt(15,0,0,u[2],0); bar(15,blk,140,u[5],0); txt(15,0,0,u[3],1);
}

