#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "parser.h"
#include <functional>

void Parser::ParseLine( callBackStart cbst, callBackNum cbnm, callBackStr cbstr,callBackFinish cbfsh, std::ofstream &out)
{
	int len = line.length();
	int current_pos = 0;
	int i;
	std:: string token = "";

	cbst(out);

	while(current_pos < len)
	{
		if(line[current_pos] != ' ' && line[current_pos] != '\t' && line[current_pos] != '\n' && current_pos != len-1 )
		{
			token += line[current_pos];
			++current_pos;			
		}
		else
		{
			if(isdigit(line[current_pos]))
			{
				cbnm(token, out);
			}
			else
			{
				cbstr(token, out);
			}

			token = "";
			++current_pos;
		}

	}

	cbfsh(out);
}

