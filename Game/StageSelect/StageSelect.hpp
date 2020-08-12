#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"PairVec.hpp"
#include<map>

namespace Game::StageSelect
{
	class ChoiceIcon;
	class LevelDisplay;

	class StageSelect : public GameLib::Actor
	{
		std::map<PairVec, int> mStageData;

		ChoiceIcon* mChoiceIcon;

		std::string mStageFileName;

		LevelDisplay* mLevelDisplay;

	public:
		//Game�����[�h�����N���A�̏��Ɋ�Â��ă}�b�v����
		//0:open 1:clear
		StageSelect(GameLib::Actor*, const std::map<PairVec, int>& data = { {std::make_pair(1,0),1},{std::make_pair(2,0),1},{std::make_pair(3,0),0} });
		virtual ~StageSelect() = default;

		void CustomizeUpdate() override;


		std::string GoStage();

	private:
		//�ʒu�̕ύX
		void UpdateChoiceIcon();
	};
}