#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/CsvReader.h"

namespace
{
	const int STAGE_X{ 15 };
	const int STAGE_Y{ 15 };
}

Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage")
{
	CsvReader map;
	map.Load("map.csv");
	int w = map.GetWidth();
	int h = map.GetHeight();

	for (int i = 0; i < STAGE_Y; i++) {
		vector<int>sdata(STAGE_X, 0);//15ŒÂ‚Ì”z—ñ‚ğ0‚Å‰Šú‰»
		stageData_.push_back(sdata);
	}

	//vector<vector<int>>stageData_(w, vector<int>(h, 0));

	for (int j = 0; j < STAGE_Y; j++) {
		for (int i = 0; i < STAGE_X; i++) {
			stageData_[j][i] = map.GetValue(i, j);
		}
	}
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
	//for (int i = 0; i < 15; i++) {
	//	for (int j = 0; j < 15; j++) {
	//		/*if (i == 0 || i == 14 || j == 0 || j == 14) {
	//			wallTrans.position_ = { 1.0f * j,0 ,1.0f * i };
	//			Model::SetTransform(hWall_, floorTrans);
	//			Model::Draw(hWall_);
	//		}
	//		else {
	//			floorTrans.position_ = { 1.0f * j,0 ,1.0f * i };
	//			Model::SetTransform(hFloor_, floorTrans);
	//			Model::Draw(hFloor_);
	//		}*/
	//		floorTrans.position_ = { 1.0f * j,0 ,1.0f * i };
	//		Model::SetTransform(hFloor_, floorTrans);
	//		Model::Draw(hFloor_);
	//		if (i == 0 || i == 14 || j == 0 || j == 14) {
	//			wallTrans.position_ = { 1.0f * j,0 ,1.0f * i };
	//			Model::SetTransform(hWall_, floorTrans);
	//			Model::Draw(hWall_);
	//		}
	//	}
	//}
	Transform floorTrans;
	floorTrans.position_ = { 0,0,0 };

	for (int z = 0; z <15; z++) {
		for (int x = 0; x < 15; x++) {
			floorTrans.position_ = { (float)x,0,(float)(14-z)};
			if (stageData_[z][x] == 1 ) {
				Model::SetTransform(hWall_, floorTrans);
				Model::Draw(hWall_);
			}
			else {
				Model::SetTransform(hFloor_, floorTrans);
				Model::Draw(hFloor_);
			}
		}
	}
}
void Stage::Release()
{
}
