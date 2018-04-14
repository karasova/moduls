#ifndef _SEARCH_H
#define _SEARCH_H
#include "geometry.h"

void searchLargestTriangles(const Point* pointArray, int PointNum, Triangle* trArray, int maxTrNum);
void clearPoint(Point& p);
void clearTriangle(Triangle& tr);
void findAndInsert(Triangle* trArray, int length, const Triangle& triangle);
#endif
