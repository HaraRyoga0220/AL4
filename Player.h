#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include "Input.h"
#include"MathUtilityForText.h"
//プレイヤー
class Player {

	public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Model*modelBody,Model*modelHead,Model*modelL_arm,Model*modelR_arm);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(ViewProjection&viewProjection);

	const WorldTransform& GetWorldTransform() { return worldTransform_; }

	//浮遊ギミック初期化
	void InitializeFloatingGimmick();
	//浮遊ギミックの更新
	void UpdateFloatingGimmick();

	// 座標の獲得
	float GetX() { return worldTransform_.matWorld_.m[3][0]; }
	float GetY() { return worldTransform_.matWorld_.m[3][1]; }
	float GetZ() { return worldTransform_.matWorld_.m[3][2]; }


	private:
		//ワールド変換データ
	    WorldTransform worldTransform_;
		WorldTransform worldTransformBody_;
		WorldTransform worldTransformHead_;
		WorldTransform worldTransform_L_arm_;
		WorldTransform worldTransform_R_arm_;

		//3Dモデル
		Model* modelFighterBody_;
		Model* modelFighterHead_;
		Model* modelFighterL_arm_;
		Model* modelFighterR_arm_;


		//テクスチャハンドル
	    uint32_t textureHandle_ = 0u;

		Input* input_ = nullptr;

		//浮遊ギミックの媒介変数
		float floatingParameter_ = 0.0f;
};
