#pragma once
#include<map>
#include<vector>
#include<string>

namespace Game
{
	const std::map<std::pair<int, int>, std::vector<std::string>> gStageData =
	{
		{std::make_pair(1,0),{"stage001","easy","始まりの森"}},
		{std::make_pair(2,0),{"stage001","easy","底なしの沼"}},
		{std::make_pair(3,0),{"stage001","nomal","あああああ"}},
		{std::make_pair(4,0),{"stage001","nomal","あああああ"}},
		{std::make_pair(5,0),{"stage001","nomal","ああああ"}},

		{std::make_pair(-1,1),{"save"}},
		{std::make_pair(0,-1),{"title"}},
		{std::make_pair(0,0),{"start"}},
	};

	//
	const std::map<std::pair<int, int>, std::vector<std::string>> gSpecialStageData =
	{
		{std::make_pair(-1,1),{"save"}},
		{std::make_pair(0,-1),{"title"}},
		{std::make_pair(0,0),{"start"}},
	};
}