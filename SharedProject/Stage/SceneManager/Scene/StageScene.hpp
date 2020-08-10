#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"ActorInfo.hpp"
#include"StageActorPolicy.hpp"

namespace Stage
{
	class Player;
	class Camera;

	//���L����Acotr��StageActorBase�̔h���̂�
	//StageActorPolicy�g����������
	class Scene : public GameLib::Actor
	{

		Camera* mCamera;

	public:
		Scene(GameLib::Actor* manager);
		virtual ~Scene() = default;

		//Player�����̃V�[���ɏ������Ă���̂ł���΂���data��Player�ɓn��
		//�܂��A���̃V�[����Active��
		//Player�����Ȃ��Ȃ�ŏ���Pause
		void CreateActors(std::vector<ActorInfo>&& actorInfos,Player* player);

		void AdjustCameraPosiotion();

		void BeginWorking() {
			SetState(GameLib::Actor::State::Active);
			InvokeActors<BeginWorkingPolicy>();
		}
		void BeginToRest() {
			SetState(GameLib::Actor::State::Pause);
			InvokeActors<BeginToRestPolicy>();
		}

	
	};

}