#include<iostream>
using namespace std;


	
class Complex
{
private:
	int i;
	int j;

public:

	Complex():i(0),j(0)
	{
	}

	Complex(int r,int s):i(r),j(s)
	{
	}
	
	void Display()
	{
	cout<<"\n I="<<i<<endl;
	cout<<"\n J="<<j<<endl;
	}
	
	const Complex& operator=(const Complex& right)
	{
		// Handle self-assignment:
		if(this == &right) 
		return *this;
		i = right.i;
		j = right.j;
		return *this;
	}

	Complex operator+(const Complex& right) const
	{
		/*Complex x;
		x.i = i+ right.i;
		x.j = j + right.j;
		return x;
*/

	return Complex(i + right.i,j+right.j);
	}
	
	Complex operator+(const int real)const 
	{
		return Complex(i+real,j);
	}
	
	bool operator==(const Complex & right)const 
	{
		return (i==right.i && j== right.j);
	}
	
	bool operator!=(const Complex & right)const 
	{
		return !((*this)==right);

	}
	
	Complex  operator++() 
	{
		++i;
		return *this;
	}
	Complex operator++(int) 
	{
		Complex a=*this;
		++i;
		return a;

	}
	
	void SetI(int p)
	{
		i=p;
	}
	
	void SetJ(int p)
	{
		j=p;
	}
	
	int GetI() const
	{
		return i;
	}
	
	int GetJ() const
	{
		return j;
	}
	friend ostream& operator<<(ostream& out, const Complex& c) ;
	friend istream& operator>>(istream& in, Complex& c);
	friend Complex operator+(const Complex& left,const Complex& right);
};



	
Complex operator+(const Complex& left,const Complex& right) 
	{
		Complex x;
		x.i = left.i+ right.i;
		x.j = left.j + right.j;
		return x;


	//return Complex(i + right.i,j+right.j);
	}
	
	
/*Complex operator+(const Complex& left,const Complex& right) 
	{
		Complex x;
		x.SetI(left.GetI()+ right.GetI());
		x.SetJ(left.GetJ()+ right.GetJ());
		return x;


	//return Complex(i + right.i,j+right.j);
	}
*/

ostream& operator<<(ostream& out, const Complex& c) 
	{
	
	out << "Real: " << c.i;
	out	<<" Imaginary"<<c.j
	out<< endl;
	return out;
//return out << "Real: " << c.i <<" Imaginary"<<c.j<< endl;
	}

istream& operator>>(istream& in, Complex& c)
{
cout<<"\n Enter real and imaginary";
	in >> c.i;
	in >> c.j;
	return in;
}
Complex operator+(int real , const Complex& right)
{
	return right+real;
}



int main()
{

	Complex c1(1,1),c2(2,2),c3;
	c1.Display();
	c2.Display();
	c3 = c1 + c2; //c1.operator+(c2)
	c3 = c3+1;
	c3 = 1+c2;
	c3.Display();
	/*c1= c3;
	c1.Display();
	cout<<c1;*/
	/*Complex c4;
	cin>>c4;
	cout<<c4;*/
return 0;
}
