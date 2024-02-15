#include "Cookie.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"

Cookie::Cookie(GameObject* parent)
	:GameObject(parent,"Cookie"),hCookie_(-1)
{
	CsvReader map;
	map.Load("map.csv");
	stageWidth_ = map.GetWidth();
	stageHeight_ = map.GetHeight();

	for (int i = 0; i < stageHeight_; i++) {
		vector<int>sdata(stageWidth_, 0);//stageWidth_ŒÂ‚Ì”z—ñ‚ğ0‚Å‰Šú‰»
		stageData_.push_back(sdata);
	}

	//vector<vector<int>>stageData_(w, vector<int>(h, 0));

	for (int j = 0; j < stageHeight_; j++) {
		for (int i = 0; i < stageWidth_; i++) {
			stageData_[j][i] = map.GetValue(i, j);
		}
	}
}

void Cookie::Initialize()
{
	hCookie_ = Model::Load("cookie.fbx");
	assert(hCookie_ >= 0);
	SphereCollider* collision = new SphereCollider({ 0,0,0 }, 0.3f);
	AddCollider(collision);
}

void Cookie::Update()
{
}

void Cookie::Draw()
{
	Transform cookieTrans;
	cookieTrans.position_ = { 0,0,0 };

	for (int z = 0; z < stageHeight_; z++) {
		for (int x = 0; x < stageWidth_; x++) {
			cookieTrans.position_ = { (float)(x-0.5),0.2,(float)(14 - z + 0.5) };
			cookieTrans.scale_ = { 0.5,0.5,0.5 };
			if (stageData_[z][x] == 2) {
				Model::SetTransform(hCookie_, cookieTrans);
				Model::Draw(hCookie_);
			}
		}
	}
}

void Cookie::Release()
{
}

void Cookie::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Player") {
		this->KillMe();
	}
}
