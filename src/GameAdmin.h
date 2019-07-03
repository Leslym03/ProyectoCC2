#pragma once
#include "SFML/Graphics.hpp"
#include "GameMotor.h"
#include <vector>

using namespace std;

class GameEstado;

class GameAdmin {
public:
	void Iniciar();
	void Limpiar();

	void ProcesarEventos();
	void Actualizar();
	void Dibujar();

	void CambiarEstado(GameEstado* estado);
	void PushEstado(GameEstado* estado);
	void PopEstado();

	bool Funcionando() { return m_funcionando;  }
	void Salir() { m_funcionando = false; }

private:
	vector<GameEstado*> estados;
	bool m_funcionando;
};