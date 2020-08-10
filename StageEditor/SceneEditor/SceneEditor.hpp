#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include"BeginPolicy.hpp"
#include"ActorEditor/ActorData.hpp"
#include"ActorEditor/ActorEditorBase.hpp"

namespace StageEditor
{
	class ActorEditorBase;

	class SceneEditor : public GameLib::Actor
	{
		ActorEditorBase* mNowActorEditor;

	public:
		SceneEditor(GameLib::Actor* actor);
		virtual ~SceneEditor() = default;

		void CustomizeUpdate() override;

		//Actor�̐���
		void CreateActor(std::string&&);

		//Actor��ҏW�����ǂ���
		bool IsEdtingActor();

		//�ҏW���̎���Actor�ɕ�����̏���n��
		void ForwardStringData(std::string&&);

		//Invoke�g��
		void BeginWorking() {
			InvokeActors<BeginWorkingPolicy>();
		}
		void BeginToRest() {
			InvokeActors<BeginToRestPolicy>();
		}

		//�ҏW����Actor�̏��̕\��
		void UpdateConsoleScreen();

		std::vector<ActorData> GetData()
		{
			std::vector<ActorData> data{};
			auto func = [&data](GameLib::Actor* actor) {
				auto ptr = static_cast<ActorEditorBase*>(actor);
				data.emplace_back(ptr->GetData()); 
			};
			mOwnedActors.For_Each(func);

			return data;
		}

	};

}