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
		{{2,0},{"stage007","easy","���񂽂񌴂���"}},
		{{2,1},{"stage002","easy","�J�G���Ɠ����n��"}},
		{{3,-1},{"stage010","�ӂ�","�ɂ񂶂񕽌�"}},
		{{3,1},{"stage011","�ӂ�","�����݂��I"}},
		{{4,-1},{"stage009","�ӂ����炢","���㒍��"}},
		{{4,0},{"stage003","difficult","�ɂ񂶂�Ƃ��"}},
		{{4,1},{"stage004","nomal","�҂��҂��Ԃ�Ԃ�"}},
		{{5,-1},{"stage005","nomal","�����Ȃ��H�����Ȃ��H"}},
		{{5,1},{"stage006","�ނ���","���邮�邩���ނ�"}},
		{{6,-1},{"stage012","�ނ���","�̂ڂ�I"}},
		{{6,0},{"stage008","�܂��܂��ނ���","�A�X���`�b�N�A�X���`�b�N"}},

		{{13,0},{"stage013","�ӂ[","��������"}},
		{{14,0},{"stage014","�ނ���","���ǂ�����"}},
	

		{{-1,1},{"save"}},
		{{0,-1},{"title"}},
		{{0,0},{"start"}},
	};

}