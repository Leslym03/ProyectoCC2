#pragma once
#include "GameAdmin.h"
//State
//un objeto altere su comportamiento cuando cambia su estado interno
class GameEstado {
public:
	virtual void Iniciar() = 0;
	virtual void Limpiar() = 0;

	virtual void Pausa() = 0;
	virtual void Reanudar() = 0;

	virtual void ProcesarEventos(GameAdmin* gameadm) = 0;
	virtual void Actualizar(GameAdmin* gameadm) = 0;
	virtual void Dibujar(GameAdmin* gameadm) = 0;

	void CambiarEstado(GameAdmin* gameadm, GameEstado* estado) {
		gameadm->CambiarEstado(estado);
	}

protected:
	GameEstado(){}
};