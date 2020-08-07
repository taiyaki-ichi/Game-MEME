#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace StageEditor
{
	class SceneEditor : public GameLib::Actor
	{

	public:
		SceneEditor(GameLib::Actor* actor);
		virtual ~SceneEditor() = default;


		//Actor�̐���
		void CreateActor(std::string&&);

		//Actor��ҏW�����ǂ���
		bool IsEdtingActor();

		//�ҏW���̎���Actor�ɕ�����̏���n��
		void MessageToActor(std::string&&);

		//Invoke�g��
		void BeginWorking();
		void BeginToRest();

		//�ҏW����Actor�̏��̕\��
		void UpdateConsoleScreen();
	};

}