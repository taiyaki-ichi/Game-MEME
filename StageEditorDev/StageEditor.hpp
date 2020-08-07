#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include<unordered_map>

namespace StageEditor
{
	class ConsoleMessage;
	class SceneEditor;

	class StageEditor : public GameLib::Actor
	{
		ConsoleMessage* mConsoleMessage;

		SceneEditor* mNowSceneEditor;
		std::unordered_map<std::string, SceneEditor*> mSceneEditors;



	public:
		StageEditor(GameLib::Actor* actor);
		virtual ~StageEditor() = default;

		void CustomizeUpdate() override;


		//SceneEditor��������
		//LoadFunc�ł��g�p
		SceneEditor* AddScene(std::string&&);

	private:
		//�R���\�[���ւ̕`�ʂ��X�V�ASceneEditor��ActorEditor�ɓ`�d����
		//Scene�̏�Ԃ�Actor�̌�
		void UpdateConsoleScreen();

		//���݂̃f�[�^���t�@�C�����̏ꏊ�ɕۑ�
		void SaveStage(std::string&&);

		//�f�[�^�����[�h�Atest.json���X�V
		void LoadStage(std::string&&);

		//�R���\�[������̃��b�Z�[�W�̏���
		void ProcessMessage();

		//�폜
		void RemoveScene(std::string&&);
		//���ݕ\������Ă���Scene��ς���
		void ChangeScene(std::string&&);

		//�R�}���h�ꗗ�̕\��
		void Help();

	};

}