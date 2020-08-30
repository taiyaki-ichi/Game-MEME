#pragma once
#include<unordered_map>
#include<vector>
#include<string>
#include"GameScene/Utility/HexVec.hpp"

namespace Game
{
	const std::unordered_map<HexVec, std::vector<std::string>> gStageData =
	{
		{{1,0},{"stage001","easy","�n�܂�̐X"}},
		//{{1,0},{"rot","easy","rot"}},
		{{2,0},{"stage007","easy","���񂽂񕽌�"}},
		{{3,0},{"stage002","easy","�J�G���Ɠ����n��"}},
		{{4,0},{"stage003","difficult","�ɂ񂶂�Ƃ��"}},
		{{5,0},{"stage004","nomal","�g�����|�����ƃn�`"}},
		{{6,0},{"stage005","nomal","�����Ȃ��H�����Ȃ��H"}},
		{{7,0},{"stage006","�ނ���","���邮�邩���ނ�"}},
		{{8,0},{"stage008","�܂��܂��ނ���","�A�X���`�b�N�A�X���`�b�N"}},
		{{9,0},{"stage009","�ӂ����炢","���㒍��"}},

		{{-1,1},{"save"}},
		{{0,-1},{"title"}},
		{{0,0},{"start"}},
	};

}