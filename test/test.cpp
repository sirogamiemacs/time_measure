#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <algorithm>
#include "../include/stopWatch.h"

int main(int argc, char** argv)
{
	// make timer.
	stopWatchController timer_con;
	
	timer_con.set_title_name("compare");
	if (argc == 2)
	{
		timer_con.set_file_name(argv[1]);
	} 
	else if (argc > 2)
	{
		std::cerr << "コマンドラインの引数が多すぎます。" << std::endl;
	}


	std::string title1 = "for_each";
	std::string title2 = "range_for";
	std::string title3 = "counter";
	
	unsigned const int FOR_EACH  = timer_con.new_timer(title1);
	unsigned const int RANGE_FOR = timer_con.new_timer(title2);
	unsigned const int COUNTER   = timer_con.new_timer(title3);


	std::vector<std::vector<int>> vecvec(1000, std::vector<int>(1000, 0));
	unsigned const int times = 100;

	for (int k = 0; k < times; k++)
	{
		timer_con.start(FOR_EACH);
		for_each(vecvec.begin(), vecvec.end(), [](vector<int>& vec)
		{
			for_each(vec.begin(), vec.end(), [](int& elem)
			{
				++elem;	
			});
		});
		timer_con.lap(FOR_EACH);
	}

	for (int k = 0; k < times; k++)
	{
		timer_con.start(RANGE_FOR);
		for (vector<int>& vec : vecvec)
		{
			for (int& elem : vec)
			{
				++elem;	
			}
		}
		timer_con.lap(RANGE_FOR);
	}

	for (int k = 0; k < times; k++)
	{
		timer_con.start(COUNTER);
		for (int i = 0; i < vecvec.size(); ++i) 
			{
			for (int j = 0; j < vecvec[i].size(); ++j) 
			{
				++vecvec[i][j];
			}		
		}
		timer_con.lap(COUNTER);
	}
}