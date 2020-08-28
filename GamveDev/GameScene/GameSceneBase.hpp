#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameData.hpp"

namespace Game
{
	class SceneBase : public GameLib::Actor
	{
	protected:
		GameData mGameData;

	private:
		unsigned int mFlag;
	protected:
		void UpFlag(unsigned int);
		void DownFlag(unsigned int);

	public:
		SceneBase(GameLib::Actor*, const GameData&);

		//�Q�[���f�[�^�̕ύX�𔽉f������K�v������Ƃ�
		//Game�N���X���Ăяo��
		const GameData& GetGameData() const;

		bool CheckFlag(unsigned int);
		//�ǂꂩ1�ł������Ă����true
		bool CheckFlag();
	};
}