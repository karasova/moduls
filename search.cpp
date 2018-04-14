#include <iostream>
#include "search.h"
#include "geometry.h"

using namespace std;

void searchLargestTriangles(const Point* pointArray, int pointNum, Triangle* trArray, int maxTrNum) {
	if (maxTrNum <= 0)
		return;
	for (int i = 0; i < maxTrNum; i++)
		clearTriangle(trArray[i]);
	Triangle triangle;
	for (int i = 0; i < pointNum; i++)
	{
		triangle.vertexes[0] = pointArray[i];
		for (int j = i + 1; j < pointNum; j++)
		{
			triangle.vertexes[1] = pointArray[j];
			for (int k = j + 1; k < pointNum; k++)
			{
				triangle.vertexes[2] = pointArray[k];
				calcTrianglePer(triangle);
		//		cout << "new tr = "<<triangle.area<<endl;

				findAndInsert(trArray, maxTrNum, triangle);

//				for (int i = 0; i < maxTrNum; i++)
	//				cout << trArray[i].area<<endl;
			}
		}
	}
}

void findAndInsert(Triangle* trArray, int length, const Triangle& triangle)
{
	int pos;
	for (pos = length - 1; pos >= 0; pos--)
	{
		if (triangle.per <= trArray[pos].per)
			break;
	}
	pos++;
	if (pos == length)
		return;
	for (int m = length - 2; m >= pos; m--)
		trArray[m + 1] = trArray[m];
	trArray[pos] = triangle;
}

void clearTriangle(Triangle& tr)
{
	for (int i = 0; i < 3; i++)
		clearPoint(tr.vertexes[i]);
	tr.area = 0.0;
}

void clearPoint(Point& p)
{
	p.x = p.y = 0.0;
}