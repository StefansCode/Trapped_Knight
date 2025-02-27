#ifndef TRAPPEDKNIGHT_H
#define TRAPPEDKNIGHT_H

extern int Field_size;

int Feldwert(int x, int y);

int* TK(int* output, int x_start, int y_start, int x_movement, int y_movement);

void print_spiral(int size);

void print_Ulam(int size);


#endif //TRAPPEDKNIGHT_H
