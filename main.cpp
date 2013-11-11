#include <iostream>
#include <string>
#include <fstream>
#include "stdio.h"

using namespace std;

int main(int argc, char* argv[])
{
	//cout << argv[0] << " " << argv[1] << " " << argv[2] << " " <<  argc << endl;
	
	if((argv[1] == "-p") || (argc < 3))
	{
		cout << "[Error] Please select a brainfuck file to run. E.g. ./brainfuck -p test.bf" << endl;
	}
	else
	{
		ifstream ifile(argv[2]);
		if(!ifile.is_open())
		{
			cout << "[Error] Invalid input file specified" << endl;
		}
		else
		{
			string program((istreambuf_iterator<char>(ifile)),(istreambuf_iterator<char>())) ;
	
			int memory[30000] = {0};
			int *ptr = memory;
			int depth;

			for(unsigned int i = 0; i < program.size(); i++)
			{
				switch(program[i])
				{
					case '>':
						if(*ptr++ >= 30000)
						{
							*ptr = 0;
						}
					break;
					case '<':
						if(*ptr-- < 0)
						{
							*ptr = 30000;
						}
					break;
					case '+':
						(*ptr)++;
					break;
					case '-':
						(*ptr)--;
					break;
					case '.':
						putchar(*ptr);
					break;
					case ',':
						*ptr = getchar();
					break;
					case '[':
						if(*ptr != 0)
						{
							break;
						}

						depth = 1;
						while(depth)
						{
							i++;
							if(i >= program.size())
							{
								return -1;
							}
							if(program[i] == '[')
							{
								depth++;
							}
							if(program[i] == ']')
							{
								depth--;
							}
						}
				
					break;
					case ']':
						if(*ptr == 0)
						{
							break;
						}
						depth = 1;
						while(depth)
						{
							i--;
							if(i < 0)
							{
								return -1;
							}
							if(program[i] == ']')
							{
								depth++;
							}
							if(program[i] == '[')
							{
								depth--;
							}
						}
					
					break;
					default:
					break;
				}
			}
			getchar();
		}
	}
}
