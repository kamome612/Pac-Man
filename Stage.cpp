#include "Stage.h"
#include "Engine/Model.h"

Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage"), hFloor_(-1),hWall_(-1)
{
}

void Stage::Initialize()
{
	hFloor_ = Model::Load("Floor.fbx");
	assert(hFloor_ >= 0);
	hWall_ = Model::Load("Wall.fbx");
	assert(hWall_ >= 0);
}

void Stage::Update()
{
}

void Stage::Draw()
{
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			floorTrans.position_ = { 1.0f * j,0 ,1.0f * i };
			Model::SetTransform(hFloor_, floorTrans);
			Model::Draw(hFloor_);
		}
	}


}

void Stage::Release()
{
}
