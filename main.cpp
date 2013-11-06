#include <iostream>
#include <string>

using namespace std;

int main()
{
	string program;
	//test
	//brainfuck hello world from wikipedia
	//program = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
	//prints fibonacci sequence (http://www.hevanet.com/cristofd/brainfuck/fib.b)
	program = ">++++++++++>+>+[[+++++[>++++++++<-]>.<++++++[>--------<-]+<<<]>.>>[[-]<[>+<-]>>[<<+>+>-]<[>+<-[>+<-[>+<-[>+<-[>+<-[>+<-[>+<-[>+<-[>+<-[>[-]>+>+<<<-[>+<-]]]]]]]]]]]+>>>]<<<]";
	
	int memory[30000] = {0};
	int *ptr = memory;
	int depth;

	for(unsigned int i = 0; i < program.size(); i++)
	{
		switch(program[i])
		{
			case '>':
				ptr++;
			break;

			case '<':
				ptr--;
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