#pragma once
#include"Model.h"
#include"WorldTransform.h"
#include"MathUtilityForText.h"
	//敵
class Enemy {

	public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Model*model);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(ViewProjection&viewProjection);

	// 座標の獲得
	float GetX() { return worldTransform_.matWorld_.m[3][0]; }
	float GetY() { return worldTransform_.matWorld_.m[3][1]; }
	float GetZ() { return worldTransform_.matWorld_.m[3][2]; }

	//衝突処理
	void Hit();

	private:
		//ワールド変換データ
	    WorldTransform worldTransform_;
		//モデル
	    Model* model_ = nullptr;
		//テクスチャハンドル
	    uint32_t textureHandle_ = 0u;

		//ジャンプ
		bool jumpFlag_ = false;
		float jumpSpeed_ = 0;
};
