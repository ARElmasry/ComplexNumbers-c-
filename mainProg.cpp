#include<fstream>
#include"ComplexNumber.h"
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;
using namespace CNumbers; 

void ComplexNumberOperations(void);


int main()
{
	
	ComplexNumberOperations();
	
	return 0;
}

////////////////Function definition//////////////////////
void ComplexNumberOperations(void)
{
	
	ComplexNumber a,b;
  ofstream outFile("Results.txt", ios::app);      
	
	cout << "Enter the Real then the Imaginary values of 1st complex number: " << endl;
	cin >> a; 
	cout << "Enter the Real then the Imaginary values of 2nd complex number: " << endl;
	cin >> b; 

	cout << "( " << a << " ) + ( " << b << " ) = ( " << a + b << " ) " << endl;
	cout << "( " << a << " ) - ( " << b << " ) = ( " << a - b << " ) " << endl;
	cout << "( " << a << " ) * ( " << b << " ) = ( " << a * b << " ) " << endl;
	cout << "( " << a << " ) / ( " << b << " ) = ( " << a / b << " ) " << endl;
  cout << "Modulus of ( " << a << " ) is " << abs_value(a) << endl;
  cout << "Modulus of ( " << b << " ) is " << abs_value(b) << endl;
 if (outFile.is_open())
 	{
 		outFile << "a = " << a << ", b = " << b << endl;
 		outFile << "a + b = " << a + b << endl;
 		outFile << "a - b = " << a - b << endl;
 		outFile << "a * b = " << a * b << endl; 
 		outFile << "Modulus of ( " << a << " ) is " << abs_value(a) << endl;
 		outFile << "Modulus of ( " << b << " ) is " << abs_value(b) << endl;
		try
		{
			outFile << "a / b = " << a / b << endl << endl;
		}
		catch( std::exception & e )	
		{
			std::cerr << "Exception: "	<< e.what() << endl;
		}
		catch( ... ) 
		{
			std::cerr << "Unknown Error" << endl;	
		}		
 	}
 	
 	
}
