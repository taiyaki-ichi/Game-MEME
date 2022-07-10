#pragma once
#include<string>
#include<memory>
#include<type_traits>
#include"Actor/Actor.hpp"
namespace GameLib
{
	struct WindowData {
		wchar_t const* WindowName;
		float WindowWidth;
		float WindowHeigth;
	};


	class App
	{
	protected:
		App() = default;

	public:
		virtual ~App() = default;

		//RootActor�̌^��n��App�X�^�[�g
		//StartActor�̃R���X�g���N�^�̑�������Actor*�Œ�
		template<typename StartActor,typename ...Args>
		void Start(Args&& ...args) {
			//RootActor���p�����ĂȂ���΂�����[
			static_assert(std::is_base_of_v<Actor,StartActor>, "Actor is not base of StartActor");

			//���[�g�A�N�^
			Actor* rootActor = new Actor{ nullptr };

			//�N���C�A���g�̃��[�g�A�N�^
			new StartActor(rootActor, std::forward<Args>(args)...);

			StartImpl(rootActor);
		}

	private:
		virtual void StartImpl(Actor* rootActor) = 0;
	};

	constexpr float DEFAULT_FPS = 60.f;

	//App�̃|�C���^�͂����������A��x�̂݌Ăяo����
	std::unique_ptr<App> CreatAppPtr(WindowData&& windowData, float fps = DEFAULT_FPS);

}