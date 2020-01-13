/**
 * This file is part of SOF, made in RT2D
 */
#include "scene01.h"

Scene01::Scene01()
	: Scene()
{
	// green
	flock1 = new Flock(16);
	flock1->boidColor(BLUE);
	flock1->boidWeights(1.8f, 1.0f, 1.7f);	// separation, alignment, cohesion
	flock1->boidViewDistance(85.0f);		// _viewdistance
	/*
	// red
	flock2 = new Flock(16);
	flock2->boidColor(RED);
	flock2->boidWeights(2.0f, 1.2f, 1.5f);	// separation, alignment, cohesion
	flock2->boidViewDistance(70.0f);		// _viewdistance
	*/
	this->addChild(flock1);
}


Scene01::~Scene01()
{
	delete flock1;
}

void Scene01::update(float deltaTime)
{
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}
