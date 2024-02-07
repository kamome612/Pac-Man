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
	int hpMax_;//�ő�HP
	int hpCrr_;//���݂�HP
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Player(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

