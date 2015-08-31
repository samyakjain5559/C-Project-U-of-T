#include <iostream>

using namespace std;

const char strA[] = "First string";
const char strB[] = "Second string";
const char strC[] = "Third string";
const unsigned N=3;

int main(int argc,char **argv)
{
	const char* str[] = { strA,strB,strC };
	for(unsigned i=0;i <= N;++i)
		cout << "str[" << i << "] is \"" << str[i] << '"' << endl;

	return 0;
}
