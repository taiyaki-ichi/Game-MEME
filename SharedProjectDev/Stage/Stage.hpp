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

		constexpr static char CLEAR_FLAG = 0b00000010;
		constexpr static char MISS_FLAG = 0b00000100;
		constexpr static char RETURN_TO_TITLE_FLAG = 0b00001000;

		Stage(GameLib::Actor* game,std::string&& stageDataFileName);
		virtual ~Stage() = default;

		//Pause�̐���
		void CustomizeUpdate() override;

		char GetFlags() const;

		//Pause����̒ʒm�p,�t���O�𗧂Ă�
		void ReturnToTitle();
	};
}