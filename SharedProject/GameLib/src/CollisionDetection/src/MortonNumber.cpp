#include"GameLib/src/CollisionDetection/MortonNumber.hpp"
#include"GameLib/src/CollisionDetection/CollisionDetectionSettingImpl.hpp"
#include"GameLib/src/CollisionDetection/CollsionDetectionData.hpp"

namespace GameLib
{
	// �r�b�g����
	inline DWORD BitSeparate32(DWORD n)
	{
		n = (n | (n << 8)) & 0x00ff00ff;
		n = (n | (n << 4)) & 0x0f0f0f0f;
		n = (n | (n << 2)) & 0x33333333;
		return (n | (n << 1)) & 0x55555555;
	}

	// 2D���[�g����Ԕԍ��Z�o�֐�
	inline WORD Get2DMortonNumber(WORD x, WORD y)
	{
		return (WORD)(BitSeparate32(x) | (BitSeparate32(y) << 1));
	}

	// ���W�����`4���ؗv�f�ԍ��ϊ��֐�
	inline DWORD GetPointElem(float pos_x, float pos_y)
	{
		float left = CollisionDetectionSettingImpl::GetLeft();
		float top = CollisionDetectionSettingImpl::GetTop();
		float unitW = CollisionDetectionSettingImpl::GetUnitWidth();
		float unitH = CollisionDetectionSettingImpl::GetUnitHeigth();
		return Get2DMortonNumber((WORD)((pos_x - left) / unitW), (WORD)((pos_y - top) / unitH));
	}

	DWORD GetMortonNumber(float left, float top, float right, float bottom)
	{
		// �ŏ����x���ɂ�����e���ʒu���Z�o
		DWORD LT = GetPointElem(left, top);
		DWORD RB = GetPointElem(right, bottom);

		// ��Ԕԍ��̔r���I�_���a����
		// �������x�����Z�o
		DWORD Def = RB ^ LT;
		unsigned int HiLevel = 0;
		unsigned int i;
		for (i = 0; i < TREE_LEVEL; i++)
		{
			DWORD Check = (Def >> (i * 2)) & 0x3;
			if (Check != 0)
				HiLevel = i + 1;
		}
		DWORD SpaceNum = RB >> (HiLevel * 2);
		DWORD AddNum = (POWER_OF_FOUR[TREE_LEVEL - HiLevel] - 1) / 3;
		SpaceNum += AddNum;

		if (SpaceNum > MAX_SPACECELL_NUM)
			return 0xffffffff;

		return SpaceNum;
	}

}