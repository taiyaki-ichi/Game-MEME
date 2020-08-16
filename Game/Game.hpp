#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<unordered_map>
#include"StageSelect/HexVec.hpp"

namespace Stage
{
	class Stage;
}

namespace Game
{
	class Title;
	class StageSelect;
	class RectCurtain;

	class Game : public GameLib::Actor
	{
		Title* mTitle;
		StageSelect* mStageSelect;
		Stage::Stage* mStage;

		//nullptr���Ⴀ�Ȃ�����Ăяo��
		//����܂�悭�Ȃ���
		void UpdateTitle();
		void UpdateStageSelect();
		void UpdateStage();

		RectCurtain* mRectCurtain;

		//�Q�[���̃f�[�^����
		std::unordered_map<HexVec, unsigned char> mSaveData;
		int mPlayerLifeNum;
		int mPlayerGemNum;
		//StageSelect��Space�������ꂽ�Ƃ��X�V
		HexVec mPosition;

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