/**
 * This file is part of RT2D, a 2D OpenGL framework.
 *
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 */
#include "scene01.h"

Scene01::Scene01()
	: Scene()
{
	// green
	flock1 = new Flock(16);
	flock1->boidColor(GREEN);
	flock1->boidWeights(1.8f, 0.7f, 1.7f);	// separation, alignment, cohesion
	flock1->boidViewDistance(85.0f);		// _viewdistance

	// red
	flock2 = new Flock(12);
	flock2->boidColor(RED);
	flock2->boidWeights(2.0f, 1.2f, 1.0f);	// separation, alignment, cohesion
	flock2->boidViewDistance(50.0f);		// _viewdistance

	// pink
	flock3 = new Flock(8);
	flock3->boidColor(PINK);
	flock3->boidWeights(1.2f, 1.0f, 1.0f);	// separation, alignment, cohesion
	flock3->boidViewDistance(50.0f);		// _viewdistance

	// blue
	flock4 = new Flock(5);
	flock4->boidColor(BLUE);
	flock4->boidWeights(30.0f, 0.2f, 1.5f);	// separation, alignment, cohesion
	flock4->boidViewDistance(85.0f);		// _viewdistance

	// yellow
	flock5 = new Flock(8);
	flock5->boidColor(YELLOW);
	flock5->boidWeights(1.0f, 1.0f, 1.0f);	// separation, alignment, cohesion
	flock5->boidViewDistance(50.0f);		// _viewdistance

	this->addChild(flock1);
	this->addChild(flock2);
	this->addChild(flock3);
	this->addChild(flock4);
	this->addChild(flock5);
}


Scene01::~Scene01()
{
	delete flock1;
	delete flock2;
	delete flock3;
	delete flock4;
	delete flock5;
}

void Scene01::update(float deltaTime)
{
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Make SuperScene do what it needs to do
	// - Escape key stops Scene
	// - Move Camera
	// ###############################################################
	SuperScene::update(deltaTime);
	SuperScene::moveCamera(deltaTime);

	// ###############################################################
	// - link mouse to camera
	// - account for camera offset (center of the screen)
	// - update mouse cursor text
	// ###############################################################
	int mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	int mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;

}
