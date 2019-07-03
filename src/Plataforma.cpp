#include "SFML/Graphics.hpp"
#include "Plataforma.h"
#include "Recursos.h"
#include "GameMotor.h"
#include <iostream>

using namespace sf;

Plataforma::Plataforma() {

	setSprite(RUTA_PLATAFORMA);
	setSize(68, 14);
	setCentro(this->getSize().x / 2, this->getSize().y / 2);
	setFrame(0, 0, 1, 1);

	distancia = 0.f;
	spawn.x = 0.f;
	spawn.y = 0.f;
	setPosicion(spawn.x, spawn.y);
}

Plataforma::Plataforma(const Plataforma& orig) {
}

Plataforma::~Plataforma() {
}

void Plataforma::activar() {
	activa = true;
}

void Plataforma::setSpawn(float x, float y) {
	this->spawn.x = x;
	this->spawn.y = y;
}

