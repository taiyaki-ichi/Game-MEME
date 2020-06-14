#include"lib/src/CollisionDetection/ColliderManager.hpp"
#include"lib/include/CollisionDetection/Collider.hpp"
#include"lib/src/CollisionDetection/MortonNumber.hpp"
#include"lib/src/CollisionDetection/SpaceDivisionTree.hpp"

namespace GameLib
{
	std::list<LinerObject<Collider>> ColliderManager::mColliders;

	void ColliderManager::Add(Collider* collider)
	{
		
		mColliders.emplace_back(LinerObject(collider));
		
	}
	void ColliderManager::Remove(Collider* collder)
	{
		auto iter = mColliders.begin();
		for (; iter != mColliders.end(); iter++)
			if (iter->GetPtr() == collder)
				break;

		if (iter != mColliders.end())
			mColliders.erase(iter);
	}
	void ColliderManager::RegistSpaceDivisionTree(SpaceDivisionTree<Collider>& tree)
	{
		for (auto& linerObj : mColliders) {
			linerObj.RemoveSpaceCell();

			auto collider = linerObj.GetPtr();
			float scale = collider->GetScale();
			float width = collider->GetWidth() * scale;
			float heigth = collider->GetHeigth() * scale;
			auto pos = collider->GetPosition();

			//squrt使って精密にやるか？？
			float halfUnitSize = std::sqrt(width * width + heigth * heigth) / 2.f;

			int spaceCellNum = GetMortonNumber(pos.x - halfUnitSize, pos.y - halfUnitSize, pos.x + halfUnitSize, pos.y + halfUnitSize);

			//std::cout << collider->GetNameTag() << " : " << spaceCellNum << "\n";

			if (0 <= spaceCellNum && spaceCellNum < MAX_SPACECELL_NUM)
				tree.Regist(&linerObj, spaceCellNum);
		}
	}
}