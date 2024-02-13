#include "ClearScene.h"
#include "Engine/Image.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent,"ClearScene"),cPict_(-1)
{
}

void ClearScene::Initialize()
{
	//画像データのロード
	cPict_ = Image::Load("");
	assert(cPict_ >= 0);
}

void ClearScene::Update()
{
}

void ClearScene::Draw()
{
}

void ClearScene::Release()
{
}
