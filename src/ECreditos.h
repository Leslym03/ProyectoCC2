#pragma once
#include "GameEstado.h"
#include "Entidad.h"
#include <fstream>

class ECreditos : public GameEstado {
public:
	void Iniciar();
	void Limpiar();

	void Pausa();
	void Reanudar();

	void ProcesarEventos(GameAdmin* gameadm);
	void Actualizar(GameAdmin* gameadm);
	void Dibujar(GameAdmin* gameadm);

	static ECreditos* Instancia() {
		return &m_ECreditos;
	}
	game::Reloj reloj;

protected:
	ECreditos() {}

private:
	static ECreditos m_ECreditos;
	Entidad *fondo;
	bool avanzar;
	bool salir;

	Font *fuente1;
	Text *palabras;
	Text *obtenido;

};