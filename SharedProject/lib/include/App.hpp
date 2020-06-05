#pragma once
#include<string>
#include<memory>

namespace GameLib
{

	class RootActor;

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

		//RootActor�̃|�C���^��n��App���J�n����
		virtual void Start(RootActor* rootActor) = 0;
	};

	//App�̃|�C���g�͂����������	
	std::unique_ptr<App> CreatAppPtr(WindowData&& windowData);

}