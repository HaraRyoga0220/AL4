#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	viewProjection_.farZ = 2000.0f;
	viewProjection_.translation_ = {0.0f, 2.0f, -10.0f};
	viewProjection_.Initialize();

	textureHandle_ = TextureManager::Load("mario.jpg");

	modelSkydorm_.reset(Model::CreateFromOBJ("skydome", true));
	modelGround_.reset(Model::CreateFromOBJ("ground", true));
	modelFighter_.reset(Model::CreateFromOBJ("float", true));
	//自機
	player_ = std::make_unique<Player>();
	player_->Initialize(modelFighter_.get());
	//地面
	ground_ = std::make_unique<Ground>();
	ground_->Initialize(modelGround_.get());
	//スカイドーム
	skydorm_ = std::make_unique<Skydorm>();
	skydorm_->Initialize(modelSkydorm_.get());

	//デバックカメラ
	debugCamera_ = std::make_unique<DebugCamera>(WinApp::kWindowWidth, WinApp::kWindowHeight);
	debugCamera_->SetFarZ(2000.0f);

	//追従カメラ
	followCamera_ = std::make_unique<FollowCamera>();
	followCamera_->Initialize();

	player_->SetViewProjection(&followCamera_->GetViewProjection());

	followCamera_->SetTarget(&player_->GetWorldTransform());

	AxisIndicator::GetInstance()->SetVisible(true);

	AxisIndicator::GetInstance()->SetTargetViewProjection(&debugCamera_->GetViewProjection());
}
void GameScene::Update() {

	if (input_->TriggerKey(DIK_0)) {
		isDebugCameraActive_ = !isDebugCameraActive_;
	}
	if (isDebugCameraActive_ == true) {
		debugCamera_->Update();
		viewProjection_.matView = debugCamera_->GetViewProjection().matProjection;
		viewProjection_.matProjection = debugCamera_->GetViewProjection().matProjection;
	} else {
		followCamera_->Update();
		viewProjection_.matView = followCamera_->GetViewProjection().matView;
		viewProjection_.matProjection = followCamera_->GetViewProjection().matProjection;
	}
	viewProjection_.TransferMatrix();
	player_->Update();
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	player_->Draw(viewProjection_);
	ground_->Draw(viewProjection_);
	skydorm_->Draw(viewProjection_);

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}