#pragma once
#include"GameSceneBase.hpp"
#include<unordered_map>
#include<vector>
#include<string>
#include"StageSelect/DataDisplay/StringDisplay.hpp"
#include"StageSelect/DataDisplay/TearGemDisplay.hpp"
#include"Stage/SceneManager/Scene/Actor/Player/ItemNum/GemDisplay.hpp"
#include"Stage/SceneManager/Scene/Actor/Player/ItemNum/LifeDisplay.hpp"
#include"Utility/HexVec.hpp"
#include"GameData.hpp"

namespace Game
{
	class ChoiceIcon;

	class StageSelect : public SceneBase
	{
		//�X�e�[�W�̏��A��������ƂɃ}�b�v��\��
		const std::unordered_map<HexVec, std::vector<std::string>> mStageData;

		//���݈ʒu��\��
		ChoiceIcon* mChoiceIcon;

		StringDisplay mStageNameDisplay;
		StringDisplay mStageLevelDisplay;
		TearGemDisplay mTearGemDisplay;

		::Stage::GemDisplay mGemDisplay;
		::Stage::LifeDisplay mLifeDisplay;

	public:
		//GameData�̂ق���StageData��Game������炤
		StageSelect(GameLib::Actor*,const GameData&,
			const std::unordered_map<HexVec, std::vector<std::string>>&);

		void CustomizeUpdate() override;


	private:
		const HexVec& GetPairVecPerFrame();

		//pos���`�F�b�N���L���Ȓl�̏ꍇchoiceIcon�̈ʒu��ύX�ADisplay�̒l�������J�G��
		void CheckposAndUpdateDisplay(const HexVec&);

		//Display������AdjustPos���Ăяo��
		void AdjustDisplayPos();

		//Stage�Ɉړ���Save���邩�Ƃ��̏���
		void PressedSpace();

	};
}