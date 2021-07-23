#include <cmath>
#include <iostream>

#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle( const Coordinates coor[] )
{
	setRectangle( coor );
}

void Rectangle::setRectangle( const Coordinates coor[] )
{
	for( int i = 0; i < 4; i++ ){
		rectangleCoordinates[ i ].x = isValid( coor[ i ].x )
		? coor[ i ].x : 1;
		
		rectangleCoordinates[ i ].y = isValid( coor[ i ].y )
		? coor[ i ].y : 1;
	}
	
	if( !isARectangle() ) {
		cout << "This is not a rectangle\n\n";
		exit(1);
	}
	else
		cout << "It is a rectangle\n\n";
}

double Rectangle::calculateLength() const
{
	int squaredDistance1 = calculateSquaredDistance
		( rectangleCoordinates[ 0 ], rectangleCoordinates[ 1 ] );
		
	int squaredDistance2 = calculateSquaredDistance
		( rectangleCoordinates[ 1 ], rectangleCoordinates[ 2 ] );
	
	return sqrt( maximum( squaredDistance1, squaredDistance2 ) );
}

double Rectangle::calculateWidth() const
{	
	int squaredDistance1 = calculateSquaredDistance
		( rectangleCoordinates[ 0 ], rectangleCoordinates[ 1 ] );
		
	int squaredDistance2 = calculateSquaredDistance
		( rectangleCoordinates[ 1 ], rectangleCoordinates[ 2 ] );
	
	return sqrt( minimum( squaredDistance1, squaredDistance2 ) );
}

double Rectangle::calculatePerimeter() const
{	
	int squaredDistance1 = calculateSquaredDistance
		( rectangleCoordinates[ 0 ], rectangleCoordinates[ 1 ] );
		
	int squaredDistance2 = calculateSquaredDistance
		( rectangleCoordinates[ 1 ], rectangleCoordinates[ 2 ] );
	
	return 2 * ( sqrt( squaredDistance1 ) + sqrt( squaredDistance2 ) );
}

double Rectangle::calculateArea() const
{	
	int squaredDistance1 = calculateSquaredDistance
		( rectangleCoordinates[ 0 ], rectangleCoordinates[ 1 ] );
		
	int squaredDistance2 = calculateSquaredDistance
		( rectangleCoordinates[ 1 ], rectangleCoordinates[ 2 ] );
		
	return ( sqrt( squaredDistance1 ) * sqrt( squaredDistance2 ) );
}

int Rectangle::isASquare() const
{
	int squaredDistance1 = calculateSquaredDistance
		( rectangleCoordinates[ 0 ], rectangleCoordinates[ 1 ] );
		
	int squaredDistance2 = calculateSquaredDistance
		( rectangleCoordinates[ 1 ], rectangleCoordinates[ 2 ] );
		
	return ( squaredDistance1 == squaredDistance2 );
}

int Rectangle::isValid( const int value ) const
{
	return ( value >= 0 && value < DIM_BOX ) ? 1 : 0;
}

int Rectangle::isARectangle() const
{		
	return distancesHaveEqualValues() 
	&& checkPythagoreanTheorem();
}

int Rectangle::calculateSquaredDistance
( const Coordinates &c1, const Coordinates &c2 ) const
{
	return ( pow( c1.x - c2.x, 2 ) + pow( c1.y - c2.y, 2 ) );
}

int Rectangle::distancesHaveEqualValues() const
{
	int squaredDistance1 = calculateSquaredDistance
		( rectangleCoordinates[ 0 ], rectangleCoordinates[ 1 ] );
		
	int squaredDistance2 = calculateSquaredDistance
		( rectangleCoordinates[ 1 ], rectangleCoordinates[ 2 ] );
		
	int squaredDistance3 = calculateSquaredDistance
		( rectangleCoordinates[ 2 ], rectangleCoordinates[ 3 ] );
		
	int squaredDistance4 = calculateSquaredDistance
		( rectangleCoordinates[ 3 ], rectangleCoordinates[ 0 ] );
			
	return ( squaredDistance1 == squaredDistance3 && 
	squaredDistance2 == squaredDistance4 );
}

int Rectangle::checkPythagoreanTheorem() const
{
	int squaredDistance1 = calculateSquaredDistance
		( rectangleCoordinates[ 0 ], rectangleCoordinates[ 1 ] );
		
	int squaredDistance2 = calculateSquaredDistance
		( rectangleCoordinates[ 1 ], rectangleCoordinates[ 2 ] );
	
	int squaredDiagonal = calculateSquaredDistance
		( rectangleCoordinates[ 0 ], rectangleCoordinates[ 2 ] );
		
	return ( squaredDiagonal == 
	squaredDistance1 + squaredDistance2 );
}

void Rectangle::draw() const
{
	char box[ DIM_BOX ][ DIM_BOX ];
	Coordinates point;
	int counter = 0;
	
	initializeBox( box );
	
	for( int j = 0; j < DIM_BOX; j++ ){
		for( int i = 0; i < DIM_BOX; i++ ){
			point.x = i;
			point.y = j;
			
			if( pointIsInsideRectangle( point ) ){
				box[ DIM_BOX - 1 - j ][ i ] = '*';
			}
		}
	}
	
	printBox( box );
}

