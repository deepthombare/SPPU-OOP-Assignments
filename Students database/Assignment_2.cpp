//============================================================================
// Name        : Assignment_2.cpp
// Author      : Deep Thombare
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
/*
Develop a program in C++ to create a database of student’s information system containing the following information:
Name, Roll number, Class, Division, Date of Birth, Blood group, Contact address, Telephone number, Driving license no. and other.
Construct the database with suitable member functions. Make use of constructor, default constructor, copy constructor,
destructor, static member functions, friend class, this pointer, inline code and
dynamic memory allocation operators-new and delete as well as exception handling.
 */
//============================================================================

#include <iostream>
#include<string>
using namespace std;
int totalno = 0;
class student
{
	public :
			int rollno,div;
			string bloodgroup,address,drivinglicense,dob,name,class_name;
			static string college;
			float cgpa;
			long int phno;
			student()							//Default constructor
			{
				rollno = 0;
				div = 0;
				phno = 0;
				cgpa = 0.0;

			}
			student(int rollno)					//Parameterized constructor
			{
				this->rollno = rollno;			//this pointer
			}
			student(const student& x)					//copy constructor
			{
				this->rollno = x.rollno;
				this->div = x.div;
				//this->bloodgroup = x.bloodgroup;
				this->class_name = x.class_name;
				this->address = x.address;
				//this->drivinglicense = x.drivinglicense;
				//this->dob = x.dob;
				this->name = x.name;
				this->cgpa = x.cgpa;
				this->phno = x.phno;
			}
			static void college_name()
			{
				cout<<"\nThe name of College is "<<college;
			}
			void getdata()
			{
				cout<<"\nEnter Name ";
				cin.ignore();
				getline(cin,name);

				cout<<"\nEnter contact address ";
				cin.ignore();
				getline(cin,address);

				cout<<"\nEnter Class Name ";
				cin.ignore();
				getline(cin,class_name);

				cout<<"\nEnter Roll no. ";
				cin>>rollno;


				cout<<"\nEnter division ";
				cin>>div;


				cout<<"\nEnter Phone number ";
				cin>>phno;

				cout<<"\nEnter your C.G.P.A of last sem ";
				cin>>cgpa;
				/*cout<<"\nEnter driving license no. ";
				getline(cin,drivinglicense);
				cout<<"\nEnter date of birth in format dd/mm/2020 ";
				getline(cin,dob);
				cout<<"\nEnter blood group in format A+/A-";
				cin>>bloodgroup;*/
			}
			void putdata()
			{
				cout<<"\n\nName : "<<name;
				cout<<"\nRoll no. : "<<rollno;
				cout<<"\nClass : "<<class_name;
				cout<<"\nDivision : "<<div;
				cout<<"\nContact Address : "<<address;
				cout<<"\nPhone number : "<<phno;
				/*cout<<"\nDOB : "<<dob;
				cout<<"\nBloog Group : "<<bloodgroup;
				cout<<"\nDriving lisence no. : "<<drivinglicense;*/
				cout<<"\nCGPA : "<<cgpa;
			}
			inline void update_phno()
			{	cin.ignore();
				cin>>phno;
			}
			inline void update_div()
			{	cin.ignore();
				cin>>div;
			}
			void update()
			{	int u;
				cout<<"\n\nEnter number to update : \n1.Division\n2.Contact Address\n3.Phone no.\n4.Class \n.5Cgpa";
				cin.ignore();
				cin>>u;
				try{
					if(u<1||u>5)
						throw u;
					else{
						switch(u)
						{
							case 1 : cout<<"\n Enter new division .";
									 update_div();
									 break;
							case 2 : fflush(stdin);
										cout<<"enter address: ";
										getline(cin,address,'\n');
									 break;
							case 3 :cout<<"\nEnter new Phone number";
									update_phno();
									break;
							case 4 :fflush(stdin);
									cout<<"\nEnter new Class Name ";
									getline(cin,class_name);
									break;
							case 5 :
									fflush(stdin);
									cout<<"\nEnter your new C.G.P.A of last sem ";
									cin>>cgpa;
									break;
							default : cout<<"\nENter valid input.";
									break;
						}
					}
				}
				catch(int u)
				{
					cout<<"\nPlease Enter valid option\n";
				}
			}
			void database()
			{
				cout<<endl<<name<<"	   "<<rollno<<"	 "<<class_name<<"	  "<<div<<" 		"<<address<<"			"<<cgpa;
			}

};
string student :: college = "Pict";
int main()
{
		int n;
		cout<<"Enter number of students";
		cin>>n;
		student *s[n];
		/*for(int i=0;i<10;i++)
		{
			s[i]=NULL;
		}*/
		while(true)
		{
				int c ;
				cout<<"\nEnter the index number of operation to perform."
						"\n1.Add new student"
						"\n2.Modify data of existing student."
						"\n3.Display data of particaular student"
						"\n4.Dispaly database"
						"\n5.delete rollno"
						"\n6.delete database"
						"\n7.Exit\n";
				cin.ignore();
				cin>>c;
				try{
					if (c<1 || c>7)
						throw c;
					else
					{
						switch(c)
						{
						case 1 :try{
									if (totalno==n)
										throw n;
									else
									{
										s[totalno] = new student;
										s[totalno]->getdata();
										totalno+=1;
									}
								}
								catch(...)
								{
									cout<<"\nNo new student can be added";
								}
								break;
						case 2 :int r,i;
								cout<<"\nEnter roll no. of student you want to modify data ";
								cin>>r;
								try{
										if (r<1 || r>n)
											throw r;
										else
										{
											for(i = 0;i<totalno;i++)
											{
												if(s[i]->rollno == r)
												{
													s[i]->update();
													cout<<"\nData updated.\n";
													break;
												}
											}
										}
								}
								catch(...)
								{
									cout<<"\nEnter valid option";
								}
								if(i==totalno)
								{cout<<"\nRoll Number not found.\n";}
								break;
						case 3 :int a,j;
								cout<<"\nEnter roll no. of student you want to dispaly data .";
								cin.ignore();
								cin>>a;
								for(j = 0;j<totalno;j++)
								{
									if(s[i]->rollno == a)
									{
										s[i]->putdata();
										break;
									}
								}
								if(i==totalno)
								{cout<<"\nRoll Number not found.";}
								break;
						case 4 :try{
									if (totalno == 0)
										throw totalno;
									else{
											cout<<"----------------------------------------------------------------------------";
											cout<<"\nName	Rollno	Class 	Division 	ContactAddress 		CGPA";
											cout<<"\n----------------------------------------------------------------------------";
											for(int i =0;i<totalno;i++)
											{
													s[i]->database();
											}
										}
								}
								catch(...)
								{
									cout<<"\nDatabase is empty ";
								}

								break;
						case 5 :int d,o;
								fflush(stdin);
								cout<<"\nEnter the rollno";
								cin>>d;
								for( o = 0;o<totalno;o++)
								{
									if(s[o]->rollno == d)
									{
										delete s[o];
										s[o]=NULL;
										for(int w = o+1;w<totalno;w++)
										{
											s[w-1] = s [w];
										}
										totalno -= 1;
										cout<<"\nDeleted roll no "<<d<<endl;
										break;
									}
								}
								if(o == totalno && o!=1 )
								{cout<<"\nRoll number not found.\n";}
								break;
						case 6 :for (int f = 0;f<totalno;f++)
								{
									delete s[f];
									s[f]=NULL;
								}
								totalno = 0;
								cout<<"\nDeleted all data\n";
								break;
						case 7 : exit(0);
								break;
						}
					}
				}
				catch(...)
				{
					cout<<"\nEnter valid option";
				}

	}
		delete[] s;
		return 0;
}
