#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <functional>

using callBackStart = std::function<void(std::ofstream&)>;
using callBackNum = std::function<void(std::string &, std:: ofstream &)>;
using callBackStr = std::function<void(std::string &, std:: ofstream &)>; 
using callBackFinish = std::function<void(std::ofstream&)>;

class Parser
{
	private:
		std::string line;

	public:
		Parser()
		{
			line = "";
		}

		void MakeParser(std::string &line_)
		{
			line = line_;
		}

		void ParseLine(callBackStart cbst, callBackNum cbnm, callBackStr cbstr,callBackFinish cbfsh, std::ofstream &out);

};
