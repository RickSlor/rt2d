/**
 * This file is part of SOF, made in RT2D
 */
#ifndef FLOCK_H
#define FLOCK_H

#include <vector>
#include <rt2d/entity.h>
#include "boid.h"
#include "PBoid.h"

class Flock: public Entity
{
	public:
		Flock(int amount);
		virtual ~Flock();


		virtual void update(float deltaTime);

		void boidColor(RGBAColor);
		void boidWeights(float sf, float af, float cf);
		void boidViewDistance(float vd);

	private:
		std::vector<Boid*> boids;
		Timer t;
		static int _nextGuid;
};

class PFlock : public Entity
{
public:
	PFlock(int amount);
	virtual ~PFlock();

	virtual void update(float deltaTime);
	void pboidColor(RGBAColor);
	void pboidWeights(float sf, float af, float cf);
	void pboidViewDistance(float vd);

private:
	std::vector<PBoid*> pboids;
	Timer t;
	int _nextGuid1;
};

#endif /* FLOCK_H */
