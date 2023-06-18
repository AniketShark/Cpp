#include <iostream>

int ThisMain(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "Program can be called with 4 arguments" << std::endl;
		std::cerr << "rooster a + b " << std::endl;
		std::cerr << "You callled with : ";
		for (int i = 0; i < argc; i++)
		{
			std::cout << " " << argv[i];
		}
		std::cout << std::endl;
		return 0;
	}


	float operand1{(float) atof(argv[1]) };
	float operand2{(float) atof(argv[3]) };
	const char* operation = argv[2];
	float result{};
	char c = *operation;


	switch (c)
	{
	case '+':
		result = operand1 + operand2;
		break;
	case '-':
		result = operand1 - operand2;
		break;
	case 'x':
		result = operand1 * operand2;
		break;
	case '/':
		result = operand1 / operand2;
		break;
	default:
		break;
	}
	std::cout << "Result : " << result << std::endl;
	return 0;
}