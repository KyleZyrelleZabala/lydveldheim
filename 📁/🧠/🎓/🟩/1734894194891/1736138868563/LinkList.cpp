#include <iostream>
#include <windows.h>
using namespace std;
	
	//linked list node structure
	struct Node {
		int data;
		Node *next;
	};
	
	//algorithm initializations
	class LinkList {
		public:
			void display();
			Node initial();
			Node newhead();
			Node newtail();
			Node insertb();
			Node inserta();
			void delhead();
			void deltail();
			void delnode();
	};
	
	//major program functions
	class Instance {
		public:
			void design();
			void count();
			int get();
			void validator();
			void set();
			int chooser();		
	};
	
	//variable definitions
	Node *o, *p, *q, *head, *tail;
	LinkList mode;
	Instance program;
	int x, y, z, nodes;
	char choice;
	
	//major program functions definitions
	void Instance::design() {
		system("cls");
		cout<<"=========================================\n"
			<<"         WELCOME TO THIS PROGRAM\n"
			<<"-----------------------------------------\n"
			<<"          Linked List Functions\n"
			<<"=========================================\n";
	}
	void Instance::count() {
		nodes=0;
		p=head;
		while(p!=NULL) {
			o=p;
			nodes++;
			p=p->next;
		}
	}	
	int Instance::get() {
		design();
		
		cout<<"Enter node data: ";
		cin>>x;
		
		if(cin.fail()) {
			validator();
			get();
		}
	}	
	void Instance::validator() {
		cin.clear();
		cin.ignore();
		cout<<"Invalid Input!!!\n";
		Sleep(1000);
		cout<<"Try again...\n";
		Sleep(1000);
	}	
	void Instance::set() {
		cout<<"=========================================\n";
		system("pause");
		chooser();
	}
	int Instance::chooser() {
		design();
		cout<<"[X] Exit\n\n[0] Clear List\n[1] Display List\n\n"
			<<"[2] Create New Node\n[3] Create New Head\n[4] Create New Tail\n\n"
			<<"[5] Insert New Node Before a Node\n[6] Insert New Node After a Node\n\n"
			<<"[7] Delete Head\n[8] Delete Tail\n[9] Delete Node\n"
			<<"=========================================\n"
			<<"Enter your choice: ";
		cin>>choice;
		cout<<"-----------------------------------------\n";
		if(choice=='1') mode.display();
		if(choice=='2') mode.initial();
		if(choice=='3') mode.newhead();
		if(choice=='4') mode.newtail();
		if(choice=='5') mode.insertb();
		if(choice=='6') mode.inserta();
		if(choice=='7') mode.delhead();
		if(choice=='8') mode.deltail();
		if(choice=='9') mode.delnode();
		if(choice=='0') {
			head=NULL;
			cout<<"List deleted.\n";
			set();
		}
		if(choice=='x'||choice=='X') exit(1);
		else {
			validator();
			cin.ignore();
			chooser();
		}
	}

		//Algorithms
		void LinkList::display() {												//for displaying purposes
			program.design();
			p=head;
			while(p!=NULL) {
				cout<< p->data <<"> ";
				p=p->next;
			}
			cout<<"[]\n";
			program.count();
			cout<<"-----------------------------------------\n";
			cout<<"Number of nodes: "<<nodes<<endl;
			program.set();
		}
		Node LinkList::initial() {												//creating a new node deleteing also all previous nodes
			program.design();
			program.get();
			
			p=new Node;
			p->data=x;
			p->next=NULL;
			head=p;
			tail=p;
			
			program.set();
		}
		Node LinkList::newhead() {												//insert new node at beginning
			program.design();
			
			if(!head) {
				cout<<"There exists no nodes to insert a head.\n";
			}
			if(head) {
				program.get();
				
				p=new Node;
				p->data=x;
				p->next=head;
				head=p;
			}
			
			program.set();
		}
		Node LinkList::newtail() {												//insert new node at end
			program.design();
			
			if(!head) {
				cout<<"There exists no node to insert a tail.\n";
			}
			if(head) {
				program.get();
				
				p=new Node;
				p->data=x;
				p->next=NULL;
				tail->next=p;
				tail=p;
			}
			
			program.set();
		}
		Node LinkList::insertb() {												//insert new node before a specific node
			program.design();
			
			if(!head) {
				cout<<"There exists no node to insert anywhere.\n";
			}
			if(head) {
				program.count();
				cout<<"Before which node do you want to insert? ";
				cin>>y;
				if(cin.fail()||y<=0||y>nodes) {
					program.validator();
					insertb();
				}
				else if(y==1) mode.newhead();
				else {
					Node *create;
					create=head;
					p=new Node;
					for(int i=1; i<y; i++) {
						o=create;
						q=create->next->next;
						create=create->next;
						
					}
					o->next=p;
					p->next=create;
					program.get();
					p->data=x;
				}
			}
			
			program.set();
		}
		Node LinkList::inserta() {												//insert new node at specific location
			program.design();
			
			if(!head) {
				cout<<"There exists no node to insert anywhere.\n";
			}
			if(head) {
				program.count();
				cout<<"After which node do you want to insert? ";
				cin>>y;
				if(cin.fail()||y<=0||y>nodes) {
					program.validator();
					mode.inserta();
				}
				else if(y==nodes) mode.newtail();
				else {
					Node *create;
					create=head;
					p=new Node;
					for(int i=1; i<=y; i++) {
						o=create;
						create=create->next;
					}
					o->next=p;
					p->next=create;
					
					program.get();
					p->data=x;
				}
			}
			
			program.set();
		}
		void LinkList::delhead() {												//delete first node
			program.design();
			
			if(!head) {//do nothing if no node exist
				cout<<"You cannot delete a node does not exist.\n";
			}
			else if(head->next==NULL) {//delete if only one node
				head=NULL;
				cout<<"Head Node Deleted.\n";
			}
			else if(head->next!=NULL) {//delete if more than one nodes
				p=head->next;
				delete head;
				head=p;
				cout<<"Head Node Deleted.\n";
			}
			
			program.set();
		}
		void LinkList::deltail() {												//delete last node
			Node *o;
			o=new Node;
			p=head;
			
			program.design();
			
			if(!head) {
				cout<<"You cannot delete a node does not exist.\n";
			}
			else if(head==tail) {//delete all if one node
				delete head;
				delete p;
				delete tail;
				cout<<"Tail node deleted.\n";
			}
			else if(head!=tail) {//delete tail if not one node
				while(p->next!=NULL) {
					o=p;
					p=p->next;
				}
				o->next=NULL;
				delete p;
				tail=o;
				cout<<"Tail node deleted.\n";
			}
			
			program.set();
		}
		void LinkList::delnode() {												//delete specific node
			program.design();
			
			if(!head) {
				cout<<"There exists no node to be deleted.\n";
			}
			if(head) {
				program.count();
				cout<<"Which node do you want to delete? ";
				cin>>z;
				
				if(cin.fail()||z<1||z>nodes) {
					program.validator();
					mode.delnode();
				}
				if(z==1) mode.delhead();
				else if(z==nodes) mode.deltail();
				else if(z>1&&z<nodes) {
					p=head;
					for(int i=1; i<z; i++) {
						o=p;
						q=p->next->next;
						p=p->next;
					}
					o->next=q;
					delete p;
					program.design();
					cout<<"Node Deleted.\n";
				}
			}
			
			program.set();
		}
		
		main() {
			program.chooser();
			return 0;
		}
