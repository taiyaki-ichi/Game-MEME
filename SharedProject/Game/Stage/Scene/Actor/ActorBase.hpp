#pragma once
#include"GameLib/include/Actor/Actor.hpp"

namespace Game::Stage
{
	class Scene;

	class ActorBase : public GameLib::Actor
	{
	public:
		ActorBase(Scene* scene, std::vector<float>&& initData = {}, int updateOrder = 0);
		virtual ~ActorBase();

		void CustomizeUpdate() override final;

		//�X�V���邩�ǂ����AActor����ʊO�ŗ������Ȃ��悤�ɂ��邽�߂ȂǂɎg�p
		//�f�t�H���g��true��Ԃ�
		virtual bool UpdateOrNot();
		virtual void UpdateActor() {}

		//Collider��Draw�n�̃I���I�t
		virtual void Active() = 0;
		virtual void Pause() = 0;

		Scene* GetScene();
	};
}