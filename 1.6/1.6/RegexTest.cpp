#include <iostream>
#include <regex>
using namespace std;

double getNumberFormResult(match_results<string::const_iterator> result, int pos);

int main()
{
	string vector = "(100.44,-30.2)";

	const regex pattern("\\((-)?(\\d{1,8})(.)?(\\d{1,8})?,(-)?(\\d{1,8})(.)?(\\d{1,8})?\\)");

	match_results<string::const_iterator> result;

	bool valid = regex_match(vector, result, pattern);

	if (valid)
	{
		double x = getNumberFormResult(result, 1);

		double y = getNumberFormResult(result, 2);

		cout << "x: " << x << endl;

		cout << "y: " << y << endl;
	}

	return 0;
}

double getNumberFormResult(match_results<string::const_iterator> result, int pos)
{
	string Num = "";

	Num += result[1 + (pos - 1) * 4];
	Num += "1";

	double fNum = atoi(Num.c_str()) * atoi(result[2 + (pos - 1) * 4].str().c_str());

	string fDecimal = "";

	if (result[3 + (pos - 1) * 4] == ".")
	{
		fDecimal += result[1 + (pos - 1) * 4];
		fDecimal += "0.";
		fDecimal += result[4 + (pos - 1) * 4];
		fNum += atof(fDecimal.c_str());
	}

	return fNum;
}