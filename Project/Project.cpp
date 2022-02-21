#include "NonLinearEq.h"
using namespace std;
int main()
{
	NonLinearEq s1;
	s1.setScope(0, 5);
	cout << s1.doBisection(0.01);
	return 0;
}
