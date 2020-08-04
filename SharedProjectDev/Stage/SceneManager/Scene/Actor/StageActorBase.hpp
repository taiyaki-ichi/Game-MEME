#pragma once
#include"GameLib/include/Actor/Actor.hpp"
#include"GameLib/include/Math/Vector2.hpp"
#include<vector>
#include<unordered_map>
#include<string>

namespace Stage
{
	class ActorBase : public GameLib::Actor
	{
	protected:
		//�R���X�g���N�^���ł͎g���Ȃ�
		const GameLib::Vector2& GetPlayerPos() const;

	public:

		ActorBase(GameLib::Actor* owner);
		virtual ~ActorBase() = default;

		void CustomizeUpdate() override final;

		//�X�V���邩�ǂ����AActor����ʊO�ŗ������Ȃ��悤�ɂ��邽�߂ȂǂɎg�p
		//�f�t�H���g�̓X�e�[�W����]���o�Ȃ���΍X�V
		virtual bool UpdateOrNot() {
			return StageIsNotRotation();
		}

		//UpdateOrNot��true�̎�CustomizeUpdate���ŌĂяo�����
		virtual void Update() {}

		virtual void Active() = 0;
		virtual void Pause() = 0;

		virtual void LoadData(std::vector<float>&& data) = 0;


	private:
		//UpdateOrNot�Ŏg�p�A�X�e�[�W����]�����Ⴀ�Ȃ����true
		bool StageIsNotRotation();
	};
}