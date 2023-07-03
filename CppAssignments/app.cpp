#include <iostream>
#include"Pointers.h"
#include "MultiThreading.h"
#include "FunctionTemplates.h"

auto func_add(auto a, auto b)->decltype(a+b);
//{
//	return a + b;
//}


int main(int argc,char* argv[])
{
	std::cout << "Hello World!\n";
	//FunctionTemplateTesting();
	//FuntionWithReturnType();

	auto result = add<char>(11, 22ul);
	std::cout << " result : " << result << " Size : " << sizeof(result) <<std::endl;

	auto result1 = subtract<double,double,double>(11.6, 22.5);
	std::cout << " result : " << result1 << " Size : " << sizeof(result1) << std::endl;

	auto result3 = func_add(11, 22ul);
	std::cout << " result : " << result3 << " Size : " << sizeof(result3) << std::endl;
	return 0;
}

auto func_add(auto a, auto b) -> decltype(a + b)
{
	return a + b;
}
