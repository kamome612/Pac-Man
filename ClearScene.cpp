#include "ClearScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent,"ClearScene"),cPict_(-1)
{
}

void ClearScene::Initialize()
{
	//画像データのロード
	cPict_ = Image::Load("Picture\\CLEAR.jpg");
	assert(cPict_ >= 0);
}

void ClearScene::Update()
{
	XMFLOAT3 mouse;
	mouse = Input::GetMousePosition();
	if (Input::IsMouseButtonDown(0))
	{
		if (mouse.y >= 430 && mouse.y <= 530) {
			if (mouse.x >= 230 && mouse.x <= 550) {
				SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
				pSceneManager->ChangeScene(SCENE_ID_TITLE);
			}
			else if (mouse.x >= 735 && mouse.x <= 1055) {
				exit(1);
			}
		}
	}
}

void ClearScene::Draw()
{
	Image::SetTransform(cPict_, transform_);
	Image::Draw(cPict_);
}

void ClearScene::Release()
{
}
