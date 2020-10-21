#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

class Parser
{
	private:
		std::string line;

	public:
		Parser()
		{
			line = "";
			//fout.open("textout.txt");
		}

		void MakeParser(std::string line_)
		{
			line = line_ ;
		}

		void ParseLine(void (*callBackStart)(std::ofstream& out),int (*callBackNum)(std::string),void  (*callBackStr)(std::string &, std::ofstream &out),void (*callBackFinish)(std::ofstream& out), std::ofstream &out)
		{
			int len = line.length();
			//std::cout<<"длина строки: "<<len<<std::endl;

			int current_pos = 0;
			int i;
			std:: string token = "";
			bool is_num = true;

			callBackStart(out);

			while(current_pos < len)
			{
				if(line[current_pos] != ' ' && line[current_pos] != '\t' && line[current_pos] != '\n'&& current_pos != len-1 )
				{
					token += line[current_pos];

					if('0' > line[current_pos] || line[current_pos] > '9')
					{
						is_num = false;

					}
					++current_pos;				
				}
				else
				{
					if(is_num == true)
					{
						out << callBackNum(token)<< "\n";
					}
					else
					{
						callBackStr(token, out)  ;

					}
					is_num = true;
					token = "";
					++current_pos;
				}

			}
			callBackFinish(out);

		}




};
