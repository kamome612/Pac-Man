#pragma once
#include "Engine/GameObject.h"
#include <vector>
using std::vector;

class Cookie :
    public GameObject
{
    int hCookie_;
	vector<vector<int>>stageData_;
	int stageWidth_, stageHeight_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Cookie(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�����蔻��
	void OnCollision(GameObject* pTarget) override;
};

