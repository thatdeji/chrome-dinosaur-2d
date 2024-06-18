#pragma once

#include "TransformComponent.h"
#include "TextureManager.h"
#include "Collision.h"

class Sprite {
	int mFramesCount;
	int mFramesSpeed;
	int mSheetIndex = 0;

	Collider mCollider;

	SDL_Rect mSrcRect{ 0, 0, 0, 0 };
	SDL_Rect mDestRect{ 0, 0, 0, 0 };

	TransformComponent* mTransform;

public:
	virtual void init() {}
	virtual void update() {}
	virtual void press_UP_key() {}
	virtual void press_DOWN_key() {}
	virtual void release_DOWN_key() {}

	void setAnimation(int index, int nFrames, int mSpeed) {
		mSheetIndex = index;
		mFramesCount = nFrames;
		mFramesSpeed = mSpeed;
	}

	int getFramesCount() const {
		return mFramesCount;
	}

	int getFramesSpeed() const {
		return mFramesSpeed;
	}

	int getSheetIndex() const {
		return mSheetIndex;
	}

	void setSrcRect(int x, int y, int w, int h) {
		mSrcRect.x = x;
		mSrcRect.y = y;
		mSrcRect.h = h;
		mSrcRect.w = w;
	}

	SDL_Rect& getSrcRect() {
		return mSrcRect;
	}

	SDL_Rect& getDestRect() {
		return mDestRect;
	}

	void initTransform(TransformComponent* transform) {
		mTransform = transform;
	}

	virtual void setTransform(float x, float y, int w, int h) {
		mTransform->mPosition.x = x;
		mTransform->mPosition.y = y;
		mTransform->mWidth = w;
		mTransform->mHeight = h;
	}

	TransformComponent& getTransform() {
		return *mTransform;
	}

	Collider& getCollider() {
		return mCollider;
	}
};

class DinoState;

class Dino : public Sprite {
	DinoState* mState = nullptr;

	bool mJumping = false;
	bool mDucking = false;
	bool mRunning = false;

	void press_UP_key() override;
	void press_DOWN_key() override;
	void release_DOWN_key() override;

public:
	const int mVerticalJumpDistance = 290;

	~Dino();

	void startDuck();
	void stopDuck();
	
	void startJump();
	void stopJump();

	void startRun();
	void stopRun();

	void setState(DinoState* state);
	DinoState* getState() const;
	void clearState();

	void init() override;
	void update() override;
};

class Background : public Sprite {
public:
	void init() override;

	void update() override;
};

class CelestialBody : public Sprite {
public:
	void update() override;
};

class Ground : public Sprite {
public:
	void init() override;

	void update() override;
};

class DyingTree1 : public Sprite {
public:
	void init() override;

	void update() override;
};

class DyingTree2 : public Sprite {
public:
	void init() override;

	void update() override;
};

class Bucket : public Sprite {
public:
	void init() override;

	void update() override;
};

class TreeStump : public Sprite {
public:
	void init() override;
	
	void update() override;
};

class Stalker : public Sprite {
public:
	void init() override;

	void update() override;
};

class Brute : public Sprite {
public:
	void init() override;

	void update() override;
};

class StalkerPup : public Sprite {
public:
	void init() override;
	
	void update() override;
};

class Gale : public Sprite {
public:
	void init() override;

	void update() override;
};