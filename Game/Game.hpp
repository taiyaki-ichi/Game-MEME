#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<map>

namespace Stage
{
	class Stage;
}

namespace Game
{
	class Title;
	class StageSelect;

	class Game : public GameLib::Actor
	{
		Title* mTitle;
		StageSelect* mStageSelect;
		Stage::Stage* mStage;

		//nullptr���Ⴀ�Ȃ�����Ăяo��
		//����܂�悭�Ȃ�����
		void UpdateTitle();
		void UpdateStageSelect();
		void UpdateStage();

		//�Q�[���̃f�[�^����
		std::map<std::pair<int, int>, unsigned char> mSaveData;
		int mPlayerLifeNum;
		int mPlayerGemNum;
		//StageSelect��Space�������ꂽ�Ƃ��X�V
		std::pair<int, int> mPosition;

		//�t�@�C���ɏ������݁A��{�I��StageSelect����Ă΂��Ǝv��
		bool Save();

		//Game���������ꂽ�Ƃ��ɌĂяo����邩��
		bool Load();

	public:
		Game(GameLib::Actor*);
		virtual ~Game() = default;

		void CustomizeUpdate() override;
	};
}