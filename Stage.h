#pragma once
#include "Engine/GameObject.h"
class Stage :
    public GameObject
{
	int hFloor_;
	int hWall_;
	Transform floorTrans;
	Transform wallTrans;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Stage(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};