void Rectangle::initializeBox( char box[][ DIM_BOX ]) const
{
	int i, j;
	
	for( j = 0; j < DIM_BOX; j++ )
		box[ 0 ][ j ] = '#';
	
	for( i = 1; i < DIM_BOX - 1; i++ ){
		box[ i ][ 0 ] = '#';
		
		for( j = 1; j < DIM_BOX - 1; j++ )
			box[ i ][ j ] = ' ';
		
		box[ i ][ DIM_BOX - 1 ] = '#';
	}
	
	for( j = 0; j < DIM_BOX; j++ )
		box[ DIM_BOX - 1 ][ j ] = '#';
}

void Rectangle::printBox( const char box[][ DIM_BOX ] ) const
{
	for( int i = 0; i < DIM_BOX; i++ ){
		for( int j = 0; j < DIM_BOX; j++ )
			cout << box[ i ][ j ] << ' ';
		
		cout << "\n";
	}
}

int Rectangle::pointIsInsideRectangle( const Coordinates p ) const
{	
	double area = calculateAreaOfTriangle
	( rectangleCoordinates[ 0 ], rectangleCoordinates[ 1 ], rectangleCoordinates[ 2 ] ) + 
	calculateAreaOfTriangle
	( rectangleCoordinates[ 0 ], rectangleCoordinates[ 2 ], rectangleCoordinates[ 3 ] ) ;
	
	double areaOfTriangle1 = calculateAreaOfTriangle
		( p, rectangleCoordinates[ 0 ], rectangleCoordinates[ 1 ] );
	
	double areaOfTriangle2 = calculateAreaOfTriangle
		( p, rectangleCoordinates[ 1 ], rectangleCoordinates[ 2 ] );
		
	double areaOfTriangle3 = calculateAreaOfTriangle
		( p, rectangleCoordinates[ 2 ], rectangleCoordinates[ 3 ] );
	
	double areaOfTriangle4 = calculateAreaOfTriangle
		( p, rectangleCoordinates[ 3 ], rectangleCoordinates[ 0 ] );
	
	return ( area == areaOfTriangle1 + areaOfTriangle2 +
		areaOfTriangle3 + areaOfTriangle4 );
}

double Rectangle::calculateAreaOfTriangle
( const Coordinates &c1, const Coordinates &c2, const Coordinates &c3) const
{
	return abs( ( c1.x * ( c2.y - c3.y ) + c2.x * ( c3.y - c1.y ) +  
    c3.x * ( c1.y - c2.y ) ) / 2.0 ); 
}

void Rectangle::translate( const int tx, const int ty )
{
	for( int i = 0; i < 4; i++ ){
		if( !isValid( rectangleCoordinates[ i ].x + tx ) ){
			cout << "Out of boundaries\n";
			return;
		}
		
		if( !isValid( rectangleCoordinates[ i ].y + ty ) ){
			cout << "Out of boundaries\n";
			return;
		}
	}
	
	for( int i = 0; i < 4; i++ ){
		rectangleCoordinates[ i ].x += tx;
		
		rectangleCoordinates[ i ].y += ty;
	}
}

void Rectangle::size( const int n )
{
	for( int i = 0; i < 4; i++ ){
		if( !isValid( rectangleCoordinates[ i ].x * n ) ){
			cout << "Out of boundaries\n";
			return;
		}
		
		if( !isValid( rectangleCoordinates[ i ].y * n ) ){
			cout << "Out of boundaries\n";
			return;
		}
	}
	
	for( int i = 0; i < 4; i++ ){
		rectangleCoordinates[ i ].x *= n;
		
		rectangleCoordinates[ i ].y *= n;
	}
}

void Rectangle::rotate( const int teta )
{
	double xT;
	double yT;
	double xR;
	double yR;
	double xC;
	double yC;
	double tetaInRadians = teta * PI / 180.0;
	int i;

	xC = ( rectangleCoordinates[ 0 ].x + rectangleCoordinates[ 2 ].x ) / 2.0;
	yC = ( rectangleCoordinates[ 0 ].y + rectangleCoordinates[ 2 ].y ) / 2.0;
	
	for( i = 0; i < 4; i++ ){
		
		//translation to xC, yC
		xT = rectangleCoordinates[ i ].x - xC;
		yT = rectangleCoordinates[ i ].y - yC;
		
		//rotation of angle teta
		xR = xT * cos( tetaInRadians ) - yT * sin( tetaInRadians );
		yR = xT * sin( tetaInRadians ) + yT * cos( tetaInRadians );
		
		//translation back to 0, 0
		xR += xC;
		yR += yC;
		
		if( !isValid( xR ) || !isValid( yR ) ){
			cout << "Out of boundaries\n";
			return;
		}
		else{
			rectangleCoordinates[ i ].x = round( xR );
			rectangleCoordinates[ i ].y = round( yR );
		}
	}
}

int Rectangle::maximum( const int a, const int b) const
{
	return ( a > b ) ? a : b;
}

int Rectangle::minimum( const int a, const int b) const
{
	return ( a < b ) ? a : b;
}

