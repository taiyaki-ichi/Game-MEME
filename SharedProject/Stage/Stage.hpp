#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<string>
#include"SceneManager/Scene/Actor/Player/ItemNum/ItemNumData.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"BackGroundType.hpp"

namespace Stage
{
	class Pause;
	class SceneManager;

	class Stage : public GameLib::Actor
	{
		
		//�X�e�[�W��Object���ꊇ�ŊǗ�����
		//Pause�̎��Ƃ�
		SceneManager* mSceneManager;

		unsigned char mFlags;

	public:

		Stage(GameLib::Actor* game, std::string&& stageDataFileName, int playerLifeNum = 5, int playerGemNum = 10,const BackGroundType& bgType = BackGroundType::SharpTreeForest);
		virtual ~Stage() = default;

		//Pause�̐���
		void CustomizeUpdate() override;

		bool CheckFlag(char);

		//�N���A���ɌĂяo���W�v
		ItemNumData GetItemNumData();
	};
}