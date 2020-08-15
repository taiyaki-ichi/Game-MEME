#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<string>
#include"SceneManager/Scene/Actor/Player/ItemNum/ItemNumData.hpp"
#include"GameLib/include/Math/Vector2.hpp"

namespace Stage
{
	class Pause;
	class SceneManager;

	class Stage : public GameLib::Actor
	{
		
		//�X�e�[�W��Object���ꊇ�ŊǗ�����
		//Pause�̎��Ƃ�
		SceneManager* mSceneManager;

		char mFlags;

	public:

		Stage(GameLib::Actor* game, std::string&& stageDataFileName, int playerLifeNum = 5, int playerGemNum = 10);
		virtual ~Stage() = default;

		//Pause�̐���
		void CustomizeUpdate() override;

		//Pause����̒ʒm�p,�t���O�𗧂Ă�
		void ReturnToTitle();

		bool CheckFlag(char);

		//�N���A���ɌĂяo���W�v
		ItemNumData GetItemNumData();
	};
}