#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"
#include "Stage.h"
#include "Gauge.h"

namespace {
	const float PLAYER_MOVE_SPEED{ 0.06f };
}

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hPac_(-1),speed_(PLAYER_MOVE_SPEED),pStage_(nullptr),
	hpMax_(100),hpCrr_(100)
{
}

void Player::Initialize()
{
	hPac_ = Model::Load("Player.fbx");
	assert(hPac_ >= 0);
	transform_.position_.x = 0.5;
	transform_.position_.z = 1.5;
	pStage_ = (Stage*)FindObject("Stage");
}

void Player::Update()
{
	/*enum Dir
	{
		UP,DOWN,RIGHT,LEFT,NONE,
	};
	int moveDir = Dir::NONE;*/

	XMVECTOR vFront = { 0,0,1,0 };
	XMVECTOR move = { 0,0,0,0 };

	if (Input::IsKey(DIK_UP)) {
		move = XMVECTOR{ 0,0,1,0 };
		//moveDir = Dir::UP;
		//transform_.rotate_.y = 0;
	}
	else if (Input::IsKey(DIK_DOWN)) {
		move = XMVECTOR{ 0,0,-1,0 };
		//moveDir = Dir::DOWN;
		//transform_.rotate_.y = 180;
	}
	else if (Input::IsKey(DIK_RIGHT)) {
		move = XMVECTOR{ 1,0,0,0 };
		//moveDir = Dir::RIGHT;
		//transform_.rotate_.y = 90;
	}
	else if (Input::IsKey(DIK_LEFT)) {
		move = XMVECTOR{ -1,0,0,0 };
		//moveDir = Dir::LEFT;
		//transform_.rotate_.y = 270;
	}
	
	/*if (transform_.position_.x < 0.5) {
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
	}*/
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	XMVECTOR posTmp = XMVectorZero();//ゼロベクトルで初期化
	posTmp = pos + speed_ * move;
	//posTmp.x. posTmp.z => int tx,ty :配列のインデックス
	//仮のmapの配列をmap[][]とする
	//移動先がフロア(STAGE_OBJ::FLOOR -> 0)だったら動く
	/*if (map[ty][tx] == STAGE_OBJ::FLOOR) {
		pos = pos + speed_ * move;
	}*/
	/*Debug::Log("(X, Y)=");
	Debug::Log(XMVectorGetX(pos));
	Debug::Log(",");
	Debug::Log(XMVectorGetZ(pos), true);*/
	int tx, ty;
	tx = (int)(XMVectorGetX(posTmp) + 1.0f);
	ty = pStage_->GetStageWidth() - (int)(XMVectorGetZ(posTmp) + 1.0f);
	/*Debug::Log("(iX, iZ)=");
	Debug::Log(tx);
	Debug::Log(",");
	Debug::Log(ty);
	Debug::Log(":");
	Debug::Log(pStage_->IsWall(tx,ty),true);*/
	if (!(pStage_->IsWall(tx, ty))) {
		pos = posTmp;
	}
	else {
		hpCrr_ = hpCrr_ - 2;
		if (hpCrr_ < 0) hpCrr_ = 0;
	}
	//pos = pos + speed_ * move;
	if (!XMVector3Equal(move, XMVectorZero())) {
		XMStoreFloat3(&(transform_.position_), pos);

		/*XMMATRIX rot = XMMatrixRotationY(-XM_PIDIV2);
		XMVECTOR modifiedVec = XMPlaneTransform(move, rot);
		Debug::Log(XMVectorGetX(modifiedVec));
		Debug::Log(",");
		Debug::Log(XMVectorGetZ(modifiedVec));*/

		float angle = atan2(XMVectorGetX(move), XMVectorGetZ(move));

		Debug::Log(" => ");
		Debug::Log(XMConvertToDegrees(angle), true);
		/*XMVECTOR vdot = XMVector3Dot(vFront, move);
		assert(XMVectorGetX(vdot) <= 1 && XMVectorGetX(vdot) >= -1);
		float angle = acos(XMVectorGetX(vdot));

		XMVECTOR vCross = XMVector3Cross(vFront, move);
		if (XMVectorGetY(vCross) < 0) {
			angle *= -1;
		}*/
		transform_.rotate_.y = XMConvertToDegrees(angle);

	}

	pGauge_ = (Gauge*)FindObject("Gauge");
	pGauge_->SetGaugeVal(hpCrr_, hpMax_);
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
