#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace StageEditor
{
	class ConsoleMessage;

	class StageEditor : public GameLib::Actor
	{
		//Actor��ҏW�����ǂ���
		//�ҏW���Ȃ�Scene�͕ύX�����Ȃ��AMessage��Actor�ɑ���
		bool mIsEditingActor;

		ConsoleMessage* mConsoleMessage;

	public:
		StageEditor(GameLib::Actor* actor);
		virtual ~StageEditor() = default;

		void CustomizeUpdate() override;

	private:


		//�R���\�[���ւ̕`�ʂ��X�V�ASceneEditor��ActorEditor�ɓ`�d����,ostream��n���H
		void UpdateConsoleScreen();

		//���݂̃f�[�^���t�@�C�����̏ꏊ�ɕۑ�
		void SaveStage(std::string);

		//�f�[�^�����[�h�Atest.json���X�V
		void LoadStage(std::string);

		//�R���\�[������̃��b�Z�[�W�̏���
		void ProcessMessage();


		//SceneEditor��������
		void AddScene(std::string);
		//�폜
		void RemoveScene(std::string);
		//���ݕ\������Ă���Scene��ς���
		void ChangeScene(std::string);



	};

}