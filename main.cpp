#include "stdafx.h"

CInfo g_CInfo;

INT WINAPI WinMain( HINSTANCE hInstance, HINSTANCE, LPSTR,  int)
{
	D_WORLD->WorldInit("기본윈도우 만들기 [노는자 5망하노니 명심하시오]", 1200, 800, false);		//!< 월드를 설정합니다
	D_WORLD->SetBackColor(CEMColor(255, 255, 255));												//!< 배경색을 지정합니다.
	//D_WORLD->Commit(new CEMGrid());																//!< 그리드 추가합니다.
	//D_WORLD->SetBoundingBoxShowFlag(true);														//!< 바운딩 박스 보여주게합니다
	//D_WORLD->SetFpsShowFlag(true);
 	D_WORLD->SetMouseCursor( "data/image/Mouse/cursor_down.png",
 					 		  stEMOffset(0.0f, 0.0f),
 							 "data/image/Mouse/cursor_down.png",
 							  stEMOffset(0.0f, 0.0f)			//!< 그림 의 맨왼쪽위로 offset이 이동해야하므로 그림 사이즈(32) - 16만큼 해주면 됩니다
 						   );
	D_SCENE->Commit(new CLoadScene, "Load");	//!< 로고 씬 등록
	D_SCENE->Commit(new CLogoScene, "logo");	//!< 로고 씬 등록
	D_SCENE->Commit(new CMenuScene, "menu");	//!< 메뉴 씬 등록
	D_SCENE->Commit(new  CMethodScene, "way");
	D_SCENE->Commit(new  CGameScene, "game");
	D_SCENE->Commit(new CResultScene, "result");

	D_SCENE->ChangeScene("Load");				//!< 이거안해주면 기본 logo씬으로 자동 갑니다^^

	D_WORLD->RunLoop();

	return 1;
}
