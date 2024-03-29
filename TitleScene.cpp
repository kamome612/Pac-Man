#include "TitleScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent,"TitleScene"),tPict_(-1),tText_(nullptr)
{
}

void TitleScene::Initialize()
{
	//画像データのロード
	tPict_ = Image::Load("Picture\\TITLE.jpg");
	assert(tPict_ >= 0);
	tText_ = new Text;
	tText_->Initialize();
}

void TitleScene::Update()
{
	XMFLOAT3 mouse;
	mouse = Input::GetMousePosition();
	if (Input::IsMouseButtonDown(0))
	{
		if (mouse.y >= 430 && mouse.y <= 530) {
			if (mouse.x >= 230 && mouse.x <= 550) {
				SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
				pSceneManager->ChangeScene(SCENE_ID_PLAY);
			}
			else if (mouse.x >= 735 && mouse.x <= 1055) {
				exit(1);
			}
		}
	}
}

void TitleScene::Draw()
{
	Image::SetTransform(tPict_, transform_);
	Image::Draw(tPict_);
}

void TitleScene::Release()
{
}
