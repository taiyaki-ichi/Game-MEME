#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<unordered_map>
#include"ActorEditor/ActorEditorBase.hpp"

namespace StageEditor
{
	class ActorEditorBase;

	using ActorData = std::unordered_map<std::string, Datas>;

	class SceneEditor : public GameLib::Actor
	{

		//���ݕҏW����Actor�����邩�ǂ����̔���Ɏg�p
		ActorEditorBase* mNowEditingActor;
		//ActorEditor�ւ̎Q��
		std::vector<ActorEditorBase*> mActorEditors;

	public:
		SceneEditor(GameLib::Actor* owenr);
		virtual ~SceneEditor() = default;

		//ActorEditor�̍쐻
		void CustomizeUpdate() override;

		//ActorEditorBase���Ŏg�p
		void AddActorEditor(ActorEditorBase* actor);
		void RemoveActorEditor(ActorEditorBase* actor);

		ActorData GetData();

		void Active();
		void Pause();

		//����Actor��ҏW�����ǂ���
		bool IsNowEditingActor();
	};
}