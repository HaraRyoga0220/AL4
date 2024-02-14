#include"Ground.h"
#include<cassert>

void Ground::Initialize(Model*model) {
//NULLポインタチェック
	assert(model);
	//引数として受け取ったデータをメンバ変数にする
	model_ = model;
	//ワールド変換の初期化
	worldTransform_.Initialize();
}

void Ground::Update() { 
	worldTransform_.TransferMatrix(); 
}

void Ground::Draw(ViewProjection&viewProjection) {
	//3Dモデル描画
	model_->Draw(worldTransform_, viewProjection);
}

