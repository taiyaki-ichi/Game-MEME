#pragma once
#include"Manager.hpp"

namespace GameLib
{

	class Component;


	struct ActorInfo;


	class Actor
	{
	public:
		Actor(Actor* owner) 
			:mOwner(owner)
		{
			//updateOrder�𓱓����邩
			owner->Add(this);
		}
		virtual ~Actor() {
			mOwner->Remove(this);
		}

		virtual void Update() {

		}

		//ActorInfo�o�R�ŏ�ԕύX�H�H�߂�ǂ����B�B


		void Add(Actor*);
		void Add(Component*);
		void Remove(Actor*);
		void Remove(Component*);


	private:
		Actor* mOwner;

		Manager<Actor>* mOwnedActors;
		Manager<Component>* mComponent;

		ActorInfo* mActorInfo;

		
	};

}