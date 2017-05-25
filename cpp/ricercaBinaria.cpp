#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Bar{
	protected:
		int x;
		vector<long long> f;

	public:
		virtual void foobar() = 0;

		auto setX(const int x) -> void{
			f.erase(f.begin(), f.end());

			this->x = x;

			fib();
		};

		auto fib() -> void {
			f.push_back(1);
			f.push_back(1);

			for(int i = 2; i < x; i++)
				f.push_back(f.at(i-1) + f.at(i-2));

		};

		auto getFib() const -> void {
			for(auto i : f)
				cout << i << ' ';

			cout << '\n';
		};

		auto ricerca(long long n) const -> bool {
			vector<long long> f2(f);
			bool s = false;
			int met_div;
			do {
				met_div = f2.size() / 2;

				if(n == f2.at(met_div)) {
					s = true;
					break;
				}else if(n > f2.at(met_div)) {
					f2.erase(f2.begin(), f2.begin()+met_div);
				} else {
					f2.erase(f2.begin()+met_div, f2.end());
				}

				if(f2.size() == 1) {
					if(f.at(0) == n)
						s = true;
					else
						break;
				}

			} while(!s);

			return s;
		};
};

class Foo : public Bar {
	public:
		void foobar() override {
			cout << "FOOBAR!!" << endl;
		}

		Foo(int x) {
			this->x = x;
			fib();
		}

};

int main(int argc, char** argv)
{
	Foo foo(10);
	int sx;
	long long valRic;
	foo.getFib();

	cin >> valRic;

	cout << (foo.ricerca(valRic) ? "Presente" : "Non presente") << endl;

	cin >> sx;
	foo.setX(sx);

	foo.getFib();

	cin >> valRic;
	cout << (foo.ricerca(valRic) ? "Presente" : "Non presente") << endl;

	foo.foobar();

	return 0;
}
