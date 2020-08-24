#pragma once
#include<unordered_map>
#include<vector>
#include<string>
#include"StageSelect/HexVec.hpp"

namespace Game
{
	const std::unordered_map<HexVec, std::vector<std::string>> gStageData =
	{
		//{{1,0},{"stage001","easy","�n�܂�̐X"}},
		{{1,0},{"rot","easy","rot"}},
		{{2,0},{"stage002","easy","�J�G���Ɠ����n��"}},
		{{3,0},{"stage003","difficult","�ɂ񂶂�Ƃ��"}},
		{{4,0},{"stage004","nomal","�g�����|�����ƃn�`"}},
		{{5,0},{"stage001","nomal","��������"}},

		{{-1,1},{"save"}},
		{{0,-1},{"title"}},
		{{0,0},{"start"}},
	};

	
}