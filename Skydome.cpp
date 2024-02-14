#include"Skydome.h"
#include<cassert>

void Skydome::Initialize(Model*model) {
//NULLポインタチェック
	assert(model);
	//引数として受け取ったデータをメンバ変数にする
	model_ = model;
	//ワールド変換の初期化
	worldTransform_.Initialize();
}

void Skydome::Update() { 
	worldTransform_.TransferMatrix(); 
}

void Skydome::Draw(ViewProjection&viewProjection) {
	//3Dモデル描画
	model_->Draw(worldTransform_, viewProjection);
}

