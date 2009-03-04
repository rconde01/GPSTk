#ifndef XJULIANDATE_HPP
#define XJULIANDATE_HPP

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "JulianDate.hpp"

using namespace std;

class xJulianDate: public CPPUNIT_NS :: TestFixture
{
	CPPUNIT_TEST_SUITE (xJulianDate);
	CPPUNIT_TEST (setFromInfoTest);
	CPPUNIT_TEST (operatorTest);
	CPPUNIT_TEST_SUITE_END ();

	public:
		void setUp (void);

	protected:
		void operatorTest (void);
		void setFromInfoTest (void);

	private:

};

#endif