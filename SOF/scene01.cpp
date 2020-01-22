/**
 * This file is part of SOF, made in RT2D
 */
#include "scene01.h"

Scene01::Scene01()
	: Scene()
{
	// green
	flock1 = new Flock(16);
	flock1->boidColor(RED);
	flock1->boidWeights(1.8f, 1.0f, 1.7f);	// separation, alignment, cohesion
	flock1->boidViewDistance(85.0f);		// _viewdistance

		// green
	pflock = new PFlock(16);
	pflock->pboidColor(RGBAColor(46,223,223,255));
	pflock->pboidWeights(1.8f, 1.0f, 1.7f);	// separation, alignment, cohesion
	pflock->pboidViewDistance(85.0f);		// _viewdistance

	/*
	// red
	flock2 = new Flock(16);
	flock2->boidColor(RED);
	flock2->boidWeights(2.0f, 1.2f, 1.5f);	// separation, alignment, cohesion
	flock2->boidViewDistance(70.0f);		// _viewdistance
	*/
	this->addChild(flock1);
	this->addChild(pflock);
}


Scene01::~Scene01()
{
	delete flock1;
	delete pflock;
}

void Scene01::update(float deltaTime)
{
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}
