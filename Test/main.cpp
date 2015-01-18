#include <iostream>
#include <Bencode.h>

using namespace std;
using namespace Bencode;

int main()
{
	Encoder e;
	Value v;
	v.Type = ValueType::List;
	v.VList.emplace_back(make_shared<Value>("test"));
	v.VList.emplace_back(make_shared<Value>(12));
	v.VList.emplace_back(make_shared<Value>(450));

	Decoder d;
	string str = e << v;
	size_t i = 0;
	for (; i < str.length() - 1; ++i)
		if (d << str[i])
		{
			cerr << "test failed." << endl;
			abort();
		}
	if (d << str[i])
		cerr << "test passed." << endl;

	return 0;
}
