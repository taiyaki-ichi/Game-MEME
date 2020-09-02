#pragma once
#include"GameLib/include/Actor/RootActor.hpp"
#include"GameScene/GameData.hpp"

namespace Game
{
	class SceneBase;
	class RectCurtain;

	class Game : public GameLib::RootActor
	{
		//���݂̃V�[��
		SceneBase* mNowScene;

		//�L�^
		GameData mGameData;

		//�V�[���J�ڗp
		RectCurtain* mRectCurtain;

	public:
		Game();

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
		


	};
}