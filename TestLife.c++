/**
 * To test the program:
		g++ -pedantic -lcppunit -ldl -Wall TestLife.c++ -o TestLife.app
		valgrind ./TestLife.app >& TestLife.out
 */

// --------
// includes
// --------
#include "cppunit/extensions/HelperMacros.h"	// CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"				// TestFixture
#include "cppunit/TextTestRunner.h"				// TestRunner

// OUR INCLUDES HERE
#define private public
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"

using namespace std;

// --------
// TestLife
// --------
struct TestLife : CppUnit::TestFixture {

	// ---------------------
	// test_life_constructor
	// ---------------------

	void test_life_constructor_0 ()
	{
		try{
			ifstream infile("plain20x20.in", ifstream::in);
			Life<ConwayCell> l(infile);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_life_constructor_1 ()
	{
		try{
			ifstream infile("plain20x20.in", ifstream::in);
			Life<FredkinCell> l(infile);
			CPPUNIT_ASSERT(false);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(true);
        }
	}

	void test_life_constructor_2 ()
	{
		try{
			ifstream infile("RunLifeFredkin.in", ifstream::in);
			Life<FredkinCell> l(infile);
			CPPUNIT_ASSERT(true);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	// ---------------------
	// test_cell_constructor
	// ---------------------

	void test_cell_constructor_0 ()
	{
		try{
			Cell cc('.');
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_cell_constructor_1 ()
	{
		try{
			Cell cc('*');
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_cell_constructor_2 ()
	{
		try{
			Cell cc('-');
			CPPUNIT_ASSERT(false);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(true);
        }
	}
	
    // -----------------------
	// test_conway_constructor
	// -----------------------

	void test_conway_constructor_0 ()
	{
		try{
			ConwayCell cc;
			CPPUNIT_ASSERT(cc.status == '.');
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_conway_constructor_1 ()
	{
		try{
			ConwayCell cc('*');
			CPPUNIT_ASSERT(cc.status == '*');
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_conway_constructor_2 ()
	{
		try{
			ConwayCell cc('-');
			CPPUNIT_ASSERT(false);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(true);
        }
	}

	// ------------------------
	// test_fredkin_constructor
	// ------------------------

	void test_fredkin_constructor_0 ()
	{
		try{
			FredkinCell fc;
			CPPUNIT_ASSERT(fc.status == '-');
			CPPUNIT_ASSERT(fc.age == 0);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_fredkin_constructor_1 ()
	{
		try{
			FredkinCell fc('+');
			CPPUNIT_ASSERT(fc.status == '+');
			CPPUNIT_ASSERT(fc.age == 10);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_fredkin_constructor_2 ()
	{
		try{
			FredkinCell fc('5');
			CPPUNIT_ASSERT(fc.status == '5');
			CPPUNIT_ASSERT(fc.age == 5);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_fredkin_constructor_3 ()
	{
		try{
			FredkinCell fc('o');
			CPPUNIT_ASSERT(false);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(true);
        }
	}

	void test_fredkin_constructor_4 ()
	{
		try{
			FredkinCell fc('+', 9);
			CPPUNIT_ASSERT(fc.status == '+');
			CPPUNIT_ASSERT(fc.age == 9);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	// ---------------
	// test_get_status
	// ---------------

	void test_get_status_0 ()
	{
		try{
			FredkinCell fc('+', 9);
			char status = fc.get_status();
			CPPUNIT_ASSERT(status == '+');

		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_get_status_1 ()
	{
		try{
			ConwayCell cc('.');
			char status = cc.get_status();
			CPPUNIT_ASSERT(status == '.');

		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_get_status_2 ()
	{
		try{
			Cell c('-');
			char status = c.get_status();
			CPPUNIT_ASSERT(status == '-');

		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	// -------------
	// test_in_bound
	// -------------

	void test_in_bound_0 ()
	{
		try{
			ifstream infile("plain20x20.in", ifstream::in);
			Life<ConwayCell> l(infile);
			bool bound = l.in_bound(20, 20);
			CPPUNIT_ASSERT(bound == false);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_in_bound_1 ()
	{
		try{
			ifstream infile("plain20x20.in", ifstream::in);
			Life<ConwayCell> l(infile);
			bool bound = l.in_bound(19, 19);
			CPPUNIT_ASSERT(bound == true);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_in_bound_2 ()
	{
		try{
			ifstream infile("plain20x20.in", ifstream::in);
			Life<ConwayCell> l(infile);
			bool bound = l.in_bound(10, 10);
			CPPUNIT_ASSERT(bound == true);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	// -------------
	// test_run
	// -------------

	void test_run_0 ()
	{
		try{
			ifstream infile("plain20x20.in", ifstream::in);
			Life<ConwayCell> l(infile);
			l.run(1);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_run_1 ()
	{
		try{
			ifstream infile("plain20x20.in", ifstream::in);
			Life<ConwayCell> l(infile);
			l.run(0);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_run_2 ()
	{
		try{
			ifstream infile("plain20x20.in", ifstream::in);
			Life<ConwayCell> l(infile);
			l.run(10);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_run_3 ()
	{
		try{
			ifstream infile("plain20x20.in", ifstream::in);
			Life<ConwayCell> l(infile);
			l.run(100);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	// ---------------------
	// test_get_num_neighbor
	// ---------------------

	void test_get_num_neighbor_0 ()
	{
		try{
			ifstream infile("RunLife.in", ifstream::in);
			Life<Cell> l(infile);
			size_t n = (*((*(l.cur_world))[10][10])).get_num_neighbor();
			CPPUNIT_ASSERT(n == 4);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_get_num_neighbor_1 ()
	{
		try{
			ifstream infile("RunLifeConway.in", ifstream::in);
			Life<ConwayCell> l(infile);
			size_t n = (*((*(l.cur_world))[49][34])).get_num_neighbor();
			CPPUNIT_ASSERT(n == 8);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_get_num_neighbor_2 ()
	{
		try{
			ifstream infile("RunLifeFredkin.in", ifstream::in);
			Life<FredkinCell> l(infile);
			size_t n = (*((*(l.cur_world))[9][9])).get_num_neighbor();
			CPPUNIT_ASSERT(n == 4);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_get_num_neighbor_3 ()
	{
		try{
			ifstream infile("RunLife.in", ifstream::in);
			Life<Cell> l(infile);
			size_t n = (*((*(l.cur_world))[0][0])).get_num_neighbor();
			CPPUNIT_ASSERT(n == 4);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_get_num_neighbor_4 ()
	{
		try{
			ifstream infile("RunLifeConway.in", ifstream::in);
			Life<ConwayCell> l(infile);
			size_t n = (*((*(l.cur_world))[0][0])).get_num_neighbor();
			CPPUNIT_ASSERT(n == 8);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_get_num_neighbor_5 ()
	{
		try{
			ifstream infile("RunLifeFredkin.in", ifstream::in);
			Life<FredkinCell> l(infile);
			size_t n = (*((*(l.cur_world))[1][0])).get_num_neighbor();
			CPPUNIT_ASSERT(n == 4);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_get_num_neighbor_6 ()
	{
		try{
			ifstream infile("RunLifeConway.in", ifstream::in);
			Life<ConwayCell> l(infile);
			size_t n = (*((*(l.cur_world))[0][1])).get_num_neighbor();
			CPPUNIT_ASSERT(n == 8);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	// ------------
	// test_get_vec
	// ------------

	void test_get_vec_0 ()
	{
		try{
			ifstream infile("RunLife.in", ifstream::in);
			Life<Cell> l(infile);
			int n = (*((*(l.cur_world))[10][10])).get_vec(0, 1);
			CPPUNIT_ASSERT(n == -1);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_get_vec_1 ()
	{
		try{
			ifstream infile("RunLifeFredkin.in", ifstream::in);
			Life<FredkinCell> l(infile);
			int n = (*((*(l.cur_world))[10][10])).get_vec(3, 0);
			CPPUNIT_ASSERT(n == 1);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_get_vec_2 ()
	{
		try{
			ifstream infile("RunLifeFredkin.in", ifstream::in);
			Life<FredkinCell> l(infile);
			(*((*(l.cur_world))[10][10])).get_vec(4, 0);
			CPPUNIT_ASSERT(false);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(true);
        }
	}

	void test_get_vec_3 ()
	{
		try{
			ifstream infile("RunLifeConway.in", ifstream::in);
			Life<ConwayCell> l(infile);
			int n = (*((*(l.cur_world))[10][10])).get_vec(0, 1);
			CPPUNIT_ASSERT(n == -1);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_get_vec_4 ()
	{
		try{
			ifstream infile("RunLifeConway.in", ifstream::in);
			Life<ConwayCell> l(infile);
			int n = (*((*(l.cur_world))[10][10])).get_vec(3, 0);
			CPPUNIT_ASSERT(n == 1);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_get_vec_5 ()
	{
		try{
			ifstream infile("RunLifeConway.in", ifstream::in);
			Life<ConwayCell> l(infile);
			int n = (*((*(l.cur_world))[10][10])).get_vec(4, 1);
			CPPUNIT_ASSERT(n == -1);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_get_vec_6 ()
	{
		try{
			ifstream infile("RunLifeConway.in", ifstream::in);
			Life<ConwayCell> l(infile);
			(*((*(l.cur_world))[10][10])).get_vec(8, 0);
			CPPUNIT_ASSERT(false);
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(true);
        }
	}

	// -----------
	// test_update
	// -----------

	void test_update_0 ()
	{
		try{
			ifstream infile("RunLife.in", ifstream::in);
			Life<FredkinCell> l(infile);
			FredkinCell c = (*((*(l.cur_world))[10][7]));
			CPPUNIT_ASSERT(c.status == '-');
			c = *(c.update(1));
			CPPUNIT_ASSERT(c.status == '0');
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}


	void test_update_1 ()
	{
		try{
			ifstream infile("RunLife.in", ifstream::in);
			Life<FredkinCell> l(infile);
			FredkinCell c = (*((*(l.cur_world))[10][10]));
			CPPUNIT_ASSERT(c.status == '0');
			c = *(c.update(2));
			CPPUNIT_ASSERT(c.status == '-');
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}


	void test_update_2 ()
	{
		try{
			ifstream infile("RunLifeConway.in", ifstream::in);
			Life<ConwayCell> l(infile);
			ConwayCell c = (*((*(l.cur_world))[34][34]));
			CPPUNIT_ASSERT(c.status == '*');
			c = *(c.update(1));
			CPPUNIT_ASSERT(c.status == '.');
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	void test_update_3 ()
	{
		try{
			ifstream infile("RunLifeConway.in", ifstream::in);
			Life<ConwayCell> l(infile);
			ConwayCell c = (*((*(l.cur_world))[0][0]));
			CPPUNIT_ASSERT(c.status == '.');
			c = *(c.update(3));
			CPPUNIT_ASSERT(c.status == '*');
		}

		catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}

	CPPUNIT_TEST_SUITE(TestLife);

    CPPUNIT_TEST(test_life_constructor_0);
    CPPUNIT_TEST(test_life_constructor_1);
    CPPUNIT_TEST(test_life_constructor_2);
    CPPUNIT_TEST(test_cell_constructor_0);
    CPPUNIT_TEST(test_cell_constructor_1);
    CPPUNIT_TEST(test_cell_constructor_2);
    CPPUNIT_TEST(test_conway_constructor_0);
    CPPUNIT_TEST(test_conway_constructor_1);
    CPPUNIT_TEST(test_conway_constructor_2);
    CPPUNIT_TEST(test_fredkin_constructor_0);
    CPPUNIT_TEST(test_fredkin_constructor_1);
    CPPUNIT_TEST(test_fredkin_constructor_2);
    CPPUNIT_TEST(test_fredkin_constructor_3);
    CPPUNIT_TEST(test_fredkin_constructor_4);
    CPPUNIT_TEST(test_get_status_0);
    CPPUNIT_TEST(test_get_status_1);
    CPPUNIT_TEST(test_get_status_2);
    CPPUNIT_TEST(test_in_bound_0);
    CPPUNIT_TEST(test_in_bound_1);
    CPPUNIT_TEST(test_in_bound_2);
    CPPUNIT_TEST(test_run_0);
    CPPUNIT_TEST(test_run_1);
    CPPUNIT_TEST(test_run_2);
    CPPUNIT_TEST(test_run_3);
    CPPUNIT_TEST(test_get_num_neighbor_0);
    CPPUNIT_TEST(test_get_num_neighbor_1);
    CPPUNIT_TEST(test_get_num_neighbor_2);
    CPPUNIT_TEST(test_get_num_neighbor_3);
    CPPUNIT_TEST(test_get_num_neighbor_4);
    CPPUNIT_TEST(test_get_num_neighbor_5);
    CPPUNIT_TEST(test_get_num_neighbor_6);
    CPPUNIT_TEST(test_get_vec_0);
    CPPUNIT_TEST(test_get_vec_1);
    CPPUNIT_TEST(test_get_vec_2);
    CPPUNIT_TEST(test_get_vec_3);
    CPPUNIT_TEST(test_get_vec_4);
    CPPUNIT_TEST(test_get_vec_5);
    CPPUNIT_TEST(test_get_vec_6);
    CPPUNIT_TEST(test_update_0);
    CPPUNIT_TEST(test_update_1);
    CPPUNIT_TEST(test_update_2);
    CPPUNIT_TEST(test_update_3);

    CPPUNIT_TEST_SUITE_END();
};

// ----
// main
// ----
int main () {
	using namespace std;
	ios_base::sync_with_stdio(false);	// turn off synchronization with C I/O
	cout << "TestLife.c++" << endl;

	CppUnit::TextTestRunner tr;
	tr.addTest(TestLife::suite());
	tr.run();

	cout << "Done." << endl;
	return 0;
}
