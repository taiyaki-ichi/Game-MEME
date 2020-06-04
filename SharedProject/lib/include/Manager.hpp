#pragma once
#include<vector>

namespace GameLib
{

	template<typename T>
	struct Node {
		T* ptr;
		int order;
	};

	template<typename T>
	class Manager
	{

		std::vector<Node<T>> mNodes;


	public:

		~Manager() {
			for (auto node : mNodes)
				delete node.ptr;
			mNodes.clear();
		}

		//順番付き
		void Add(Node<T>&& node) {

			auto iter = mNodes.begin();
			for (; iter != mNodes.end(); iter++)
				if (node.order < iter->order)
					break;
			mNodes.insert(iter, node);
		}

		//指定しない場合、順番は0
		void Add(T* ptr) {
			Add({ ptr,0 });
		}

		void Remove(T* ptr) {
			auto iter = mNodes.begin();
			for (; iter != mNodes.end(); iter++)
				if (ptr == iter->ptr)
					break;
			if (iter!=mNodes.end())
				mNodes.erase(iter);
		}

		template<typename Policy>
		void Invoke() {
			for (auto node : mNodes)
				Policy::function(node.ptr);
		}
	};

}