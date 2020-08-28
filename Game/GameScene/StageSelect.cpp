#include"StageSelect.hpp"
#include"StageSelect/StageSelectParam.hpp"
#include"StageStateFlag.hpp"
#include"StageSelect/HexChip/HexChip.hpp"
#include"StageSelect/ChoiceIcon.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"
#include"StageSelect/HexChip/ToVector2.hpp"
#include"GameSceneFlag.hpp"
#include"StageDataParam.hpp"

namespace Game
{
	StageSelect::StageSelect(GameLib::Actor* actor,const GameData& gameData,
		const std::unordered_map<HexVec, std::vector<std::string>>& stageData)
		:SceneBase{ actor ,gameData}
		, mStageData{stageData}
		, mChoiceIcon{ nullptr }
		, mStageNameDisplay{ StageSelectParam::STAGENAME_DISPLAY_POSITION,GameLib::Font::Size::Size_48 }
		, mStageLevelDisplay{ StageSelectParam::LEVEL_DISPLAY_POSITION,GameLib::Font::Size::Size_36 }
		, mTearGemDisplay{ StageSelectParam::TEARGEM_DIPLAY_POSITION }
		, mGemDisplay{ StageSelectParam::GEM_NUM_POSITION,gameData.mPlayerGemNum }
		, mLifeDisplay{ StageSelectParam::LIFE_NUM_POSITION,gameData.mPlayerLifeNum }
	{

		for (const auto& stageDataTmp : mStageData)
		{
			auto saveDataIter = mGameData.mSaveData.find(stageDataTmp.first);
			//特別なマスの場合
			if (stageDataTmp.second.size() == 1)
			{
				//仮
				if (stageDataTmp.second[0] == "start")
					new HexChip{ this,stageDataTmp.first.x,stageDataTmp.first.y,"../Assets/StageSelect/hex.png" };
				else if (stageDataTmp.second[0] == "save")
					new HexChip{ this,stageDataTmp.first.x,stageDataTmp.first.y,"../Assets/StageSelect/hex.png" };
				else if (stageDataTmp.second[0] == "title")
					new HexChip{ this,stageDataTmp.first.x,stageDataTmp.first.y,"../Assets/StageSelect/hex.png" };

			}
			//saveDataが存在する場合、つまり進むことできる通常のマス
			else if (saveDataIter != mGameData.mSaveData.end())
			{
				if (saveDataIter->second & StageStateFlag::CLEAR_FLAG)
					new HexChip{ this,stageDataTmp.first.x,stageDataTmp.first.y,"../Assets/StageSelect/clear_hex.png" };
				else //if(saveDataIter->second & StageSelectFlag::OPEN_FLAG)
					new HexChip{ this,stageDataTmp.first.x,stageDataTmp.first.y,"../Assets/StageSelect/circle_hex.png" };
			}
			//クリアできてない進むことができないマス
			else
			{
				new HexChip{ this,stageDataTmp.first.x,stageDataTmp.first.y,"../Assets/StageSelect/batu_hex.png" };
			}
		}

		mChoiceIcon = new ChoiceIcon{ this };
		CheckposAndUpdateDisplay(mGameData.mNowPos);

		AdjustDisplayPos();
	}

	void StageSelect::CustomizeUpdate()
	{
		if (CheckFlag(SceneFlag::SAVE_FLAG))
			DownFlag(SceneFlag::SAVE_FLAG);

		auto pos = mGameData.mNowPos;
		GameLib::Viewport::SetPos(ToVector2(pos.x, pos.y));

		auto addPairVec = GetPairVecPerFrame();
		//0,0は絶対進める
		if (addPairVec != HexVec{ 0,0 })
		{
			pos = pos + addPairVec;
			CheckposAndUpdateDisplay(pos);
		}

		AdjustDisplayPos();

		if (GameLib::InputState::GetState(GameLib::Key::Space) == GameLib::ButtonState::Pressed)
			PressedSpace();
	}

	const HexVec& StageSelect::GetPairVecPerFrame()
	{
		if (GameLib::InputState::GetState(GameLib::Key::E) == GameLib::ButtonState::Pressed)
			return DIR_E;
		if (GameLib::InputState::GetState(GameLib::Key::D) == GameLib::ButtonState::Pressed)
			return DIR_D;
		if (GameLib::InputState::GetState(GameLib::Key::X) == GameLib::ButtonState::Pressed)
			return DIR_X;

		if (GameLib::InputState::GetState(GameLib::Key::Z) == GameLib::ButtonState::Pressed)
			return DIR_Z;
		if (GameLib::InputState::GetState(GameLib::Key::A) == GameLib::ButtonState::Pressed)
			return DIR_A;
		if (GameLib::InputState::GetState(GameLib::Key::W) == GameLib::ButtonState::Pressed)
			return DIR_W;

		return { 0,0 };
	}

	void StageSelect::CheckposAndUpdateDisplay(const HexVec& pos)
	{
		auto saveDataIter = mGameData.mSaveData.find(pos);
		auto stageDataIter = mStageData.find(pos);

		//stringのvectorのサイズが１の時は特別なマス、必ず通れる
		if (stageDataIter != mStageData.end() && stageDataIter->second.size() == 1)
		{
			mStageNameDisplay.SetText(stageDataIter->second[0]);
			mStageLevelDisplay.SetText("");
			mTearGemDisplay.NotDrawing();

			mChoiceIcon->SetPosision(pos.x, pos.y);
			mGameData.mNowPos = pos;
		}
		//セーブデータに記載されている
		//つまり、クリアしたか進むことができるかの時
		else if (saveDataIter != mGameData.mSaveData.end() && stageDataIter != mStageData.end())
		{
			mStageNameDisplay.SetText(stageDataIter->second[2]);
			mStageLevelDisplay.SetText("level : " + stageDataIter->second[1]);

			mTearGemDisplay.SetFrame();
			if (saveDataIter->second & StageStateFlag::TEARGEM1_FLAG)
				mTearGemDisplay.SetTearGem(1);
			if (saveDataIter->second & StageStateFlag::TEARGEM2_FLAG)
				mTearGemDisplay.SetTearGem(2);
			if (saveDataIter->second & StageStateFlag::TEARGEM3_FLAG)
				mTearGemDisplay.SetTearGem(3);

			mChoiceIcon->SetPosision(pos.x, pos.y);
			mGameData.mNowPos = pos;
		}
	}

	void StageSelect::AdjustDisplayPos()
	{
		mStageNameDisplay.AdjustPos();
		mStageLevelDisplay.AdjustPos();
		mGemDisplay.AdjustPos();
		mTearGemDisplay.AdjustPos();
		mLifeDisplay.AdjustPos();
	}

	void StageSelect::PressedSpace()
	{
		auto stageDataIter = mStageData.find(mGameData.mNowPos);
		if (stageDataIter != mStageData.end())
		{
			//普通のステージの場合
			if (stageDataIter->second.size() == StageDataParam::STAGE_STRING_NUM)
			{
				UpFlag(SceneFlag::GO_STAGE_FLAG);
			}
			//セーブ
			else if (stageDataIter->second.size() == 1 && stageDataIter->second[0] == "save")
			{
				UpFlag(SceneFlag::SAVE_FLAG);
			}
			else if (stageDataIter->second.size() == 1 && stageDataIter->second[0] == "title")
			{
				UpFlag(SceneFlag::GO_TITLE_FLAG);
			}
		}
	}

}