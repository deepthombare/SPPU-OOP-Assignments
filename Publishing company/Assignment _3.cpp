//============================================================================
// Name        : Assignment 3.cpp
// Author      : Deep Thombare
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
/*Imagine a publishing company which does marketing for book and audio cassette versions.
Create a class publication that stores the title (a string) and price (type float) of publications.
From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape class, allows user to enter data and displays the data members.
If an exception is caught, replace all the data member values with zero values.
 **/
//============================================================================

#include <iostream>
#include<string>
using namespace std;
int totalno = 0;
class Publisher
{
public:
				string  name;
				float cost_per_page,cost_per_sec;
				int no = 0;
				Publisher()
				{

					name = "";
					cost_per_page = 0;
					cost_per_sec = 0;
				}
				void copy(const Publisher *obj)
				{

					name = obj->name;
					cost_per_page = obj->cost_per_page;
					cost_per_sec = obj->cost_per_sec;

				}
				void input()
				{
					cout<<"\nEnter the name of Publisher\n";
					cin.ignore();
					cin>>name;
					cout<<"\nEnter cost printing a page of book\n";
					cin.ignore();
					cin>>cost_per_page;
					cout<<"\nEnter the cost of recording a minute\n";
					cin.ignore();
					cin>>cost_per_sec;
				}
				void show()
				{

					cout<<endl<<no<<"	"<<name<<"			";
					cout<<cost_per_page<<"						";
					cout<<cost_per_sec;
				}
};

class Book : public Publisher
{
	public :
			string title;
			int pages;
			float bookcost;
			static int bookno;
			Book()
			{
				title = "";
				pages = 0;
				bookcost = 0;
			}
			void book_input()
			{
				cout<<"\nEnter Title of Book";
				cin.ignore();
				cin>>title;
				cout<<"\nEnter pages of book.";
				cin.ignore();
				cin>>pages;
			}

			void show_book()
			{
				bookcost = pages * cost_per_page;

				cout<<title<<" 			"<<name<<" 		"<<pages<<"		"<<bookcost<<endl;
			}


};
int Book :: bookno = 0;
class Tape : public Publisher
{
	public : 	string title;
				float time_in_sec,tapecost;
				static int tapeno;
				Tape()
				{
					title = "";
					time_in_sec = 0.0;
					tapecost = 0;
				}
				void tape_input()
				{
					cout<<"\n Enter Title of Tape";
					cin.ignore();
					cin>>title;
					cout<<"\nEnter time in sec of tape.";
					cin.ignore();
					cin>>time_in_sec;

				}
				void show_tape()
				{
					tapecost = time_in_sec*cost_per_sec;
					cout<<title<<" 			"<<name<<" 		"<<time_in_sec<<"		"<<tapecost<<endl;

				}
};
int Tape :: tapeno = 0;
int main()
{	int n,c,a,q,w;
	cout<<"Enter no. of publishers"	;
	//cin.ignore();
	cin>>n;
	Publisher *p[n];

	for (int i = 0;i<n;i++)
	{
		p[i] = new Publisher;
		p[i]->input();
		totalno++;
		p[i]->no = totalno;
	}
	cout<<"\n\nNo.	The name of Publisher 	Cost printing a page of book		The cost of recording a minute";
	for (int i = 0;i<n;i++)
	{
		p[i]->show();

	}
	cout<<"\nEnter number of books and tapes you want to publish ";
	cin.ignore();
	cin>>q>>w;
	Book *b[q];
	Tape *t[w];
	int val = 1;
	while(val != 0 )
	{
		cout<<"\nEnter the index of what you want to publish"
				"\n1.Book"
				"\n2.Tape"
				"\n3.Exit input of data";
		cin.ignore();
		cin>>c;
		try
		{
			if(c<=0||c>3)
				throw c;
			else
			{
				switch(c)
				{
					case 1:
						try
						{
							if (Book::bookno == q || q == 0 )
								throw q;
							else
							{
								for (int i = 0;i<q;i++)
								{
									cin.ignore();
									cout<<"\nEnter index of Publisher for the book ";
									cin>>a;
									b[i] = new Book;
									b[i]->copy(p[a-1]);
									b[i]->book_input();
									b[i]->bookno++;

								}
							}
						}
						catch(...)
						{
							cout<<"\nYou have reached maximum number of inputs of books.\n";
						}
						break;
					case 2:
						try
						{
							if (Tape::tapeno == w || w == 0 )
								throw w;
							else
							{
								for (int i = 0;i<w;i++)
								{
									cout<<"\nEnter index of Publisher for the tape ";
									cin.ignore();
									cin>>a;
									t[i] = new Tape;
									t[i]->copy(p[a-1]);
									t[i]->tape_input();
									t[i]->tapeno++;								}
							}
						}
						catch(...)
						{
							cout<<"\nYou have reached maximum number of inputs of Tapes.\n";
						}
						break;

					case 3: val = 0;
				}
			}
		}
		catch(...)
		{
			cout<<"\nInvalid option";
		}

	}
	cout<<"------------------------------------------------------";
	val = 1 ;
	while(val != 0)
	{
		cout<<"\nEnter the index "
				"\n1.Display Publishers"
				"\n2.Display all books"
				"\n3.Display all Tapes"
				"\n4.Exit";
		int x;
		cin.ignore();
		cin>>x;
		try
		{
			if(x<=0 || x>=5)
				throw x;
			else
			{
				switch(x)
				{
					case 1:
						try
						{	if (n == 0)
								throw n;
							else
							{
								cout<<"\n\nNo.	The name of Publisher 	Cost printing a page of book		The cost of recording a sec";
								for (int i = 0;i<n;i++)
								{
									p[i]->show();

								}
							}
						}
						catch(...)
						{
							cout<<"\nDatabase is empty";
						}
						break;
					case 2:
						try
						{	if (q == 0)
								throw n;
							else
							{
								cout<<"\n\nTitle of book 		Publisher	Pages 	Cost\n";
								for (int i = 0;i<q;i++)
								{
									b[i]->show_book();
								}
							}
						}
						catch(...)
						{
							cout<<"\nNo Book available";
						}



						break;
					case 3 :
						try
						{	if (w == 0)
								throw ;
							else
							{
								cout<<"\n\nTitle of Tape 		Publisher	time in sec 	Cost\n";
								for (int i = 0;i<w;i++)
								{
									t[i]->show_tape();
								}							}
							}
						catch(...)
						{
							cout<<"\nNo Tape available";
						}


					break;
					case 4 : val = 0;
							break;
				}
			}
		}
		catch(...)
		{
			cout<<"\nInvalid option";
		}
	}


	delete[] b;
	delete[] t;
	delete[] p;
	return 0;
}
