#include <iostream>
using std::istream;
using std::ostream;

namespace CNumbers
{
	class ComplexNumber
	{
		public:
			ComplexNumber(void);
			ComplexNumber(double, double);
			ComplexNumber (double);
			ComplexNumber(const ComplexNumber &);
			ComplexNumber & operator = (const ComplexNumber &);
			~ComplexNumber(void)=default;;
			
			double getRealValue(void) const;
			double getImaginaryValue(void) const;
			void setRealValue(double);
			void setImaginaryValue(double);
			bool operator == (const ComplexNumber &)const;
			ComplexNumber operator + (const ComplexNumber &)const;
			ComplexNumber & operator += (const ComplexNumber &);
			ComplexNumber operator - (const ComplexNumber &)const;
			ComplexNumber & operator -= (const ComplexNumber &);
			ComplexNumber operator * (const ComplexNumber &)const;
			ComplexNumber & operator *= (const ComplexNumber &);
			ComplexNumber operator / (const ComplexNumber &)const;
			ComplexNumber & operator /= (const ComplexNumber &);
			
			
		
		private:
			double Real {0.0};
			double Imag {0.0};
			friend istream & operator >>(istream &, ComplexNumber &);
			friend ostream & operator <<(ostream &, const ComplexNumber &);
	};
	
	double abs_value (const ComplexNumber &);
	
///////////////Implementation Section///////////////////////////
	ComplexNumber::ComplexNumber(void): Real{0.0}, Imag{0.0} {}
	ComplexNumber::ComplexNumber(double r, double i):
								 Real(r), Imag(i) {}
	ComplexNumber::ComplexNumber(double r): Real{r}, Imag{0.0} {}
	ComplexNumber::ComplexNumber(const ComplexNumber & a) = default;
	ComplexNumber & ComplexNumber::
		operator = (const ComplexNumber & a) = default;
	
	double ComplexNumber::getRealValue(void) const
		{
			return Real;
		}
	double ComplexNumber::getImaginaryValue(void) const
		{
			return Imag;
		}
	void ComplexNumber::setRealValue(double r)
		{
			Real=r;
		}
	void ComplexNumber::setImaginaryValue(double i)
		{ 
			Imag=i;
		}

	bool ComplexNumber::operator == (const ComplexNumber & a) const
		{
			return Real==a.Real && Imag==a.Imag;
		}
	
	ComplexNumber ComplexNumber::operator +(const ComplexNumber & a) const
		{
			ComplexNumber result (Real+a.Real, Imag+a.Imag);
			return result;
		}
	ComplexNumber & ComplexNumber::operator +=(const ComplexNumber & a)
		{ 
			Real+=a.Real, Imag+=a.Imag;
			return * this;
		}
	
	ComplexNumber ComplexNumber::operator-(const ComplexNumber & a) const
		{
			ComplexNumber result (Real-a.Real, Imag-a.Imag);
			return result;
		}
	ComplexNumber & ComplexNumber::operator-=(const ComplexNumber&a)
		{
			Real-=a.Real, Imag-=a.Imag;
			return *this;
		}
	
	ComplexNumber ComplexNumber::operator*(const ComplexNumber & a) const
		{
			ComplexNumber result (Real*a.Real, Imag*a.Imag);
			return result;
		}
	ComplexNumber & ComplexNumber::operator*=(const ComplexNumber&a)
		{
			Real*=a.Real, Imag*=a.Imag;
			return *this;
		}
	
	ComplexNumber ComplexNumber::operator / (const ComplexNumber & a) const
		{
			const double threshold (1.e-36);
			auto divisor=a.Real * a.Real + a.Imag *	a.Imag;	
			if(fabs(divisor)<threshold)
				throw std::overflow_error("Division by zero error!!!");
			auto r = Real*a.Real + Imag*a.Imag;
			auto i = Imag*a.Real - Real*a.Imag;
			r/=divisor;
			i/=divisor;
			return ComplexNumber (r, i);
		}
	ComplexNumber & ComplexNumber::operator/=(const ComplexNumber & a)
		{
			const double threshold (1.e-36);
			auto divisor=a.Real * a.Real + a.Imag *	a.Imag;	
			if(fabs(divisor)<threshold)
				throw std::overflow_error("Division by zero error!!!");
			auto r = Real*a.Real + Imag*a.Imag;
			auto i = Imag*a.Real - Real*a.Imag;
			r/=divisor, i/=divisor;
			Real=r, Imag=i;
			return *this;
		}
		
	istream & operator >>(istream & i, ComplexNumber & a)
		{
			i >> a.Real >> a.Imag;
			return i;
		}
	ostream & operator << (ostream & o, const ComplexNumber & a)
		{
			o << a.Real << "  "<< a.Imag;
			return o;
		}
		
	double abs_value (const ComplexNumber & a)
	{
		return std::sqrt(a.getRealValue()*a.getRealValue()+a.getImaginaryValue()*a.getImaginaryValue());
	}
}
			
