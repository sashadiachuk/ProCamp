// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
extern "C"{
#include "mock.h"
#include "stringCopy.h"
}
using namespace std;

#define LOG_CALL(...)
#define LOG_PARAM_U32(...)

uint32_t f1_result = 0;

char null[50] = "Null pointer exeption, malloc has fault\n";

char null_In[50] = "NULL input exeption\n";// wrong input type, not char * , 

char wType[50] = "wrong input type, not char *\n";

int MALLOC_FAILS;

int main()
{
    std::cout << " testing stringCopy.c\n";

	/*
	test cases
	- input not NULL - > output not NULL- done;
	- memory leak, because of malloc; - done
	- input NULL -> output NULL - done;
	- wrong input type, not char *
	*/

	// Prepare
	MALLOC_FAILS = 0;// if 1 malloc has fault, memory leak simulation; 
	char string[] = "Hello";
		
	// Execute
	try
	{
		if (strCopy(1, setResultChar(string)) == NULL) {// MALLOC_FAILS  = 1 - >  memory leak, because of malloc;

			throw null;
		}
		
		else
		{
				cout << "Null pointer exeption - not submitted\n";
		}

	} 
	catch (const char* s)
	{
		printf("%s", s);

	}
	try
	{
		if (strCopy(0, setResultChar(string)) == NULL) {// input not NULL - > output not NULL 

			throw null;
		}

		else
		{
			cout << "Null pointer exeption - not submitted\n";
		}

	} 
	catch (const char* s)
	{
		printf("%s", s);

	}


	
	try // wrong input type, not char *;// pre setted value  setResultInt(25) or setResultChar(NULL)
	{
		if ((int)strCopy(0, setResultInt(25)) == 100) {

			throw wType;
		}
	}
	catch (const char* s)
	{
		printf("%s", s);

	}
	try //- input NULL->output NULL 
	{
		if ((int)strCopy(0, setResultChar(NULL)) == 1) {

			throw null_In;
		}
	}
	catch (const char* s)
	{
		printf("%s", s);

	}
}
	

	
