#pragma once
#include<cstring>
#include<string>

// Basic Template Functions
template<typename T>
const T& maximum(const T& a, const T& b)
{
	return a > b ? a : b;
}

template<typename T>
void swap_data(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}


template<typename T>
int hunt_down(T value, T* array, size_t size)
{
	for (int i{ 0 }; i < size; i++)
	{
		if (value == array[i])
		{
			return i;
		}
	}
	return -1;
}
// TEMPLATE SPECIALIZATIONS
// Template Specializations work like normal functions
// these need to be declared in .h file and defination need to be in .cpp file.

template<>
int hunt_down<const char*>(const char* value, const char** array, size_t size);


// Template with return type

// the order of the parameters is important for templates with ReturnType as if you dont specify return type 
// you will get Compiler error
 
// template<typename ReturnType,typename T, typename P>
// max<int,int,int>(4,6)  :  valid as return type is specified in first position in templete description
// max<int,int>(4,6) : valid as return type is present. Parameter types will be deduced based on parameters types passed 
// max<int>(4,6) : valid as return type is present. Parameter types will be deduced based on parameters types passed
// max(4,6) : ***Compiler Error!! as return type is mandatory to be provided***
// 


// template<typename T,typename ReturnType, typename P> : ***BAD DESIGN! as this forces you to provide atleast 2 types for your function to be valid*** 
// max<int>(4,6)     : Compiler Error!! as return type is at second place and we have specified only T here that is insufficient for compiler to deduce Return Type.
// max<int,int>(4,6) : valid as return type is present. Parameter types will be deduced based on parameters types passed 
//
template<typename ReturnType,typename T, typename P>
ReturnType max(T a, P b)
{
	return (a > b) ? a : b;
}

template<typename T, typename P>
std::string concatenate(T a, P b)
{
	return std::to_string(a) + std::to_string(b);
}

// Auto deduction of return type
template<typename T, typename P>
auto sum(T a, P b);

// Using trailing return type to deduce actual return type of the function.
// 
// in template you can use decltype(expression) as trailing return type to deduce
// return type at function declaration.
template<typename T, typename P>
auto maxi(T a, P b) -> decltype((a > b) ? a : b);


/// Default Arguments Type in Templates
template <typename ReturnType = double, typename T, typename P>
ReturnType add(T a, P b)
{
	return a + b;
}

/// Default Arguments Type in Templates
template <typename T, typename P, typename ReturnType = double>
ReturnType subtract(T a, P b)
{
	return a - b;
}

// Auto Fuction Templates 
//auto func_add(auto a, auto b)
//{
//	return a + b;
//}



/// <summary>
/// Section dedicated to testing methods
/// </summary>
void FunctionTemplateTesting();
void FuntionWithReturnType();
