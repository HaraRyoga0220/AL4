#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
//#include"SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include"Player.h"
#include"Ground.h"
#include"Skydorm.h"
#include<memory>
#include"FollowCamera.h"
#include"DebugCamera.h"
#include"AxisIndicator.h"
#include <Enemy.h>

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
	
	uint32_t textureHandle_ = 0u;
	//3Dモデル
	std::unique_ptr<Model> modelSkydorm_;
	std::unique_ptr<Model> modelGround_;
	std::unique_ptr<Model> modelFighterBody_;
	std::unique_ptr<Model> modelFighterHead_;
	std::unique_ptr<Model> modelFighterL_arm_;
	std::unique_ptr<Model> modelFighterR_arm_;
	std::unique_ptr<Model> modelEnemyBody_;
	std::unique_ptr<Model> modelEnemyL_arm_;
	std::unique_ptr<Model> modelEnemyR_arm_;
	//ビュープロジェクション
	ViewProjection viewProjection_;
	//各クラス
	std::unique_ptr<Player> player_;
	std::unique_ptr<Ground> ground_;
	std::unique_ptr<Skydorm> skydorm_;
	std::unique_ptr<FollowCamera> followCamera_;
	std::unique_ptr<DebugCamera> debugCamera_;
	std::unique_ptr<Enemy> enemy_;

	bool isDebugCameraActive_ = false;

	

};
