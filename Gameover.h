#pragma once
#include "Engine/GameObject.h"

//�Q�[���I�[�o�[�V�[�����Ǘ�����N���X
class GameoverScene : public GameObject
{
private:
	int goPict_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	GameoverScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};