#pragma once
#include"Model.h"
#include"WorldTransform.h"


class Player {
public:

	void Initialize(Model* model);

	void Update();

	void Draw(const ViewProjection& viewProjection);

	private:
        //ワールド変換データ
		WorldTransform worldTransform_;
		//モデル
	    Model* model_ = nullptr;
		//テクスチャハンドル
	    uint32_t textureHandle_ = 0u;
};
