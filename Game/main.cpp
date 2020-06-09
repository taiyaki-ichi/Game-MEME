#include<iostream>
#include<string>
#include<memory>
#include"lib/include/Actor/RootActor.hpp"
#include"lib/include/App.hpp"
#include"lib/src/Windows/Window.hpp"
#include"lib/include/Math/Vector2Func.hpp"
#include"lib/include/Draw/DrawTexture.hpp"
#include"lib/include/Draw/DrawLine.hpp"

#include <stdlib.h>
#include <crtdbg.h>
#define malloc(X) _malloc_dbg(X,_NORMAL_BLOCK,__FILE__,__LINE__) 
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

using namespace GameLib;

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_DELAY_FREE_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);

	
	auto app = GameLib::CreatAppPtr({ "window",800,600 });
	DrawLine line({ -400,-300 }, { 400,300 }, { 255,0,0,255 }, 15);
	DrawTexture tex("../Assets/run001.png", { 0.f,0.f }, 0.5f, 0.f, 10);
	auto root = new GameLib::RootActor();

	app->Start(root);

	//asasas

	return 0;
	
}