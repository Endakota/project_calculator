#pragma once
#include <cmath>
#include <iostream>
using namespace std;
class NonLinearEq{
public:
	double a, b;
	void setScope(double x1, double x2) {
		a = x1;
		b = x2;
	}
	double equation(double x) {
		return x * x * x * x - 18 * x * x * x - 10;
	}
	double dequation(double x, double eps) {
		return (this->equation(x + eps) - this->equation(x - eps)) / (2 * eps);
	}
	double doBisection(double eps) {
		double x1 = a, x2 = b;
		int iter = 0;
		while (fabs(x1 - x2) > 2 * eps) {
			double xc = (x2 + x1) / 2;
			if (this->equation(xc) * this->equation(x1) < 0) { x2 = xc; }
			else { x1 = xc; }
			iter++;
		}
		cout << "The root is " << x1 << endl;
		return iter;
	}
	double doNewton(double eps) {
		double x0 = 2, x1 = x0 - this->equation(x0) / this->dequation(x0, eps);
		while (fabs((x1 - x0) * (x1 - x0)) > eps) {
			x0 = x1;
			x1 = x0 - this->equation(x0) / this->dequation(x0, eps);
		}
		cout << "The root is " << x1;
	}
	double doSecant(double eps) {
		double x0 = b, x1 = x0 - this->equation(x0) / this->dequation(x0, eps);
		double x2 = 0;
		while (fabs(x1 - x0) > eps) {
			x2 = x1 - this->equation(x1) * (x1 - x0) / (this->equation(x1) - this->equation(x0));
			x0 = x1;
			x1 = x2;
		}
		cout << "The root is " << x2;
	}
	double doNewNewton(double eps) {

		double x0 = a, x1 = x0 - this->equation(x0) / this->dequation(x0, eps);
		double df = this->dequation(x0, eps);
		int iter = 0;


		while (fabs((x1 - x0)) > eps) {
			x0 = x1;
			x1 = x0 - this->equation(x0) / df;
			iter++;
			cout << "The root is " << x1 << endl;
		}
		return iter;
	}

};

