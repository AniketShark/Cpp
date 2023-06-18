#pragma once
#include <iostream>

// Integral Logic Conditions

void IntegralConditions()
{
	int condition = 0;

	bool boolCondition = condition;
	std::cout << std::boolalpha;

	if (condition)
	{
		std::cout << "Hello World!\n" << boolCondition;
	}
	else
	{
		std::cout << "Bye World!\n" << boolCondition;
	}

}

const int MAX_FRAMES = 30;
const int MAX_TIME_FOR_FRAME = 2;

void ConstantExpressions()
{
	if constexpr (MAX_TIME_FOR_FRAME * MAX_FRAMES > 0)
	{
		std::cout << "Constant Expression Result : " << MAX_TIME_FOR_FRAME * MAX_FRAMES << "\n";
	}
}

void IfConditionInitializer()
{
	bool go{ true };

	if (int highspeed{33};go)
	{
		if(highspeed > 30)
			std::cout << "Slow Down \n";
		else
			std::cout << "All Good\n";

	}
	else
	{
		std::cout << "HIgh Speed"<<highspeed << "\n";
	}
}

void SwitchConditionalInitializer()
{
	int int_condition{0};

	switch (int x{ 10 }, y{ 20 };
			int_condition)
		{
		case 0:
			std::cout << "Case 0 Value of X \n"<<x;
			break;
		default:
			std::cout << "Case 0 Value of X \n" << y;
			break;
		}

}

void EvenOrOddWithIfInitializer()
{
	int value;
	std::cout << "Please add an integral value : \n";
	std::cin >> value;

	if (int result{ value % 2 }; result) {
		std::cout << value << " Is Odd \n";
	}
	else
		std::cout << value << " Is Even\n";
}
