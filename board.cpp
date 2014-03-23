#include "board.h"

Board::Board(unsigned int rows, unsigned int columns) {
	this->rows = rows;
	this->columns = columns;

	/*
	 * Se usa new como estandar de C++ y por ser estatica
	 * la memoria a asignar, si fuera dinamica, se 
	 * usaría malloc() -> realloc();
	 *
	 * Se asigna la memoria de las filas.
	 */

	data = new token_t * [rows];

	/*
	 * Se asigna la memoria en cada fila, de las
	 * columnas destinadas.
	 */

    for (unsigned int i = 0; i < rows; ++i) {
		data[i] = new token_t[columns]; 
	}
}

Board::~Board() {
    /*
     * Se borran los datos de la memoria.
     */

    for (unsigned int i = 0; i < rows; ++i) {
        delete [] data[i];
    }

    /*
     * Se borra los restantes de la matriz.
     */

    delete [] data;
}

void Board::setDataAt(unsigned int row, unsigned int col, token_t val) {
    if (row < rows && col < columns) data[row][col] = val;
}

token_t Board::getDataAt(unsigned int row, unsigned int col) const {
    if (row < rows && col < columns) return data[row][col];

    return NIL;
}

token_t ** Board::getContext() const {
	return data;
}

unsigned int Board::getRows() {
    return rows;
}

unsigned int Board::getColumns() {
    return columns;
}
