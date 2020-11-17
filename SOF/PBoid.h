/**
 * This file is part of SOF, made in RT2D
 */
#ifndef PBOID_H
#define PBOID_H

#include <vector>
#include <rt2d/entity.h>

class PBoid : public Entity
{
public:
	PBoid();
	virtual ~PBoid();

	void update(float deltaTime);
	virtual void updatePBoid();

	void flock(std::vector<PBoid*>& pboids);
	Vector2 _seek(Vector2 target);
	void _applyForce(Vector2 force);

	float _mass;
	float _radius;
	float _maxforce;
	float _maxspeed;
	float _desiredseparation;
	float _viewdistance;

	float _separationfactor;
	float _alignmentfactor;
	float _cohesionfactor;
	//float _xenofactor;

private:
	Vector2 _location;
	Vector2 _velocity;
	Vector2 _acceleration;
	Point2 mouse;

	int _bordermode;
	void _borders(int width, int height);
	void _mouse(int moX, int moY);

	Vector2 _separate(std::vector<PBoid*>& boids);
	Vector2 _align(std::vector<PBoid*>& boids);
	Vector2 _cohesion(std::vector<PBoid*>& boids);
};

#endif /* PBOID_H */
