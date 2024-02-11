#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/CsvReader.h"

namespace
{
	/*const int STAGE_X{ 15 };
	const int STAGE_Y{ 15 };*/
}

Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage")
{
	CsvReader map;
	map.Load("map.csv");
	stageWidth_ = map.GetWidth();
	stageHeight_= map.GetHeight();

	for (int i = 0; i < stageHeight_; i++) {
		vector<int>sdata(stageWidth_, 0);//stageWidth_個の配列を0で初期化
		stageData_.push_back(sdata);
	}

	//vector<vector<int>>stageData_(w, vector<int>(h, 0));

	for (int j = 0; j < stageHeight_; j++) {
		for (int i = 0; i < stageWidth_; i++) {
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
	Camera::SetPosition(XMFLOAT3(6.5, 10, -5));
	Camera::SetTarget(XMFLOAT3(6.5, 0, 5.5));
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

	for (int z = 0; z <stageHeight_; z++) {
		for (int x = 0; x < stageWidth_; x++) {
			floorTrans.position_ = { (float)x,0,(float)(14 - z) };
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
	//配列のお掃除
	for (int i = 0; i < stageHeight_; i++) {
		stageData_[i].clear();
	}
	stageData_.clear();
}

bool Stage::IsWall(int _x, int _y)
{
	//assert(stageWidth_>_x >=0);//_x,_yの範囲チェック
	if (stageData_[_y][_x] == STAGE_OBJ::WALL) {
		return true;
	}
	else {
		return false;
	}
}
