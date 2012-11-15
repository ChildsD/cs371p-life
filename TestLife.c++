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

#include <stdexcept>

// ----------
// TestDarwin
// ----------
struct TestLife : CppUnit::TestFixture {
	
    // --------
	// testGrid
	// --------
	void testGrid0 () 
    {
    	try {
            // OUR CODE HERE
    	}

    	catch (const std::exception &e) {
    		CPPUNIT_ASSERT(false);
        }
	}


	CPPUNIT_TEST_SUITE(TestLife);

    CPPUNIT_TEST(testGrid0);

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
