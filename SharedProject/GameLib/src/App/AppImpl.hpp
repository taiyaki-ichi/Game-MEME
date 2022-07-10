#pragma once
#include<string>
#include<memory>
#include"GameLib/include/App.hpp"
#include<Windows.h>

namespace GameLib
{

	template<typename T>
	class SpaceDivisionTree;
	class Collider;

	class AppImpl : public App
	{
	public:
		AppImpl(WindowData&& windowData, float fps);
		~AppImpl();

	private:

		void StartImpl(Actor* rootActor) override;

		bool mIsRunning;

		bool Init(WindowData&& windowData);
		void GameLoop();
		void Shutdown();

		Actor* mRootActor;

		unsigned long mTime;
		unsigned long mWaitTime;

		std::unique_ptr<SpaceDivisionTree<Collider>> mSpaceDivisionTree;

		unsigned long mSumTime;
		int mCnt;

		HWND hwnd;
	};
}