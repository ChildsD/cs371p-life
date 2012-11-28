// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2012
// Glenn P. Downing
// -------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall RunLife.c++ -o RunLife.c++.app
    % valgrind ./RunLife.c++.app >& RunLife.out

To configure Doxygen:
    doxygen -g
That creates the file Doxyfile.
Make the following edits:
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO

To document the program:
    doxygen Doxyfile
*/

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <fstream>
#include <sstream>
#include <stdexcept> // invalid_argument, out_of_range
#include <string>

//#define _POSIX_SOURCE
//#include <unistd.h>

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    // ------------------
    // Conway Cell 109x69
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 109x69 ***" << endl;
        /*
        read RunLifeConway.in // assume all Conway cells
        Print grid.
        Simulate 283 moves.
        Print grid.
        Simulate 40 moves.
        Print grid.
        Simulate 2500 moves.
        Print grid.
        */
        ifstream infile("RunLifeConway.in");
        //char * dir = getcwd(NULL, 0);
        //printf("Current dir: %s", dir);
        
        Life<ConwayCell> exe(infile);
        exe.print(cout);
        exe.run(283);
        exe.print(cout);
        exe.run(40);
        exe.print(cout);
        exe.run(2500);
        exe.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Print grid.
        Simulate 2 moves.
        Print every grid.
        */
        
        ifstream infile("RunLifeFredkin.in");
        
        Life<FredkinCell> exe(infile);
        exe.print(cout);
        exe.run(1);
        exe.print(cout);
        exe.run(1);
        exe.print(cout);
        
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 20x20
    // ----------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Print grid.
        Simulate 5 moves.
        Print every grid.
        */
        ifstream infile("RunLife.in");
        
        Life<Cell> exe(infile);
        exe.print(cout);
        for (int i=0; i<5; ++i) {
            exe.run(1);
            exe.print(cout);
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // BEGIN OUR ACCEPTANCE TESTS
    // ##########################

    // --------
    // Cell 5x5
    // --------
    try {

        cout << "*** Life<Cell> 5x5 ***" << endl;
        
        ifstream infile("RunLifeCell5x5.in");
        
        Life<FredkinCell> exe(infile);
        exe.print(cout);
        exe.run(10);
        exe.print(cout);
        exe.run(20);
        exe.print(cout);
        exe.run(50);
        exe.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 10x10
    // ----------
    try {

        cout << "*** Life<Cell> 10x10 ***" << endl;

        ifstream infile("RunLifeCell10x10.in");
        
        Life<FredkinCell> exe(infile);
        exe.print(cout);
        exe.run(10);
        exe.print(cout);
        exe.run(20);
        exe.print(cout);
        exe.run(50);
        exe.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 20x20
    // ----------
    try {

        cout << "*** Life<Cell> 20x20 ***" << endl;

        ifstream infile("RunLifeCell20x20.in");
        
        Life<FredkinCell> exe(infile);
        exe.print(cout);
        exe.run(10);
        exe.print(cout);
        exe.run(20);
        exe.print(cout);
        exe.run(50);
        exe.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 50x50
    // ----------
    try {

        cout << "*** Life<Cell> 50x50 ***" << endl;

        ifstream infile("RunLifeCell50x50.in");
        
        Life<FredkinCell> exe(infile);
        exe.print(cout);
        exe.run(1);
        exe.print(cout);
        exe.run(5);
        exe.print(cout);
        exe.run(10);
        exe.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---------------
    // Conway Cell 5x5
    // ---------------
    try {

        cout << "*** Life<ConwayCell> 5x5 ***" << endl;
        
        ifstream infile("RunLifeConway5x5.in");
        
        Life<ConwayCell> exe(infile);
        exe.print(cout);
        exe.run(10);
        exe.print(cout);
        exe.run(20);
        exe.print(cout);
        exe.run(50);
        exe.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // Conway Cell 10x10
    // -----------------
    try {

        cout << "*** Life<ConwayCell> 10x10 ***" << endl;
        
        ifstream infile("RunLifeConway10x10.in");
        
        Life<ConwayCell> exe(infile);
        exe.print(cout);
        exe.run(10);
        exe.print(cout);
        exe.run(20);
        exe.print(cout);
        exe.run(50);
        exe.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // Conway Cell 20x20
    // -----------------
    try {

        cout << "*** Life<ConwayCell> 20x20 ***" << endl;

        ifstream infile("RunLifeConway20x20.in");
        
        Life<ConwayCell> exe(infile);
        exe.print(cout);
        exe.run(10);
        exe.print(cout);
        exe.run(20);
        exe.print(cout);
        exe.run(50);
        exe.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // Conway Cell 50x50
    // -----------------
    try {

        cout << "*** Life<ConwayCell> 50x50 ***" << endl;

        ifstream infile("RunLifeConway50x50.in");
        
        Life<ConwayCell> exe(infile);
        exe.print(cout);
        exe.run(1);
        exe.print(cout);
        exe.run(5);
        exe.print(cout);
        exe.run(10);
        exe.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Fredkin Cell 5x5
    // ----------------
    try {

        cout << "*** Life<FredkinCell> 5x5 ***" << endl;
        
        ifstream infile("RunLifeFredkin5x5.in");
        
        Life<FredkinCell> exe(infile);
        exe.print(cout);
        exe.run(10);
        exe.print(cout);
        exe.run(20);
        exe.print(cout);
        exe.run(50);
        exe.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 10x10
    // ------------------
    try {

        cout << "*** Life<FredkinCell> 10x10 ***" << endl;
        
        ifstream infile("RunLifeFredkin10x10.in");
        
        Life<FredkinCell> exe(infile);
        exe.print(cout);
        exe.run(10);
        exe.print(cout);
        exe.run(20);
        exe.print(cout);
        exe.run(50);
        exe.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 20x20
    // ------------------
    try {

        cout << "*** Life<FredkinCell> 20x20 ***" << endl;

        ifstream infile("RunLifeFredkin20x20.in");
        
        Life<FredkinCell> exe(infile);
        exe.print(cout);
        exe.run(10);
        exe.print(cout);
        exe.run(20);
        exe.print(cout);
        exe.run(50);
        exe.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 50x50
    // ------------------
    try {

        cout << "*** Life<FredkinCell> 50x50 ***" << endl;

        ifstream infile("RunLifeFredkin50x50.in");
        
        Life<FredkinCell> exe(infile);
        exe.print(cout);
        exe.run(1);
        exe.print(cout);
        exe.run(5);
        exe.print(cout);
        exe.run(10);
        exe.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}