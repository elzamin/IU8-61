#include <iostream>
#include <cmath>
#define n 0.3			//норма обучения
using namespace std;

class Net
{
private:
	double w[5];
	int bad;

	bool y(double x)
	{
		return x >= 0.5 ? 1 : 0;
	}

	double f(double x)
	{
		cout << "f(net) = " << (0.5 / (tan(x) + 1.0)) << endl;
		return (0.5 / (tan(x) + 1.0));
	}

	double net_(bool x1, bool x2, bool x3, bool x4, double w0, double w1, double w2, double w3, double w4)
	{
		return (1 * w0 + x1 * w1 + x2 * w2 + x3 * w3 + x4 * w4);
	}

	bool target(bool x1, bool x2, bool x3, bool x4)
	{
		return !((!x1 || x2) && !x3 || x4);
	}

	void cycle(bool x1, bool x2, bool x3, bool x4)
	{
		int delta;
		cout << "-------------------\nResults for F(";
		cout << x1 << x2 << x3 << x4 << "):\n\n";
		double net = net_(x1, x2, x3, x4, w[0], w[1], w[2], w[3], w[4]);
		cout << "net = " << net << endl;
		bool a = y(f(net));
		cout << "y(f) = " << a << endl;
		bool b = target(x1, x2, x3, x4);
		cout << "target = " << b << endl;
		delta = b - a;
		cout << "delta = " << delta << endl;
		if (a != b)
			bad++;
		//int deltaw0 = (n*delta*(f(net)-f(netp)))/(net-netp);
		double deltaw0 = n * delta;
		cout << "delta weight [0] = " << deltaw0 << endl;
		//int deltaw1 = (n*delta*(f(net)-f(netp))*x1)/(net-netp);
		double deltaw1 = n * delta*(int)x1;
		cout << "delta weight [1] = " << deltaw1 << endl;
		//int deltaw2 = (n*delta*(f(net)-f(netp))*x2)/(net-netp);
		double deltaw2 = n * delta*(int)x2;
		cout << "delta weight [2] = " << deltaw2 << endl;
		//int deltaw3 = (n*delta*(f(net)-f(netp))*x3)/(net-netp);
		double deltaw3 = n * delta*(int)x3;
		cout << "delta weight [3] = " << deltaw3 << endl;
		//int deltaw4 = (n*delta*(f(net)-f(netp))*x4)/(net-netp);
		double deltaw4 = n * delta*(int)x4;
		cout << "delta weight [4]  = " << deltaw4 << endl;
		w[0] += deltaw0;
		cout << "weight [0]  = " << w[0] << endl;
		w[1] += deltaw1;
		cout << "weight [1]  = " << w[1] << endl;
		w[2] += deltaw2;
		cout << "weight [2]  = " << w[2] << endl;
		w[3] += deltaw3;
		cout << "weight [3]  = " << w[3] << endl;
		w[4] += deltaw4;
		cout << "weight [4]  = " << w[4] << endl;
	}

	void start()
	{
		bad = 0;
		cycle(false, false, false, false);
		cycle(false, false, false, true);
		cycle(false, false, true, false);
		cycle(false, false, true, true);
		cycle(false, true, false, false);
		cycle(false, true, false, true);
		cycle(false, true, true, false);
		cycle(false, true, true, true);
		cycle(true, false, false, false);
		cycle(true, false, false, true);
		cycle(true, false, true, false);
		cycle(true, false, true, true);
		cycle(true, true, false, false);
		cycle(true, true, false, true);
		cycle(true, true, true, false);
		cycle(true, true, true, true);
		cout << endl << "Mistakes = " << bad << endl << endl;
	}
public:
	Net(double x0, double x1, double x2, double x3, double x4)
	{
		int i = 0;
		w[0] = x0;
		w[1] = x1;
		w[2] = x2;
		w[3] = x3;
		w[4] = x4;
		//for(int i = 0; i <300 ; i++)
		do
		{
			i++;
			cout << "Generation # " << i << endl;;
			start();
			cout << "--------------------------------------\n";
		} while (bad != 0);
		cout << "Required generations to learn = " << i << endl;
	}

	~Net() {}
};

int main()
{
	Net * A = new Net(0, 0, 0, 0, 0);
	cout << "by Usubaliev Elzamin IU8-51\n";
	system("pause");
	return 0;
}
