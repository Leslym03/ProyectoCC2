#include <iostream>
#include "Entidad.h"
#include "GameMotor.h"

using namespace std;
using namespace sf;

Entidad::Entidad() {
	Cargado = false;
	setVelocidad(0.f, 0.f);
}

Entidad::Entidad(const char *texture) {
	setSprite(texture);
	reloj.restart();
	frame = 0;
	setVelocidad(0.f, 0.f);
}

Entidad::~Entidad() {

}

void Entidad::setSprite(const char *path) {
	if (!textura.loadFromFile(path)) {
		cout << "Error cargando imagen" << path;
		Cargado = false;
	}
	else {
		Cargado = true;
		sprite.setTexture(textura);
		setSize(textura.getSize().x, textura.getSize().y);
	}
}

void Entidad::setCentro(float x, float y) {
	if (Cargado) {
		sprite.setOrigin(x, y);
	}
}

void Entidad::setPosicion(float x, float y) {
	if (Cargado) {
		sprite.setPosition(x, y);
	}
}

Vector2f Entidad::getPosicion() {
	if (Cargado) {
		return sprite.getPosition();
	}
	return Vector2f();
}

Vector2u Entidad::getSize() {
	return size;
}

void Entidad::setSize(unsigned int x, unsigned int y) {
	size.x = x;
	size.y = y;
}

void Entidad::dibujar() {
	if (Cargado) {
		GameMotor &motor = *GameMotor::Instancia();
		motor.ventana.draw(sprite);
	}
}

void Entidad::movimiento(float x, float y) {
	if (Cargado) {
		sprite.move(x, y);
	}
}

void Entidad::setVelocidad(float x, float y) {
	velocidad.x = x;
	velocidad.y = y;
}

Vector2f Entidad::getVelocidad() {
	return velocidad;
}

void Entidad::setFrame(int row, int frame, float scaleX, float scaleY) {
	sprite.setTextureRect(IntRect(frame*size.x, row*size.y, size.x, size.y));
	sprite.setScale(scaleX, scaleY);
}

IntRect Entidad::getBounds() {
	IntRect r(getPosicion().x - getSize().x / 2 + 5, getPosicion().y - getSize().y / 2 + 5, getSize().x - 10, getSize().y - 5);
	return r;
}