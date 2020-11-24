/**
 * This file is part of SOF, made in RT2D
 */
#include <rt2d/scene.h>
#include "flock.h"

int Flock::_nextGuid = 0;
int PFlock::_nextGuid1 = 0;

//test

Flock::Flock(int amount)
	: Entity()
{
	srand((unsigned)time(nullptr)+_nextGuid);
	_nextGuid++;

	t.start();

	for (int i=0; i<amount; i++) {
		Boid* b = new Boid();
		b->sprite()->color = WHITE;
		boids.push_back(b);
		this->addChild(b);
	}
}

PFlock::PFlock(int amount)
	: Entity()
{
	srand((unsigned)time(nullptr) + _nextGuid1);
	_nextGuid1++;

	t.start();

	for (int i = 0; i < amount; i++) {
		PBoid* pb = new PBoid();
		pb->sprite()->color = WHITE;
		pboids.push_back(pb);
		this->addChild(pb);
	}
}


Flock::~Flock()
{
	int s = boids.size();
	for (int i=0; i<s; i++) {
		Boid* b = boids[i];
		this->removeChild(b);
		delete b;
	}
	boids.clear();
}

PFlock::~PFlock()
{
	int s = pboids.size();
	for (int i = 0; i < s; i++) {
		PBoid* pb = pboids[i];
		this->removeChild(pb);
		delete pb;
	}
	pboids.clear();
}

void Flock::update(float deltaTime)
{
	if (VSYNC) {
		int i;
		int s = boids.size();
		for (i = 0; i < s; i++) {
			boids[i]->flock(boids);
			boids[i]->updateBoid();
		}
	}
	else if (t.seconds() > (1.0f / 60.0f)) {
		int i;
		int s = boids.size();
		for (i = 0; i < s; i++) {
			boids[i]->flock(boids);
			boids[i]->updateBoid();
		}
		t.start();
	}
}
void PFlock::update(float deltaTime)
{
	if (VSYNC) {
		int i;
		int s = pboids.size();
		for (i = 0; i < s; i++) {
			pboids[i]->flock(pboids);
			pboids[i]->updatePBoid();
		}
	}
	else if (t.seconds() > (1.0f / 60.0f)) {
		int i;
		int s = pboids.size();
		for (i = 0; i < s; i++) {
			pboids[i]->flock(pboids);
			pboids[i]->updatePBoid();
		}
		t.start();
	}
}
	/*
	int mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	int mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mouse = Point2(mousex, mousey);
	*/

	void PFlock::pboidColor(RGBAColor c)
	{
		int s = pboids.size();
		for (int i = 0; i < s; i++) {
			Sprite* s = pboids[i]->sprite();
			s->color = c;
		}
	}

	void PFlock::pboidWeights(float sf, float af, float cf)
	{
		int s = pboids.size();
		for (int i = 0; i < s; i++) {
			pboids[i]->_separationfactor = sf;
			pboids[i]->_alignmentfactor = af;
			pboids[i]->_cohesionfactor = cf;
		}
	}

	void PFlock::pboidViewDistance(float vd)
	{
		int s = pboids.size();
		for (int i = 0; i < s; i++) {
			pboids[i]->_viewdistance = vd;
		}
	}


void Flock::boidColor(RGBAColor c)
{
	int s = boids.size();
	for (int i=0; i<s; i++) {
		Sprite* s = boids[i]->sprite();
		s->color = c;
	}
}

void Flock::boidWeights(float sf, float af, float cf)
{
	int s = boids.size();
	for (int i=0; i<s; i++) {
		boids[i]->_separationfactor = sf;
		boids[i]->_alignmentfactor = af;
		boids[i]->_cohesionfactor = cf;
	}
}

void Flock::boidViewDistance(float vd)
{
	int s = boids.size();
	for (int i=0; i<s; i++) {
		boids[i]->_viewdistance = vd;
	}
}



