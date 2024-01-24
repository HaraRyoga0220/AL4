#pragma once
#include"Model.h"
#include"WorldTransform.h"
#include"MathUtilityForText.h"
#include"Input.h"

class Player {
public:

	void Initialize(Model*modelBody,Model*modelHead,Model*modelL_arm,Model*modelR_arm);

	void Update();

	void Draw(const ViewProjection& viewProjection);

	const WorldTransform& GetWorldTransform() { return worldTransform_; }

	void SetViewProjection(const ViewProjection* viewProjection) {
		viewProjection_ = viewProjection;
	}

	//浮遊ギミック初期化
	void InitializeFloatingGimmick();

	//浮遊ギミック更新
	void UpdateFloatingGimmick();

	private:
		//ワールド変換データ
		WorldTransform worldTransform_;
		WorldTransform worldTransformBody_;
		WorldTransform worldTransformHead_;
		WorldTransform worldTransformL_arm_;
		WorldTransform worldTransformR_arm_;
		//3Dモデル
	    Model* modelFighterBody_;
		Model* modelFighterHead_;
		Model* modelFighterL_arm_;
		Model* modelFighterR_arm_;
	    /// テクスチャハンドル
	    uint32_t textureHandle_ = 0u;
		//入力
		Input* input_ = nullptr;
		//カメラのビュープロジェクション
		const ViewProjection* viewProjection_ = nullptr;

		//浮遊ギミックの媒介変数
	    float floatingParameter_ = 0.0f;
};
