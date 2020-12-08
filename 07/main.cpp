#include "vector.h"
#include <iostream>
#include <cassert>

void Test()
{
	Vector<std::string> vec(5);
	vec[0] = "a";
	vec[1] = "b";
	vec[2] = "c"; 
	vec[3] = "d"; 
	vec[4] = "e";

        Vector<std::string> vec2 = vec;
	assert(vec.size() == 5);	
	assert(vec == vec2);

	vec.push_back("f");
	vec2.resize(6);
	vec2[5] = "f";
	assert(vec == vec2);

	vec.pop_back();
	assert(vec.size() == 5);

	vec.clear();
	assert(vec.empty() == true);

	assert(vec2.capacity() == 9);
}

int main()
{
	Test();

	std::cout << "success" << std::endl;

	return 0;
}
