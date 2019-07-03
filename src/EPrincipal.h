#pragma once
#include "GameEstado.h"
#include "Entidad.h"
#include "Plataforma.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <vector>
#include <iostream>
#include <fstream>


using namespace std;
using namespace sf;

class EPrincipal : public GameEstado {
public:
	void Iniciar();
	void Limpiar();

	void Pausa();
	void Reanudar();

	void ProcesarEventos(GameAdmin* gameadm);
	void Actualizar(GameAdmin* gameadm);
	void Dibujar(GameAdmin* gameadm);

	static EPrincipal* Instancia() {
		return &m_EPrincipal;
	}

	Plataforma plat[10];

protected:
	EPrincipal() {}

private:
	static EPrincipal m_EPrincipal;
	bool avanzar;
	bool salir;

	Entidad *fondo;
	Font *fuente1;
	Text *scoreText;
	Clock * reloj1;
	Time * tiempo1;
	float tiempo2;

	int playerX = 250;
	int playerY = 151;
	float dy = 0;
	int height = 150;
	int score = 0;

	//Cuadro delimitador del jugador. 
	//Debe modificarse según el tamaño de la imagen.
	const int PLAYER_LEFT_BOUNDING_BOX = 20;
	const int PLAYER_RIGHT_BOUNDING_BOX = 60;
	const int PLAYER_BOTTOM_BOUNDING_BOX = 70;
};