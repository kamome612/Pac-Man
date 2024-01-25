#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"

const int STAGE_X{ 15 };
const int STAGE_Y{ 15 };
int stage[STAGE_X][STAGE_Y]{
	{1},{1},{1},{1},{1},{1},{1},{1},{1},{1},{1}
};

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
	/*CsvReader map;
	map.Load("map.csv");*/
}

void Stage::Update()
{
}

void Stage::Draw()
{
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			/*if (i == 0 || i == 14 || j == 0 || j == 14) {
				wallTrans.position_ = { 1.0f * j,0 ,1.0f * i };
				Model::SetTransform(hWall_, floorTrans);
				Model::Draw(hWall_);
			}
			else {
				floorTrans.position_ = { 1.0f * j,0 ,1.0f * i };
				Model::SetTransform(hFloor_, floorTrans);
				Model::Draw(hFloor_);
			}*/
			floorTrans.position_ = { 1.0f * j,0 ,1.0f * i };
			Model::SetTransform(hFloor_, floorTrans);
			Model::Draw(hFloor_);

			if (i == 0 || i == 14 || j == 0 || j == 14) {
				wallTrans.position_ = { 1.0f * j,0 ,1.0f * i };
				Model::SetTransform(hWall_, floorTrans);
				Model::Draw(hWall_);
			}
		}
	}
}

void Stage::Release()
{
}
