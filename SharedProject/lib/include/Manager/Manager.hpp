#pragma once
#include<vector>
#include<algorithm>
#include<iostream>
#include"DestructorPolicy.hpp"

namespace GameLib
{

	template<typename T,typename Policy>
	class ManagerBase;

	//�|�C���^�����L���Ă���AManager�̃f�X�g���N�^���Ń|�C���^���J��
	template<typename T>
	using OwnerManager = ManagerBase<T, OwnerManagerDestructorPolicy<T>>;

	//�|�C���^�����L���Ă��Ȃ��A�Q�Ƃ̂�
	//�f�X�g���N�^���Ăяo����Ă��|�C���^�͊J������Ȃ�
	template<typename T>
	using WekManager = ManagerBase<T, WeakManagerDestructorPolicy<T>>;



	template<typename T,typename DestructorPolicy>
	class ManagerBase
	{

		std::vector<Node<T>> mNodes;


	public:
		ManagerBase() = default;
		virtual ~ManagerBase() {
			DestructorPolicy()(std::move(mNodes));
		}

		//���ԕt��
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

		void Remove(T* ptr) {
			auto iter = mNodes.begin();
			for (; iter != mNodes.end(); iter++)
				if (ptr == iter->Ptr)
					break;
			if (iter!=mNodes.end())
				mNodes.erase(iter);
		}

		template<typename Policy>
		void Invoke() {
			for (auto iter = mNodes.begin(); iter != mNodes.end(); iter++) {
				if (iter->Ptr)
					Policy()(iter->Ptr);
				else
					mNodes.erase(iter);
			}
			
		}

		void SetOrder(T* ptr, int order) {
			Remove(ptr);
			Add({ ptr,order });
		}

	};


}