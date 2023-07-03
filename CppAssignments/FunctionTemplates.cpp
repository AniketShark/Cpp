#include "FunctionTemplates.h"
#include <string>
#include <iostream>

template<>
int hunt_down<const char*>(const char* value, const char** array, size_t size)
{
	for (int i{ 0 }; i < size; i++)
	{
		if (std::strcmp(value, array[i]) == 0)
		{
			return i;
		}
	}
	return -1;
}

template<typename T, typename P>
auto sum(T a, P b)
{
	return a + b;
}

void FunctionTemplateTesting()
{
	const int b = 20.7;
	const int a{ 10 };
	const int& max = maximum(a, b);
	std::cout << "A : " << &a << " B : " << &b << " Max : " << max << " Max Address : " << &max << std::endl;

	std::string to_find{"Karly"};
	std::string students[]{ "Steve","Karly","Sally","Salim" };
	int result = hunt_down(to_find, students, std::size(students));
	std::cout << to_find << " Found ? : " << result << std::endl;

	std::string to_find3{"Sally"};
	const char* studentsnew[]{ "Steve","Karly","Sally","Salim" };
	result = hunt_down(to_find3.c_str(), studentsnew, std::size(studentsnew));
	std::cout << to_find3 << " Found ? : " << result << std::endl;


	double to_find2{ 820.546 };
	double doubleValues[]{ 20.4,78.5,67.5,55.5,22.887,44.55,820.546 };
	result = hunt_down(to_find2, doubleValues, std::size(doubleValues));
	std::cout << to_find2 << " Found ? : " << result << std::endl;

	// Swap Function
	int c = 20;
	int d{ 10 };
	std::cout << "C : " << &c << " D : " << &d << " C : " << c << " D : " << d << std::endl;
	swap_data(c, d);
	std::cout << "C : " << &c << " D : " << &d << " C : " << c << " D : " << d << std::endl;

	std::string e{"Hello"};
	std::string f{ "World" };
	std::cout << " E : " << e << " F : " << f << std::endl;
	swap_data(e, f);
	std::cout << " E : " << e << " F : " << f << std::endl;
}

void FuntionWithReturnType()
{
	const double b = 20.7;
	const int a{ 10 };
	const char c {'B'};

	printf("%d  %f   max? = %f \n", a, b, max<double, double, int>(b, a));
	printf("%d  %c   max? = %c \n", a, c, max<char>(c, a));
	printf("%d  %c   max? = %d \n", a, c, max<int>(c, a));
	
	auto result = sum(a, c);
	printf(" Size Of result %d \n ", sizeof(result));

	printf("Sum of %d + %c = %c \n", a, c,result);
}