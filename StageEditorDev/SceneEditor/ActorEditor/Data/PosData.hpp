#pragma once
#include"GameLib/include/Math/Vector2.hpp"
#include<vector>

namespace StageEditor
{
	class PosData
	{
		int mSize;
		std::vector<GameLib::Vector2> mPosData;

		//�����̗v�f���m�肳�ꂽ�f�[�^���ǂ���
		bool mDefinedBackData;

	public:
		PosData(int size);
		virtual ~PosData() = default;

		//�����̗v�f���X�V
		void UpdatePosDataBack(GameLib::Vector2&& pos);

		//�����̗v�f���m�肳��
		void DefinePosDataBeck();

		//�f�[�^���m�肵�����ǂ���
		bool IsOK() const;

		int GetDataNum() const;

		const GameLib::Vector2& operator[](int n) const;
	};
}