#include <iostream>
#include<cmath>
#include "Pointers.h"


const char* predictions[]{
    "a lot of kids running in the backyard!\n",
    "a lot of empty beer bootles on your work table.\n",
    "you Partying too much with kids wearing weird clothes.\n",
    "you running away from something really scary\n",
    "clouds gathering in the sky and an army standing ready for war\n",
    "dogs running around in a deserted empty city\n",
    "a lot of cars stuck in a terrible traffic jam\n",
    "you sitting in the dark typing lots of lines of code on your dirty computer\n",
    "you yelling at your boss. And oh no! You get fired!\n",
    "you laughing your lungs out. I've never seen this before.\n"
};

const char* TellMyFortune()
{
	size_t rand_num = static_cast<size_t>((rand() % std::size(predictions)));
	//std::cout << predictions[rand_num] << std::endl;
	return predictions[rand_num];
}

void FortuneProgram()
{
	char option = 'y';

	while (option == 'y')
	{
		std::cout << "Do you want me to tell your fortune ?\n";
		std::cin >> option;

		if (option == 'y')
			std::cout << TellMyFortune() << std::endl;

		if (option != 'y' && option != 'n')
			std::cout << "You Entered wrong choice \n" << option;

	}
}

void PointersOfDifferentTypes()
{
	int potion{ 33 };
	int mana{ 50 };
	
	int* p_var{ &potion };
	const int* p_var3{ &mana};

	const int* const p_var4{ &mana};
	int* const p_number{ &potion};



	std::cout << "Printing Pointer p_var : " << p_var << std::endl;
	std::cout << "Printing Dereferenced Pointer *p_var : " << *p_var << std::endl;

	//*p_var3 = 55;
	

	std::cout << " Mana Value : " << *p_var3 << std::endl;
	std::cout << " Potion Value : " << *p_var << std::endl;

	p_var3 = &potion;
	p_var = &mana;

	std::cout << " Mana Value : " << *p_var3 << std::endl;
	std::cout << " Potion Value : " << *p_var << std::endl;

}

void PointersToArray()
{
	int arr[]{ 20,10,30,40,59,74,88 };

	const int* const p_arr{ arr };
	
	std::cout << "Address of Array           : arr " << arr << std::endl;
	std::cout << "Pointer Address of Array   : p_arr " << p_arr << std::endl;
	std::cout << "Reference Address of Array : &arr " << &arr<< std::endl;

	std::cout << "First Element In Array *p_arr : " << *p_arr << std::endl;
	std::cout << "First Element In Array arr[0] : " << arr[0] << std::endl;

	arr[0] = 200;
	
	std::cout << "First Element In Array *p_arr : " << *p_arr << std::endl;
	std::cout << "First Element In Array arr[0] : " << arr[0] << std::endl;


	std::cout << "Size  : " <<std::size(arr) << std::endl;
	//std::cout << "Size : " << std::size(p_arr) << std::endl;
}

void Swaping2Arrays()
{
	int array1[]{ 20,10,30,40,59,74,88 };
	int array2[]{ 55,66,88,99,22,11,33 };
	int size = std::size(array1);

	int* p_arr1{ array1 };
	int* p_arr2{ array2 };

	std::cout << "Array 1 Start : " << array1[0] << std::endl;
	std::cout << "Array 2 Start : " << array2[0] << std::endl;

	int* temp = nullptr;

	for (unsigned int i{}; i < size; i++)
	{
		p_arr1 = &array1[i];
		p_arr2 = &array2[i];

		temp = p_arr1;
		p_arr1 = p_arr2;
		p_arr2 = temp;
	}

	std::cout << "Array 1 Start : " << *p_arr1<<std::endl;
	std::cout << "Array 2 Start : " << *p_arr2<<std::endl;

}
