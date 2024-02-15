#include "Cookie.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"

Cookie::Cookie(GameObject* parent)
	:GameObject(parent,"Cookie"),hCookie_(-1)
{
}

void Cookie::Initialize()
{
	hCookie_ = Model::Load("cookie.fbx");
	assert(hCookie_ >= 0);
	transform_.scale_ = { 0.5,0.5,0.5 };
	SphereCollider* collision = new SphereCollider({ 0,0,0 }, 0.1f);
	AddCollider(collision);
}

void Cookie::Update()
{
}

void Cookie::Draw()
{
	Model::SetTransform(hCookie_, transform_);
	Model::Draw(hCookie_);
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
