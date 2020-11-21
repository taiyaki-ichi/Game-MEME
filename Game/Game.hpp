#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameScene/GameData.hpp"

namespace Game
{
	class SceneBase;
	class RectCurtain;

	class Game : public GameLib::Actor
	{
		//���݂̃V�[��
		SceneBase* mNowScene;

		//�L�^
		GameData mGameData;

		//�V�[���J�ڗp
		RectCurtain* mRectCurtain;

	public:
		Game(GameLib::Actor*);

		void CustomizeUpdate() override;

	private:

		//StageChangeFlag�����������̏���
		//������
		void GoStage();
		void GoTitle();
		void GoStageSelect();
		void GoStageSelectFromTitle();
		void StageClear();
		void MissStage();
		void GoStageSelectFromZero();
		void GoGameClear();

		//TitleScene�p
		int GetStarNum();


	};
}