#pragma once
#include<string>
#include<memory>
#include<type_traits>
#include"Actor/Actor.hpp"
namespace GameLib
{
#ifdef _M_X64
#define WINDOW_NAME_TYPE wchar_t
#else 
#define WINDOW_NAME_TYPE char
#endif

	struct WindowData {
		WINDOW_NAME_TYPE const* WindowName;
		float WindowWidth;
		float WindowHeigth;
	};


	class App
	{
	protected:
		App() = default;

	public:
		virtual ~App() = default;

		//RootActorの型を渡しAppスタート
		//StartActorのコンストラクタの第一引数はActor*固定
		template<typename StartActor,typename ...Args>
		void Start(Args&& ...args) {
			//RootActorを継承してなければえっらー
			static_assert(std::is_base_of_v<Actor,StartActor>, "Actor is not base of StartActor");

			//ルートアクタ
			Actor* rootActor = new Actor{ nullptr };

			//クライアントのルートアクタ
			new StartActor(rootActor, std::forward<Args>(args)...);

			StartImpl(rootActor);
		}

	private:
		virtual void StartImpl(Actor* rootActor) = 0;
	};

	constexpr float DEFAULT_FPS = 60.f;

	//Appのポインタはここから入手、一度のみ呼び出し可
	std::unique_ptr<App> CreatAppPtr(WindowData&& windowData, float fps = DEFAULT_FPS);

}