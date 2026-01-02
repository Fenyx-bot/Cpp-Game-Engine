#include "Engine.h"

Vector2 Engine::screenSize = { 960, 480 };
Texture2D Engine::Background;

Engine::Engine(){
	
}

Engine::~Engine() {
	Destroy();
}

void Engine::AddActor(std::unique_ptr<Actor> actor) {
	actors.push_back(std::move(actor));
}

void Engine::Run() {
	Engine::Init();
	Init();
	while (!WindowShouldClose()) {
		Engine::Update();
		Update();
		BeginDrawing();
		ClearBackground(RAYWHITE);
		Draw();
		EndDrawing();
	}

}


void Engine::Init() {
	InitWindow((int)screenSize.x, (int)screenSize.y, "Game Engine test");
	SetTargetFPS(144);
	//Checkered texture
	int width = 960;
	int height = 480;

	Color* pixels = (Color*)malloc(width * height * sizeof(Color));

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (((x / 32 + y / 32) / 1) % 2 == 0) pixels[y * width + x] = Color{ 100, 149, 237, 255 };
			else pixels[y * width + x] = Color{ 30, 42, 68, 255 };
		}
	}

	// Load pixels data into an image structure and create texture
	Image checkedIm = {
		pixels,
		width,
		height,
		1,
		PIXELFORMAT_UNCOMPRESSED_R8G8B8A8
	};

	Background = LoadTextureFromImage(checkedIm);
	UnloadImage(checkedIm);

	for (auto& actor : actors) {
		actor->Init();
	}

}

void Engine::Update(){
	for (auto& actor : actors) {
		actor->Update(GetFrameTime());
	}
}

void Engine::Draw() {
	DrawTexture(Engine::Background, (int)(Engine::screenSize.x / 2 - Engine::Background.width / 2), (int)(Engine::screenSize.y / 2 - Engine::Background.height / 2), Fade(WHITE, 0.5f));
	for (auto& actor : actors)
	{
		for (auto& comp : actor->GetComponents())
		{
			if (auto drawable = dynamic_cast<DrawableComponent*>(comp.get()))
				drawable->Draw();
		}
	}
}

void Engine::Destroy() {
	UnloadTexture(Background);
	CloseWindow();
}

Vector2 Engine::GetWindowSize() {
	return Engine::screenSize;
}
