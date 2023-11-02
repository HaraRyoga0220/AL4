#include "Ground.h"
#include<cassert>

void Ground::Initialize(Model*model) {

	//NULLポインタチェック
	assert(model);

	model_ = model; 

	//ワールド変換の初期化
	worldTransform_.Initialize();
}

void Ground::Update() {


}

void Ground::Draw(const ViewProjection&viewProjection) {
	//3Dモデルを描画
	model_->Draw(worldTransform_, viewProjection);

}
