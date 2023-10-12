#include "Player.h"
#include"ImGuiManager.h"
#include"Vector3.h"
#include<cassert>

void Player::Initialize(Model* model, uint32_t textureHandle) {
	assert(model);

	textureHandle_ = textureHandle;
	model_ = model;

	worldTransform_.Initialize();
}

void Player::Update() {


}

void Player::Draw(const ViewProjection& viewProjection) { 
	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}

