#include "Gauge.h"
#include "Engine/Image.h"

Gauge::Gauge(GameObject* parent)
	:GameObject(parent,"Gauge"),hGaugeBar_(-1),hGaugeFrame_(-1),
	gaugeMaxVal_(200),gaugeCrrVal_(100)
{
}

void Gauge::Initialize()
{
	hGaugeBar_ = Image::Load("hpbar.png");
	assert(hGaugeBar_ >= 0);
	hGaugeFrame_ = Image::Load("frame.png");
	assert(hGaugeFrame_ >= 0);

	transform_.position_.x = 0.0f;
	transform_.position_.y = 0.9f;
}

void Gauge::Update()
{
}

void Gauge::Draw()
{
	Transform tr = this->transform_;
	tr.scale_.x = tr.scale_.x * (float)gaugeCrrVal_ / (float)gaugeMaxVal_;
	tr.position_.x = -0.2f;
	Image::SetTransform(hGaugeBar_, tr);
	Image::Draw(hGaugeBar_);

	Image::SetTransform(hGaugeFrame_, transform_);
	Image::Draw(hGaugeFrame_);
}

void Gauge::Release()
{
}
