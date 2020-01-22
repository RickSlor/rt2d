/**
 * This file is part of SOF, made in RT2D
 */
#ifndef SCENE01_H
#define SCENE01_H

#include <rt2d/scene.h>
#include "flock.h"

class Scene01: public Scene
{
	public:
		Scene01();
		virtual ~Scene01();

		virtual void update(float deltaTime);

	private:
		Flock* flock1;
		PFlock* pflock;
};

#endif /* SCENE01_H */
