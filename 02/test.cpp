#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "parser.cpp"
#include <cassert>


int ParseNum(std::string token)
{
	int i = 0;
	int res = 0;
	for (i = 0; i< token.length();i++)
	{
		res += pow(10,token.length() - i - 1)*(token[i] - '0');

	}
	return res;
}

void  ParseStr(std::string &token, std::ofstream& out)
{
	out << token << "\n";
}

void Start_fun(std::ofstream& out)
{
	out << "Start parcing line\n" ;
}

void Finish_fun(std::ofstream& out)
{
	out << "Finish parcing line\n";
}



void DefaultWorkTest()
{
	int (*num_parcer)(std::string) = &ParseNum;

	void (*start_parcer)( std::ofstream& out) = &Start_fun;
	void (*finish_parcer)( std::ofstream& out) = &Finish_fun;
	Parser p;
	std:: string line;
	std:: ifstream in("textin.txt");
	std:: ofstream fout;
	fout.open("textout.txt");

	void (*str_parcer)(std::string &, std::ofstream &out) = &ParseStr;

	if(in.is_open())
	{
		while (getline(in,line))
		{
			p.MakeParser(line);
			p.ParseLine(start_parcer,num_parcer,str_parcer,finish_parcer, fout);
		}
	}
	in.close();
	fout.close();
	std::ifstream checkin("textout.txt");
	if(checkin.is_open())
	{
		getline(checkin,line);
		assert(line=="Start parcing line");
		getline(checkin,line);                                                                                                                                                  assert(line=="pbpbpbpbpbp");

		getline(checkin,line); 
		assert(line=="45");

		getline(checkin,line);
		assert(line=="7");

		getline(checkin,line);   
		assert(line=="Finish parcing line");

		getline(checkin,line);  
		assert(line=="Start parcing line");

		getline(checkin,line); 
		assert(line=="3gufi");

		getline(checkin,line);                                                                                                                                                  assert(line=="Finish parcing line");
		assert(!getline(checkin,line));  
	}
	checkin.close();

}



int main()
{
	DefaultWorkTest();
	std::cout<<"success"<<std::endl;
	return 0;
}
