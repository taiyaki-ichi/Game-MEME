#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<unordered_map>
#include<vector>
#include<string>
#include"DataDisplay/StringDisplay.hpp"
#include"DataDisplay/TearGemDisplay.hpp"
#include"Stage/SceneManager/Scene/Actor/Player/ItemNum/GemDisplay.hpp"
#include"Stage/SceneManager/Scene/Actor/Player/ItemNum/LifeDisplay.hpp"
#include"HexVec.hpp"

namespace Stage
{
	class GemDisplay;
	class LifeDisplay;
}

namespace Game
{
	class ChoiceIcon;

	class StageSelect : public GameLib::Actor
	{
		//���W����X�e�[�W�̃f�[�^�ł���string�ƃN���A�󋵂�����char
		std::unordered_map<HexVec, std::pair<std::vector<std::string>, unsigned char>> mStageData;

		//���݈ʒu��\��
		ChoiceIcon* mChoiceIcon;

		StringDisplay mStageNameDisplay;
		StringDisplay mStageLevelDisplay;
		TearGemDisplay mTearGemDisplay;

		Stage::GemDisplay mGemDisplay;
		Stage::LifeDisplay mLifeDisplay;

		bool mChoiceIconStopFlag;

	public:
		//2��map����mStageData���쐬���Ȃ���}�b�v��`�ʂ��Ă���
		StageSelect(GameLib::Actor*, 
			const std::unordered_map<HexVec, unsigned char>&,
			const std::unordered_map<HexVec, std::vector<std::string>>&,
			const HexVec& nowPos,int lifeNum, int gemNum);

		void CustomizeUpdate() override;

		//Space�������ꂽ�Ƃ�Game����Ăяo�����
		const HexVec& GetChoicePos()const;

		void ChoiceIconStop();


	private:
		const HexVec& GetPairVecPerFrame();

		//pos���`�F�b�N���L���Ȓl�̏ꍇchoiceIcon�̈ʒu��ύX�ADisplay�̒l�������J�G��
		void CheckposAndUpdateDisplay(const HexVec& pos);

		//Display������AdjustPos���Ăяo��
		void AdjustDisplayPos();

	};
}