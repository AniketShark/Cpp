#pragma once

extern double PassingSizedArraysAsParameter(const double(&scores)[10]);
extern double Sum(double scores[]);
void PassByValue(int age);
void PassByReference(int& age);
void PassByPointer(int* age);

void FunctionParameterPassingTest();
void ArrayAsParameter(int array[], size_t size);
void ArraySizedAsReferenceParameter(int(&array)[5]);

void FunctionArrayParameterPassingTest();

constexpr int Add2Numbers(int a, int b)
{
	return a + b;
}
consteval int MultiplyBy3(int number)
{
	return number * 3;
}


