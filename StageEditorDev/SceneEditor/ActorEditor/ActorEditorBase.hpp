#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"Data/Data.hpp"
#include"Data/PosData.hpp"
#include"ActorData.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"

namespace StageEditor
{


	class ActorEditorBase : public GameLib::Actor
	{
	protected:
		PosData mPosData;
		Data<std::string> mStringData;

		//�X�y�[�X�ō폜����p�̓����蔻��
		//�h���N���X�Ń^�e���R�ʒu�Ȃǂ�ݒ�
		GameLib::Collider mCollider;

	private:
		//���̖��O��Json�ɋL�q�����
		std::string mNameTag;

	public:
		ActorEditorBase(GameLib::Actor* actor, std::string&& nameTage, int posDataNum, int stringDataNum);
		virtual ~ActorEditorBase() = default;

		bool IsOK();

		void CustomizeUpdate() override final;
		virtual void Update() {};

		//SceneEditor���當���񂪑����Ă���
		void ForwardStringData(std::string&& str);
		
		//���͂��ꂽ�f�[�^�A���̃f�[�^�����Ԗڂɓ��͂���邩�̕\��
		void PrintStringData();
		//PrintStringData�̑O�ɌĂяo�����A���Ԗڂ̃f�[�^���Ȃ�̃f�[�^���̐����p
		virtual void PrintStringDataInfo() {};

		void BeginBeginWorking();
		void BeginBeginToRest();
		virtual void BeginWorking() = 0;
		virtual void BeginToRest() = 0;

		//json�t�@�C���쐬�p
		ActorData GetData();

		//loadStage�ŏ������̍ۂɎg�p
		void SetData(std::vector<float>&& floatData, std::vector<std::string>&& stringData);
	};


}