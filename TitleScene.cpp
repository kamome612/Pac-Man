#include "TitleScene.h"
#include "Engine/Image.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent,"TitleScene"),tPict_(-1)
{
}

void TitleScene::Initialize()
{
	//画像データのロード
	tPict_ = Image::Load("");
	assert(tPict_ >= 0);
}

void TitleScene::Update()
{
}

void TitleScene::Draw()
{
}

void TitleScene::Release()
{
}
