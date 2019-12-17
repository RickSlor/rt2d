/**
 * This file is part of SOF, made in RT2D
 */
#include <rt2d/core.h>
#include "scene01.h"

int main( void )
{
	// Core instance
	Core core;

	// scene handle
	Scene* scene = nullptr;

	scene = new Scene01();		// create Scene on the heap
	while(scene->isRunning()) {	// check status of Scene every frame
		core.run(scene);		// update and render the current scene
		core.showFrameRate(5);	// show framerate in output every 5 seconds
	}
	//core.cleanup();				// cleanup ResourceManager (Textures + Meshes, but not Shaders)
	delete scene;				// delete Scene from heap to make space for next one

	return 0;
}
