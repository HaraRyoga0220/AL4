#include "Skydorm.h"
#include<cassert>

void Skydorm::Initialize(Model* model) { 
	assert(model);

	model_ = model;

	worldTransform_.Initialize();
}

void Skydorm::Update() {}

void Skydorm::Draw(const ViewProjection& viewProjection) {
	model_->Draw(worldTransform_, viewProjection);
}
