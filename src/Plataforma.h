#pragma once
#include "Entidad.h"
#include "SFML/Graphics.hpp"
using namespace sf;


class Plataforma : public Entidad {
public:
	Plataforma();
	Plataforma(const Plataforma& orig);
	virtual ~Plataforma();

	int rel;
	float distancia;
	bool activa;

	void activar();
	void setSpawn(float x, float y);
	int x, y;

private:
	Vector2f spawn;
};
