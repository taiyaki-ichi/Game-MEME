#include"StageEditor.hpp"
#include"SceneEditor/SceneEditor.hpp"
#include"Console/ConsoleMessage.hpp"
#include"GameLib/include/InputState/InputState.hpp"
#include"Utility/EditorCamera.hpp"
#include"Utility/ClickManager.hpp"
#include"Utility/Cursor.hpp"
#include"FileFunc.hpp"
#include"GameLib/include/CollisionDetection/CollisionDetectionSetting.hpp"
#include"GameLib/include/Viewport/Viewport.hpp"

namespace StageEditor
{

	StageEditor::StageEditor(GameLib::Actor* owner)
		:GameLib::Actor{owner}
		, mNowEditingScene{nullptr}
		,mStageScenes{}
		, mStageName{""}
		, mPlayerNum{0}
		, mReDrawFlag{false}
	{

		mCamera = new EditorCamera(this);
		mCamera->Reset();
		new Cursor(this);
		new ClickManager(this);

		LoadStageData(this, "test.json");
		PrintStageInfo();

	}

	SceneEditor* StageEditor::AddScene(const std::string& sceneName)
	{
		auto ptr = new SceneEditor(this);
		mStageScenes.emplace(sceneName, ptr);
		if (mNowEditingScene == nullptr) {
			mNowEditingScene = mStageScenes.begin()->second;
			mNowEditingScene->Active();
		}

		return ptr;

	}

	void StageEditor::IncrementSumNum(const std::string& actorName)
	{
		if (actorName == "Player")
			mPlayerNum++;


		mReDrawFlag = true;
	}
	void StageEditor::DecrementSumNum(const std::string& actorName)
	{
		if (actorName == "Player")
			mPlayerNum--;

		mReDrawFlag = true;
	}
	void StageEditor::ResetSumNum()
	{
		mPlayerNum = 0;

		mReDrawFlag = true;

	}
	void StageEditor::DeleteScene(const std::string& sceneName)
	{
		auto i = mStageScenes.find(sceneName);
		if (i != mStageScenes.end()) {
			i->second->SetState(GameLib::Actor::State::Dead);
			auto ptr = i->second;
			mStageScenes.erase(i);

			if (ptr == mNowEditingScene) {
				if (mStageScenes.size() > 0) {
					mNowEditingScene = mStageScenes.begin()->second;
					mNowEditingScene->Active();
					mCamera->Reset();
				}
				else
					mNowEditingScene = nullptr;
			}	
		}
	}
	void StageEditor::ChangeScene(const std::string& sceneName)
	{
		auto i = mStageScenes.find(sceneName);
		if (i != mStageScenes.end() && !mNowEditingScene->IsNowEditingActor()) {
			mNowEditingScene->Pause();
			mNowEditingScene = i->second;
			mNowEditingScene->Active();
			mCamera->Reset();
		}
	}
	void StageEditor::PrintStageInfo()
	{
		std::system("cls");

		std::cout << "Stage\n";
		if (mStageName.size() == 0)
			std::cout << " Name: --- \n";
		else
			std::cout << " Name: " << mStageName << "\n";


		std::cout << " Scene:\n";
		for (auto iter = mStageScenes.begin(); iter != mStageScenes.end(); iter++) {
			std::cout << "  |- " << iter->first;
			if (iter->second == mNowEditingScene)
				std::cout << " <-Now!!!";
			std::cout << "\n";
		}
		std::cout << "\n";

		std::cout << "PlayerNum: " << mPlayerNum << "\n";

		std::cout << ">";
	}

	void StageEditor::CustomizeUpdate()
	{
		GameLib::CollisionDetectionSetting::SetPos(GameLib::Viewport::GetPos());

		auto strings = ConsoleMessage::GetStrings();

		if (strings.size() == 3 && strings[1] == "scene") {
			if (strings[0] == "add")
				AddScene(strings[2]);
			else if (strings[0] == "change")
				ChangeScene(strings[2]);
			else if (strings[0] == "delete")
				DeleteScene(strings[2]);
		}

		if (strings.size() == 3 && strings[0] == "set" && strings[1] == "StageName")
			mStageName = strings[2];
			

		if (strings.size() > 0 || mReDrawFlag)
			PrintStageInfo();

		
		if (GameLib::InputState::GetState(GameLib::Key::RightShift) == GameLib::ButtonState::Pressed) {
			std::unordered_map<std::string, std::vector<ActorData>> tmp{};
			for (auto iter = mStageScenes.begin(); iter != mStageScenes.end(); iter++)
				tmp.emplace(iter->first, iter->second->GetData());
			SaveStageData(mStageName, std::move(tmp), "test.json");
		}
		
		mReDrawFlag = false;

	}
}