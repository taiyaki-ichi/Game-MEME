#include<iostream>
#include<string>
#include<memory>
#include<random>
#include"GameLib/include/App.hpp"
#include"StartActor.hpp"

#include <stdlib.h>
#include <crtdbg.h>
#define malloc(X) _malloc_dbg(X,_NORMAL_BLOCK,__FILE__,__LINE__) 
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_DELAY_FREE_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);

#ifdef _M_X64
	auto app = GameLib::CreatAppPtr({ L"StageEditor",800,600 });
#else 
	auto app = GameLib::CreatAppPtr({ "StageEditor",800,600 });
#endif
	app->Start<StageEditor::StartActor>();


	return 0;

}