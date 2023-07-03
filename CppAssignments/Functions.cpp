#include "Functions.h"
#include<iostream>

double PassingSizedArraysAsParameter(const double(&scores)[10])
{

	double sum = 0;
	for (size_t i{}; i < std::size(scores); i++)
	{
		sum += scores[i];
	}

	return sum;
}

double Sum(double scores[])
{
	double score_sum{};
	unsigned int count = sizeof(scores) / sizeof(double);

	for (size_t i{ 0 }; i < count; ++i) {
		score_sum += scores[i];
	}
	return score_sum;
}

void PassByValue(int age)
{
	std::cout << "Age passed to Function : " << age << std::endl;
	age++;
	std::cout << "Age passed to Function After Increament: " << age << std::endl;
}

void PassByReference(int& age)
{
	std::cout << "Age passed to Function : " << age << std::endl;
	age++;
}

void PassByPointer(int* age)
{
	std::cout << "Age passed to Function : " << *age << std::endl;
	(*age)++;
}

void FunctionParameterPassingTest()
{
	int age{ 10 };

	std::cout << "Age before PassByValue " << age << std::endl;
	PassByValue(age);
	std::cout << "Age After PassByValue : " << age << std::endl;

	std::cout << "Age before Passing By Reference :" << age << std::endl;
	PassByReference(age);
	std::cout << "Age After PassByReference : " << age << std::endl;

	std::cout << "Age before PassByPointer :" << age << std::endl;
	PassByPointer(&age);
	std::cout << "Age After PassByPointer : " << age << std::endl;

}

void ArrayAsParameter(int array[], size_t size)
{
	for (int i{}; i < size; i++)
	{
		std::cout << array[i] << std::endl;
	}
}

void ArraySizedAsReferenceParameter(int(&array)[5])
{
	for (int i{}; i < std::size(array); i++)
	{
		std::cout << array[i] << std::endl;
	}
}

void FunctionArrayParameterPassingTest()
{
	int array[]{ 10,40,100,10 ,20 };
	int array2[]{ 20,10,50,60,55,440,500 };

	ArrayAsParameter(array2, std::size(array2));
	ArraySizedAsReferenceParameter(array);
}



