#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<vector>
#include<array>
#include<string>

namespace Game::Stage
{
	namespace Player {
		class Actor;
	}
	namespace BackGround {
		class SlideObjectBase;
	}
}

namespace Game::StageSelect
{
	constexpr int STAGE_NUM = 2;

	class WarpBox;
	class StageNumChangeBox;

	using StageWarpBoxs = std::vector<WarpBox*>;
	using BackGrounds = std::vector<Stage::BackGround::SlideObjectBase*>;

	//�Q�[���̐i�������[�h������
	class StageSelect : public GameLib::Actor
	{
		std::vector<BackGrounds> mBackGround;
		std::vector<StageWarpBoxs> mStageWarpBox;

		StageNumChangeBox* mStageNumChangeBox;

		int mGoStageFlag;

		Stage::Player::Actor* mPlayer;

	public:
		StageSelect(GameLib::Actor* owner);
		virtual ~StageSelect() = default;

		//GoStageFlag��0�ȊO�̗L���Ȓl�Ȃ�΂���Stage�ֈړ�
		void CustomizeUpdate() override;

		void GoStage(int stageNum);

		void ChangeStageNum(int num);
	};


}