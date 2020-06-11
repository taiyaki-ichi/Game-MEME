#pragma once
#include<list>
#include<algorithm>
#include<iostream>
#include"ManagerPolicy.hpp"

namespace GameLib
{

	template<typename T,typename DestructorPolicy>
	class ManagerBase;

	//����Manager�̃f�X�g���N�^���Ă΂ꂽ�ۃR���e�i���ɂ���|�C���^�̊J�����S��
	template<typename T>
	using OwnerManager = ManagerBase<T, OwnerManagerDestructorPolicy<T>>;

	//����Manager�̃f�X�g���N�^���Ă΂�Ă��R���e�i�ɂ���|�C���^�͊J������Ȃ�
	template<typename T>
	using WeakManager = ManagerBase<T, WeakManagerDestructorPolicy<T>>;



	template<typename T,typename DestructorPolicy>
	class ManagerBase
	{

		std::list<Node<T>> mNodes;


	public:
		ManagerBase() = default;
		virtual ~ManagerBase() {
			DestructorPolicy()(std::move(mNodes));
		}

		//���Ԏw��
		void Add(Node<T>&& node) {

			auto iter = mNodes.begin();
			for (; iter != mNodes.end(); iter++)
				if (node.Order < iter->Order)
					break;
			mNodes.insert(iter, node);
		}

		//�w�肵�Ȃ��ꍇ�A���Ԃ�0
		void Add(T* ptr) {
			Add({ ptr,0 });
		}

		template<typename U,typename RemovePolicy=DefaltRemovePolicy<U>>
		void Remove(U* ptr) {
			auto iter = mNodes.begin();
			for (; iter != mNodes.end(); iter++)
				if (RemovePolicy()(ptr,iter->Ptr))
					break;
			if (iter!=mNodes.end())
				mNodes.erase(iter);
		}

		template<typename Policy>
		void Invoke() {
			auto iter = mNodes.begin();
			while (iter != mNodes.end()) {
				if (iter->Ptr) {
					Policy()(iter->Ptr);
					iter++;
				}
				else
					iter = mNodes.erase(iter);
			}
			
		}

		void SetOrder(T* ptr, int order) {
			Remove(ptr);
			Add({ ptr,order });
		}

	};


}