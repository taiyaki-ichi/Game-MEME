#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<string>

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

		Stage(GameLib::Actor* game,std::string&& stageDataFileName);
		virtual ~Stage() = default;

		//Pause�̐���
		void CustomizeUpdate() override;

		//Pause����̒ʒm�p,�t���O�𗧂Ă�
		void ReturnToTitle();

		bool CheckFlag(char);
	};
}