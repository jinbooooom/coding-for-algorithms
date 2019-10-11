

#include <iostream>
#include <string>
using namespace std;
void foo(string& s) {
	cout << s << endl;
}

int main() {
	cout << "OK" << endl;
	foo("hello world!);
}




