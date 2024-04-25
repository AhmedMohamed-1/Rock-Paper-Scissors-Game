#include <iostream>
using namespace std;

class Class_calculator {
private :
	int _FirstNum = 0;
	int _InputUserNumber = 0;
	int _sign = 0;
public:
	int Add(int Num1) {
		_sign = 1;
		_InputUserNumber = Num1;
		return _FirstNum += Num1;
	}
	int Subtract(int Num1) {
		_sign = 2;
		_InputUserNumber = Num1;
		return _FirstNum -= Num1;
		
	}
	int Multiply(int Num1) {
		_sign = 3;
		_InputUserNumber = Num1;
		return _FirstNum *= Num1;
		
	}
	int Divide(int Num1) {
		_sign = 4;
		_InputUserNumber = Num1;
		return _FirstNum /= Num1;
		
	}
	void Clear()
	{
		_sign = 0;
		_FirstNum = 0;
	}
	void PrintResult() {
		switch (_sign)
		{
		case 1:
			cout << "Result After Adding " << _InputUserNumber << " is : " << _FirstNum << endl;
			break;
		case 2:
			cout << "Result After Subtracting " << _InputUserNumber << " is : " << _FirstNum << endl;
			break;
		case 3:
			cout << "Result After Multiplying " << _InputUserNumber << " is : " << _FirstNum << endl;
			break;
		case 4:
			cout << "Result After Dividing " << _InputUserNumber << " is : " << _FirstNum << endl ;
			break;
		default:
			cout << "Result After Clearing is : " << _FirstNum << endl;
			break;
		}
	}
};


int main()
{
	Class_calculator Calculator;

	Calculator.Clear();

	Calculator.Add(10);
	Calculator.PrintResult();

	Calculator.Add(100);
	Calculator.PrintResult();

	Calculator.Multiply(3);
	Calculator.PrintResult();

	Calculator.Divide(2);
	Calculator.PrintResult();

	Calculator.Subtract(50);
	Calculator.PrintResult();

	Calculator.Clear();
	Calculator.PrintResult();

	Calculator.Add(10);
	Calculator.PrintResult();

}

