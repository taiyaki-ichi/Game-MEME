#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<map>
#include<vector>
#include<string>
#include"DataDisplay/StringDisplay.hpp"
#include"DataDisplay/TearGemDisplay.hpp"
#include"Stage/SceneManager/Scene/Actor/Player/ItemNum/GemDisplay.hpp"
#include"Stage/SceneManager/Scene/Actor/Player/ItemNum/LifeDisplay.hpp"

namespace Game
{
	class ChoiceIcon;

	class StageSelect : GameLib::Actor
	{
		//���W����X�e�[�W�̃f�[�^�ł���string�ƃN���A�󋵂�����char
		std::map<std::pair<int, int>, std::pair<std::vector<std::string>, unsigned char>> mStageData;

		//���݈ʒu��\��
		ChoiceIcon* mChoiceIcon;

		StringDisplay mStageNameDisplay;
		StringDisplay mStageLevelDisplay;
		TearGemDisplay mTearGemDisplay;

		Stage::GemDisplay mGemDisplay;
		Stage::LifeDisplay mLifeDisplay;


	public:
		//2��map����mStageData���쐬���Ȃ���}�b�v��`�ʂ��Ă���
		StageSelect(GameLib::Actor*, 
			const std::map<std::pair<int, int>, unsigned char>&,
			const std::map<std::pair<int, int>, std::vector<std::string>>&,
			std::pair<int, int>&& nowPos,int lifeNum, int gemNum);

		void CustomizeUpdate() override;

		//Space�������ꂽ�Ƃ�Game����Ăяo�����
		const std::pair<int,int>& GetChoicePos();


	private:
		const std::pair<int,int>& GetPairVecPerFrame();

		//pos���`�F�b�N���L���Ȓl�̏ꍇchoiceIcon�̈ʒu��ύX�ADisplay�̒l�������J�G��
		void CheckposAndUpdateDisplay(std::pair<int,int>&& pos);

		//Display������AdjustPos���Ăяo��
		void AdjustDisplayPos();

	};
}