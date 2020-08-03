#pragma once
#include<string>
#include<memory>
#include<type_traits>
#include"Actor/RootActor.hpp"
namespace GameLib
{
	struct WindowData {
		std::string WindowName;
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
		template<typename StartActor,typename ...Args>
		void Start(Args&& ...args) {
			//RootActor���p�����ĂȂ���΂�����[
			static_assert(std::is_base_of_v<RootActor,StartActor>, "RootActor is not base of StartActor");

			RootActor* rootActor = new StartActor(std::forward<Args>(args)...);
			StartImpl(rootActor);
		}

	private:
		virtual void StartImpl(RootActor* rootActor) = 0;
	};

	constexpr float DEFAULT_FPS = 60.f;

	//App�̃|�C���^�͂����������A��x�̂݌Ăяo����
	std::unique_ptr<App> CreatAppPtr(WindowData&& windowData, float fps = DEFAULT_FPS);

}