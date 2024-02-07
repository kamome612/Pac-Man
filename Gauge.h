#pragma once
#include "Engine/GameObject.h"
class Gauge :
    public GameObject
{
    int hGaugeBar_;//�Q�[�W�̉摜�n���h��
    int hGaugeFrame_;//�t���[���̉摜�n���h��

    int gaugeMaxVal_;//�Q�[�W�̍ő�l
    int gaugeCrrVal_;//�J�����g�̒l(���݂̒l)
public:
    //�R���X�g���N�^
    //�����Fparent�@�e�I�u�W�F�N�g(SceneManager)
    Gauge(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�Z�b�^�[
    void SetGaugeVal(int _crr, int _max)
    {
        gaugeMaxVal_ = _max;
        gaugeCrrVal_ = _crr;
    }
};

