#pragma once
#include "GameEstado.h"
#include "Entidad.h"

class EMenu : public GameEstado {
public:
	void Iniciar();
	void Limpiar();

	void Pausa();
	void Reanudar();

	void ProcesarEventos(GameAdmin* gameadm);
	void Actualizar(GameAdmin* gameadm);
	void Dibujar(GameAdmin* gameadm);

	static EMenu* Instancia() {
		return &m_EMenu;
	}

protected:
	EMenu(){}

private:
	static EMenu m_EMenu;
	Entidad *inicio;
	bool avanzar;
	bool salir;

	Font *fuente1;
	Text *palabras;
};