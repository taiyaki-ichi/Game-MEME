#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<unordered_map>
#include"SceneEditor/SceneEditor.hpp"

namespace StageEditor
{
	class SceneEditor;
	class EditorCamera;

	class StageEditor : public GameLib::Actor
	{
		
		std::string mStageName;
		
		SceneEditor* mNowEditingScene;
		std::unordered_map<std::string, SceneEditor*> mStageScenes;

		EditorCamera* mCamera;

		void DeleteScene(const std::string& sceneName);
		void ChangeScene(const std::string& sceneName);

		int mPlayerNum;

		void PrintStageInfo();

		bool mReDrawFlag;

	public:
		StageEditor(GameLib::Actor* owner);
		virtual ~StageEditor() = default;

		//�Z�[�u�A���[�h�AScene�̒ǉ��폜�A���ݕҏW���̃V�[���̕ύX
		void CustomizeUpdate() override;


		SceneEditor* AddScene(const std::string& sceneName);

		void IncrementSumNum(const std::string& actorName);
		void DecrementSumNum(const std::string& actorName);
		void ResetSumNum();
	};
}