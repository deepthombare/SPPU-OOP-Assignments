/*	Assignment No. 1
 * 	Roll no. 21357
 *	Name : Deep Thombare
 *	DOP : 11/08/2020
 *	DOS : 11/08/2020

Implement a class Complex which represents the Complex Number data type. Implement the following operations:

1.	Constructor (including a default constructor which creates the complex number 0+0i).
2.	Overloaded operator+ to add two complex numbers.
3.	Overloaded operator* to multiply two complex numbers.
4.	Overloaded << and >> to print and read complex Numbers.

 */



#include <iostream>
using namespace std;

class complex
{	private: int real,img;
	public:
			complex()
			{
				real = 0;
				img = 0;
			}
			complex operator +(const complex obj)
			{	complex s;
				s.real = real + obj.real;
				s.img = img + obj.img;
				return s;
			}
			complex operator *(const complex obj)
			{
				complex m;
				m.real = real*obj.real-img*obj.img;
				m.img = real*obj.img + img*obj.real;
				return m;
			}
			complex operator -(const complex obj)
			{
				complex s;
				s.real = real - obj.real;
				s.img = img - obj.img;
				return s;
			}

			friend ostream & operator <<(ostream &out,complex &d )
			{
				out<<d.real<<" + i"<<d.img<<endl;
				return out;
			}
			friend istream & operator >>(istream &in,complex &c)
			{
				cout<<"\nEnter the real and imaginary part of complex no. \n";
				in>>c.real>>c.img;
				return in;
			}

};

int main()
{
	complex a,b;
	cin>>a;
	cin>>b;
	cout<<"\nThe complex number is "<<a;
	cout<<"\nThe complex number is "<<b<<endl;
	complex c,d,s;
	c = a + b;
	cout<<"The addition is ";
	cout<<c<<endl;
	s = a - b;
	cout<<"The Subtraction is ";
	cout<<s<<endl;
	d = a * b;
	cout<<"The multiplication is ";
	cout<<d;
	return 0;
}
