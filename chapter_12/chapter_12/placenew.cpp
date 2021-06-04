#include <iostream>
#include <string.h>
#include <new>

using namespace std;
const int BUF = 512;

class JustTesting
{
private:
	string words;
	int number;
public:
	JustTesting(const string& s = "Just Testing", int n = 0)
	{
		words = s;
		number = n;
		cout << words << " constructed\n";
	}
	~JustTesting() {
		cout << words << " destroyed\n";
	}
	void Show() const
	{
		cout << words << ", " << number << endl;
	}
};

int main3()
{
	char* buffer = new char[BUF];

	JustTesting* pc1, *pc2;

	pc1 = new(buffer) JustTesting;
	pc2 = new JustTesting("heapl", 20);

	cout << "Memory block addresses:\n" << "buffer: "
		<< (void*)buffer << "	heap:" << pc2 << endl;

	cout << "Memory contents:\n";
	cout << pc1 << ": ";
	pc1->Show();
	cout << pc2 << ": ";
	pc2->Show();

	cout << "===========================" << endl;
	JustTesting* pc3, *pc4;
	pc3 = new (buffer + sizeof(JustTesting)) JustTesting("bad Idea", 6);
	pc4 = new JustTesting("Heap2", 10);

	cout << "Memory contents:\n";
	cout << pc3 << ": ";
	pc3->Show();
	cout << pc4 << ": ";
	pc4->Show();

	delete pc2;
	delete pc4;

	pc3->~JustTesting();
	pc1->~JustTesting();

	delete[] buffer;
	
	cout << "Done\n";
	return 0;
}