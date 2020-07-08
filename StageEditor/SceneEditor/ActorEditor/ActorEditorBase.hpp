#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/CollisionDetection/Collider.hpp"
#include"PosInfo/PosInfoUtility.hpp"
#include<vector>

namespace StageEditor
{
	class PosInfo;
	class SceneEditor;

	struct ActorData {
		std::string mActorName;
		std::vector<float> mData;
	};

	class ActorEditorBase : public GameLib::Actor
	{
		std::string mActorName;

		std::vector<PosInfo*> mPosInfos;
		int mPosInfoNum;

	protected:
		const std::vector<PosInfo*>& GetPosInfos();

		//�폜����Ƃ��Ƃ��Ɏg��
		GameLib::Collider mDefaultCollider;

	public:
		//posNum�͂P�ȏ�
		ActorEditorBase(SceneEditor* owner, std::string&& nameTag, int posInfoNum);
		virtual ~ActorEditorBase();

		//PosInfo�ւ̓���
		void CustomizeUpdate() override final;

		virtual void ActorEditorUpdate() {}

		//PosInfo���L���Ȓl�����������ǂ���
		bool IsOk();

		//Collider�ƕ`��̃R���g���[��
		virtual void Pause() = 0;
		virtual void Active() = 0;

		//json�ɏ������ނ悤
		ActorData GetData();

		//json����ǂݍ��ނƂ��p
		void SetData(std::vector<float>&& data);
	};
}