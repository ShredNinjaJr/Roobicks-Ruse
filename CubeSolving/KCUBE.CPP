// kcube.cpp - Kociemba Cube Solver main program
//
// This program implements an algorithm devised by Herbert
// Kociemba to solve Rubik's Cube.
//
// This program was written for educational purposes and
// may be freely distributed provided this header remains
// intact.  The author assumes no responsibility for its
// use.
//
#include "solver.h"     // Solver
#include "kocicube.h"	// KociembaCube
#include "facecube.h"	// FaceletCube
#include "cubepars.h"	// CubeParser

#include <stdlib.h>     // For exit()
#include <iostream.h>
//
// Command line format:
//
// >cube FaceSpecifier1, FaceSpecifier2, ... FaceSpecifier6
//
// where each face specifier is of the form f:mmmmmmmmm
//
// and f (face) must be one of {U,D,F,B,L,R} and m (marker)
// can be any printable ASCII character.  Grasp the left or
// right side of the cube with one hand and rotate it so that
// the face under consideration is in front of you.  The order
// of the markers is left-to-right, top-to-bottom with respect
// to each face.  For example, consider the following "unfolded"
// cube:
//              Red Red Wht
//              Yel Wht Wht
//              Wht Red Red
//
// Wht Wht Grn  Org Yel Yel  Blu Red Org  Yel Grn Grn
// Red Org Org  Yel Yel Yel  Blu Red Org  Blu Grn Blu
// Yel Wht Grn  Org Wht Org  Yel Blu Blu  Red Grn Red
//
//              Blu Org Blu
//              Grn Blu Grn
//              Wht Org Grn
//
// With the faces above corresponding to:
//
//      Up
// Left Front Right Back
//      Down
//
// Then one possible way to enter this configuration is:
//
// >cube L:WWGROOYWG R:BROBROYBB U:RRWYWWWRR D:BOBGBGWOG
//	F:OYYYYYOWO B:YGGBGBRGR
//
// Note: that the choice of marker characters is completely
// arbitrary, one must only use them consistently within
// any given cube configuration specification.  Also, the
// order of each face specification is arbitrary.
//
// When run, the program will first load the move mapping
// and pruning tables (it will regenerate them if not found)
// then perform the search.  Successively shorter solutions
// will be printed out until an optimal solution is found
// (that may take a very long time) and the program terminates,
// or the program is aborted by the user.
//
void main(int argc, char* argv[])
{
	unsigned int status;

	// Parse the input and initialize a "FaceletCube".
	// The FaceletCube represents the cube by the markings
	//   of the 54 individual facelets.

	FaceletCube faceletCube;
	CubeParser cubeParser;
	if ((status = cubeParser.ParseInput(argc, argv, faceletCube)) != CubeParser::VALID)
	{
		cout << cubeParser.ErrorText(status) << endl;
		exit(1);
	}

	// Validate the facelet representation in terms	of
	//   legal cubie markings, permutation, and parity
	//   and initialize a "standard" cube.  The standard
	//   cube represents the cube state in terms of cubie
	//   permutation and parity.
	
	KociembaCube cube;
	if ((status = faceletCube.Validate(cube)) != FaceletCube::VALID)
	{
		cout << faceletCube.ErrorText(status) << endl;
		exit(1);
	}

	// Create a solver, initialize the move mapping and
	//   pruning tables, and invoke the search for a
	//   solution.  Since the cube is in a valid configuration
	//   at this point, a solution should always be found.
	
	Solver solver;
	solver.InitializeTables();
	(void)solver.Solve(cube);
}	
