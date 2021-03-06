#include <cxxtest/TestSuite.h>
#include "vector.h"

class MyTestSuite : public CxxTest::TestSuite
{
public:

	void test_assign_vector(void){
		Vector a(5);
		Vector b(5);
		Vector c(1);
		Vector d(10);
		a[1] = 1;
		a[2] = 2;
		a = a;
		b = a;
		c = b;
		d = c;
	
		TS_ASSERT_EQUALS(b[1],1);
		TS_ASSERT_EQUALS(d[2],2);
	}

	void test_copy_vector(void){
		Vector a(5);
		a[0] = 1;
		a[3] = 2;
		Vector b = a;
		Vector c(b);
		TS_ASSERT_EQUALS(b[0],1);
		TS_ASSERT_EQUALS(c[3],2);
	}

	void test_rand(void){
		Vector a(5);
		TS_ASSERT_THROWS(a[5],std::out_of_range);
		TS_ASSERT_THROWS(a[5] = 1,std::out_of_range);
		TS_ASSERT_THROWS(a[-1],std::out_of_range);
	}

	void test_initialize_with_scalar(void){
		Vector a(5);
		a = {1,2,3};
		Vector b = {3,4,5};
		TS_ASSERT_EQUALS(a[1],2);
		TS_ASSERT_EQUALS(b[2],5);
		TS_ASSERT_THROWS(a[3],std::out_of_range);
	}

	void test_index_insertion(void){
		Vector a(5);
		int x = 3;
		Vector b = {1,2,3};
		a[1] = x;
		int y = b[1];
		TS_ASSERT_EQUALS(y,2);
		TS_ASSERT_EQUALS(a[1],3);

	}
};
