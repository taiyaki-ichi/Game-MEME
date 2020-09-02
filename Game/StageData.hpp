#pragma once
#include<unordered_map>
#include<vector>
#include<string>
#include"GameScene/Utility/HexVec.hpp"

namespace Game
{
	const std::unordered_map<HexVec, std::vector<std::string>> gStageData =
	{
		{{1,0},{"stage007","easy","���񂽂񌴂���"}},
		{{2,0},{"stage001","easy","�n�܂�̐X"}},
		{{2,1},{"stage002","easy","�J�G���Ɠ����n��"}},
		{{3,-1},{"stage010","nomal","�ɂ񂶂񕽌�"}},
		{{3,1},{"stage011","nomal","�����݂��I"}},
		{{4,0},{"stage013","nomal","��������"}},
		{{4,-1},{"stage009","nomal","���㒍��"}},
		{{5,0},{"stage005","nomal","�����Ȃ��H�����Ȃ��H"}},
		{{5,1},{"stage008","difficult","�A�X���`�b�N�A�X���`�b�N"}},
		{{6,1},{"stage006","difficult","���邮�邩���ނ�"}},
		{{6,-1},{"stage004","nomal","�҂��҂��Ԃ�Ԃ�"}},
		{{7,0},{"stage003","difficult","�ɂ񂶂�Ƃ��"}},
		{{7,-1},{"stage014","difficult","���ǂ�����"}},
		{{8,0},{"stage012","difficult","�̂ڂ�I"}},
	
		
		{{-1,1},{"save"}},
		{{0,-1},{"title"}},
		{{0,0},{"start"}},
	};

}