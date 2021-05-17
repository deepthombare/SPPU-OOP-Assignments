//============================================================================
// Name        : File.cpp
// Author      : Deep Thombare
// Assignment  : 7
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
/*Write a C++ program that creates an output file, writes information to it, closes the file, open
it again as an input file and read the information from the file.
 * */
//============================================================================

#include <iostream>
#include <fstream>
#include<string>
using namespace std;
int main()
{	int option;

	while (true)
    {

        cout << "\n============ MENU ============"
             << "\n"
             << "1) Write data to the file"
             << "\n"
             << "2) Read data from the file"
             << "\n"
			 <<	 "3) Clear file"
             << "\n4) Quit"
             << endl;

        cout << "Enter the option number : ";
        cin >> option;
        cin.ignore();
        cout << endl;
		switch(option)
		{
			case 1:{ fflush(stdin);
			    ofstream fout;
			    string line;
			    fout.open("OOP.txt",ios::app);
			    cout<<"Enter data \n";
			    getline(cin, line);
			    fout << line << endl;
			    fout.close();

			}break;
			case 2 :
			{
				string s1;
				ifstream inf;
				inf.open("OOP.txt",ios ::in|ios::app);
				cout<<"The data you entered is:-"<<endl;
				while(inf)
				{
					getline(inf,s1);
					cout<<s1<<endl;
				}
			break;}
			case 3 :
			{
				ofstream o;
				o.open("OOP.txt",ios::trunc);
				o.close();
			}break;
			default :
				exit(0);
		}
    }
	return 0;
}
