#pragma once
#include<map>
#include<vector>
#include"StageData.hpp"
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Draw/DrawTexture.hpp"

namespace Game::StageSelect
{
	class PlayerIcon;

	//std::vector<GameLib::DrawTexture> mHexTextures;�����͂����Ő���
	class MapDrawer;

	class HexMap : public GameLib::Actor
	{
		std::map<std::pair<int,int>, StageData> mMap;

		//�ړ��ł��˂ǂ�������A�A�C�R���̏ꏊ�ɂ���ăJ�����ړ��A
		PlayerIcon* mPlayerIcon;

	public:
		//�R���X�g���N�^����Map�����A�ق��ł͓��ɉ������Ȃ�
		HexMap(GameLib::Actor*);

		//�ړ��A�Ƃ�
		void CustomizeUpdate() override;


	};
}