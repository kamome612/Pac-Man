#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"

namespace {
	const float PLAYER_MOVE_SPEED{ 1.0f };
}

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hPac_(-1),speed_(PLAYER_MOVE_SPEED)
{
}

void Player::Initialize()
{
	hPac_ = Model::Load("Player.fbx");
	assert(hPac_ >= 0);
	transform_.position_.x = 0.5;
	transform_.position_.z = 1.5;
	//map[13][1]Ç™ÅA(map[y][x]ÇÃèÍçá)èâä˙à íu
}

void Player::Update()
{
	/*enum Dir
	{
		UP,DOWN,RIGHT,LEFT,NONE,
	};
	int moveDir = Dir::NONE;*/

	XMVECTOR vFront = { 0,0,1,0 };
	XMVECTOR move = { 0,0,1,0 };

	if (Input::IsKeyDown(DIK_UP)) {
		move = XMVECTOR{ 0,0,1,0 };
		//moveDir = Dir::UP;
		//transform_.rotate_.y = 0;
	}
	else if (Input::IsKeyDown(DIK_DOWN)) {
		move = XMVECTOR{ 0,0,-1,0 };
		//moveDir = Dir::DOWN;
		//transform_.rotate_.y = 180;
	}
	else if (Input::IsKeyDown(DIK_RIGHT)) {
		move = XMVECTOR{ 1,0,0,0 };
		//moveDir = Dir::RIGHT;
		//transform_.rotate_.y = 90;
	}
	else if (Input::IsKeyDown(DIK_LEFT)) {
		move = XMVECTOR{ -1,0,0,0 };
		//moveDir = Dir::LEFT;
		//transform_.rotate_.y = 270;
	}
	
	if (transform_.position_.x < 0.5) {
		transform_.position_.x = 0.5;
	}
	if (transform_.position_.x > 12.5) {
		transform_.position_.x = 12.5;
	}
	if (transform_.position_.z < 1.5) {
		transform_.position_.z = 1.5;
	}
	if (transform_.position_.z > 13.5) {
		transform_.position_.z = 13.5;
	}
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	pos = pos + speed_ * move;
	Debug::Log("(X, Y)=");
	Debug::Log(XMVectorGetX(pos));
	Debug::Log(",");
	Debug::Log(XMVectorGetZ(pos), true);

	XMStoreFloat3(&(transform_.position_), pos);

	XMVECTOR vdot = XMVector3Dot(vFront, move);
	float angle = acos(XMVectorGetX(vdot));

	XMVECTOR vCross = XMVector3Cross(vFront, move);
	assert(XMVectorGetX(vdot) <= 1 && XMVectorGetX(vdot) >= -1);
	if (XMVectorGetY(vCross) < 0) {
		angle *= -1;
	}
	transform_.rotate_.y = XMConvertToDegrees(angle);

	/*float rotAngle[5]{ 0,180,90,270,0 };
	transform_.rotate_.y = rotAngle[moveDir];*/
}

void Player::Draw()
{
	Model::SetTransform(hPac_, transform_);
	Model::Draw(hPac_);
}

void Player::Release()
{
}
