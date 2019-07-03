#pragma once
#include "SFML/Graphics.hpp"
#include "Reloj.h"
using namespace sf;

class Entidad {
public:
	Entidad();
	Entidad(const char *texture);
	virtual ~Entidad();

	bool Cargado;
	Sprite sprite;
	Texture textura;

	void setSprite(const char *path);
	void setSize(unsigned int x, unsigned int y);
	void setPosicion(float x, float y);
	void setCentro(float x, float y);
	void setVelocidad(float x, float y);
	void setFrame(int row, int frame, float scaleX, float scaleY);

	Vector2f getPosicion();
	Vector2u getSize();
	Vector2f getVelocidad();
	IntRect getBounds();

	void dibujar();
	void movimiento(float x, float y);

	game::Reloj reloj;

	int frame;

protected:
	Vector2u size;
	Vector2f velocidad;

};