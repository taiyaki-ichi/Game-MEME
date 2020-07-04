#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<unordered_map>

namespace StageEditor
{
	class ActorEditorBase;
	struct ActorData;

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

		std::vector<ActorData> GetActorDataObject();

		void Active();
		void Pause();

		//����Actor��ҏW�����ǂ���
		bool IsNowEditingActor();
	};
}