#include <iostream>
#include <array>
#include <vector>

using namespace std;
struct tovari {
	string name;
	int colvo;
	int price;
};
void print_tovar(ostream& out, vector<tovari>& tovar)
{
	for (auto& pos : tovar)
		out << pos.name << ". " << pos.colvo << ". " << pos.price;
}

int main(int argc, const char* argv[])
{
	const 
	if (argc != 4) {
		cerr << "Error use four parameters/n";
		return 5;
	}
	else {
		if 
	}
}

	/*
	array <int, 6> arrl;
	for (auto pos : arrl) cout << pos << " "; cout << endl;
	for (auto pos : arrl)
	{
		pos = rand() % 10;
	}
	for (auto pos : arrl) cout << pos << " "; cout << endl;
	for (auto it = arrl.begin(); it != arrl.end(); ++it)
		cout << *it << " ";
	for (int i = 0; i < size(arrl); i++)
		cout << arrl[i] << endl;
	cout << endl;
	cout << "Hello world!" << endl;
	vector<int> vl, v2;
	//vl.resize(10);
	for (int i = 0; i < 10; i++) {
		cout << "capacity=" << vl.capacity() << "size=" << vl.size();
		cout << endl;
		vl.push_back(i);
	}
	vector<double>v3;
	for (int i = 0; i < 100000; i++) {
		v3.push_back(i);
		cout << "capacity=" << v3.capacity() << "size=" << v3.size() << endl;
	}
	*/
}