#include "Skydorm.h"
#include<cassert>

void Skydorm::Initialize(Model* model) {

//NULLポインタチェック
	assert(model);
	//メンバ変数に受け取った値の代入
	model_ = model;

	//ワールド変換の初期化
	worldTransform_.Initialize();

}

void Skydorm::Update() {}

void Skydorm::Draw(const ViewProjection& viewProjection) {
	//3Dモデルを描画
	model_ ->Draw(worldTransform_, viewProjection);
}
