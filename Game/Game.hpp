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
		//�Z�[�u�f�[�^
		//���ꃁ���o�ɂ���K�v���Ȃ�
		GameData Load();
		void Save(const GameData&);

		//StageChangeFlag�����������̏���
		void GoStage();
		void GoTitle();
		void GoStageSelect();
		void StageClear();
		void MissStage();
		


	};
}