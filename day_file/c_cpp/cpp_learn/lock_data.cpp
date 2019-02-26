#include <iostream>
#include <string>
#include <mutex>

using namespace std;

class Key
{
public:
	Key(){};
private:
	tr1::function<void* ()> mKey;
	tr1::function<void* ()> mVal;
public:
	template < typename U >
	U& Key(U u){ 
		U *b =& u;
			mKey = [=]()->void*
			{
				return b;
			};
			
			return *((U*)mKey());
	};
 
	template < typename V >
	V& Val(V t){ 
		V *b = &t;
			
			mVal = [=]()->void*
			{
				return b;
			};
			bValInit=true;
			return *((V*)mVal());
	};
};

template<typename T>
class vMap
{
public:
	vMap(void){};
	~vMap(){};
	void Add(vKey k){vKeys.push_back(k);};
	vKey& operator[](T v){
		for (int n = 0; n < vKeys.size(); n++)
		{
			if (vKeys[n].Key(v) == v)
				return vKeys[n];
		}
		return NULLKEY;
	};
private:
	vector<vKey> vKeys;
};

int main()
{



}