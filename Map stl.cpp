/*Write a program in C++ to use map associative container.
 * The keys will be the names of states and the values will be the populations of the states.
 * When the program runs, the user is prompted to type the name of a state.
 * The program then looks in the map, using the state name as an index and returns the population of the state.*/
// Assignment  : 12
#include <iostream>
#include <map>
#include <string>
using namespace std;
class Map{
public:
	map<string,int> state ;
	Map(){
		 state["Maharashtra"] = 123;
		 state["Delhi"] = 30;
		 state["Goa"] = 2;
		 state["UP"] = 237;
		 state["Kerala"] = 36;
		 state["J&K"] = 13;

	}
    void display_all_states(){
        cout<<"--   STATES   -- "<<endl<<"1.Maharashtra"<<endl<<"2.Delhi"<<endl<<"3.Goa"<<endl<<"4.UP"<<endl<<"5.Kerala"<<endl<<"6.J&K"<<endl;
    }
    void Check_population(){

         string s;
         cout<<"Enter a name of state:-"<<endl;
         cin>>s;
         cout<<"Population of state you enter in Millions:- "<<endl;
         cout<<state.find(s)->second<<endl;

    }
};
int main()
{
    Map m;
    char c='y';
    m.display_all_states();
    while(c == 'y'){
        m.Check_population();
        cout<<"Would you like to continue (y/n) :-"<<endl;
        cin>>c;
    }
    return 0;
}
