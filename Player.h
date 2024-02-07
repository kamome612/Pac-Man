#pragma once
#include "Engine/GameObject.h"

class Stage;
class Gauge;

class Player :
    public GameObject
{
	int hPac_;
	float speed_;
	Stage* pStage_;
	Gauge* pGauge_;
	int hpMax_;//最大HP
	int hpCrr_;//現在のHP
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

