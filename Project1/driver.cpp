#include "array.h"
#include <iostream>
#include <iomanip>

void test0() {
    //std::cout << "in function " << __FUNCTION__ << ": " << "create empty array" << std::endl;
    std::cout << "create empty array" << std::endl;
    CS225::Array array;

    std::cout << "create Integer(1)" << std::endl;
    CS225::Integer val( 1 );
    std::cout << "insert Integer(1) at 1" << std::endl;
    array.Insert( 1, val );
    std::cout << "array = " << array << std::endl;

    std::cout << "create Integer(2)" << std::endl;
    CS225::Integer val2( 2 );
    std::cout << "insert Integer(2) at 5" << std::endl;
    array.Insert( 5, val2 );
    std::cout << "array = " << array << std::endl;
}
void test1() {
    std::cout << "create empty array" << std::endl;
    CS225::Array array;

    std::cout << "create Integer(1)" << std::endl;
    CS225::Integer val( 1 );
    std::cout << "insert Integer(1) at 5" << std::endl;
    array.Insert( 5, val );

    CS225::Integer val3( 3 );
    array[3] = val3;
    std::cout << "array = " << array << std::endl;
}
void test2() {
    std::cout << "create empty array" << std::endl;
    CS225::Array array;

    std::cout << "create Integer(1)" << std::endl;
    CS225::Integer val( 1 );
    std::cout << "insert Integer(1) at 5" << std::endl;
    array.Insert( 5, val );

    std::cout << "array[3] = " << array[3] << std::endl;
    std::cout << "array[5] = " << array[5] << std::endl;
}
void test3() {
    std::cout << "create empty array" << std::endl;
    CS225::Array array;

    std::cout << "create Integer(6)" << std::endl;
    CS225::Integer val( 6 );
    std::cout << "insert Integer(6) at 3 and 5" << std::endl;
    array[3] = val;
    array[5] = val;

    for ( int i=0; i<6; ++i ) {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }
}

// tests using copy ctor and assignment
void test4() {
    CS225::Integer::noise = false;
    std::cout << "create empty array" << std::endl;
    CS225::Array array;

    for ( int i=0; i<6; ++i ) {
        array[i] = i+2; // use implicit conversion int->Integer
    }

    std::cout << "array = " << array << std::endl;

    CS225::Integer::noise = true;
    std::cout << "create shallow copy" << std::endl;
    CS225::Array array_copy( array ); // shallow copy
    std::cout << "create shallow copy - done, no output expected" << std::endl;
    
        std::cout << "position    array    array_copy" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << "    " <<   i << "          " << array[i] << "          " << array_copy[i] << std::endl;
    }
}
void test5() {
    CS225::Integer::noise = false;
    std::cout << "create empty array" << std::endl;
    CS225::Array array;

    for ( int i=0; i<6; ++i ) {
        array[i] = i+2; // use implicit conversion int->Integer
    }

    std::cout << "array = " << array << std::endl;

    CS225::Integer::noise = true;
    std::cout << "create shallow copy" << std::endl;
    CS225::Array array_copy( array ); // shallow copy
    std::cout << "create shallow copy - done, no output expected" << std::endl;
   
    std::cout << "modify original (should cause deep copy)" << std::endl;
    array[3] = 100;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array_copy" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array_copy[i] << std::endl;
    }
    
    std::cout << "modify original again (NO deep copy this time )" << std::endl;
    array[2] = 100;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array_copy" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array_copy[i] << std::endl;
    }

    std::cout << "modify copy (NO deep copy - original created it's own copy, so array_copy ref counter is 1)" << std::endl;
    array_copy[1] = 100;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array_copy" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array_copy[i] << std::endl;
    }
}
void test6() {
    CS225::Integer::noise = false;
    std::cout << "create empty array" << std::endl;
    CS225::Array array;

    for ( int i=0; i<6; ++i ) {
        array[i] = i+2;
    }
    std::cout << "array = " << array << std::endl;

    std::cout << "create another " << std::endl;
    CS225::Array array2;
    for ( int i=0; i<6; ++i ) {
        array2[i] = i+20;
    }
    std::cout << "array2 = " << array2 << std::endl;
    std::cout << "-------------------" << std::endl;
    
    
    CS225::Integer::noise = true;
    array2 = array; 
    std::cout << "create shallow assign - done, no output expected" << std::endl;
   
    std::cout << "modify original (should cause deep copy)" << std::endl;
    array[3] = -10;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::endl;
    }
    
    std::cout << "modify original again (NO deep copy this time )" << std::endl;
    array[2] = -10;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::endl;
    }

    std::cout << "modify copy (NO deep copy - original created it's own copy, so array2 ref counter is 1)" << std::endl;
    array2[1] = 1000;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::endl;
    }
}
void test7() {
    CS225::Integer::noise = false;
    std::cout << "create empty array" << std::endl;
    CS225::Array array;

    for ( int i=0; i<6; ++i ) {
        array[i] = i+2;
    }
    std::cout << "array = " << array << std::endl;

    std::cout << "create another " << std::endl;
    CS225::Array array2;
    for ( int i=0; i<6; ++i ) {
        array2[i] = i+20;
    }
    std::cout << "array2 = " << array2 << std::endl;
    
    std::cout << "create yet another " << std::endl;
    CS225::Array array3;
    for ( int i=0; i<6; ++i ) {
        array3[i] = i+200;
    }
    std::cout << "array3 = " << array3 << std::endl;
    std::cout << "-------------------" << std::endl;
    
    
    CS225::Integer::noise = true;
    array2 = array3; 
    array = array2; 
    std::cout << "2 shallow assigns - done, no output expected" << std::endl;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }
    
    std::cout << "modify original (should cause deep copy)" << std::endl;
    array[3] = -10;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }
    
    std::cout << "modify original again (NO deep copy this time )" << std::endl;
    array[2] = -10;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }

    std::cout << "modify copy (should cause deep copy, array2 ref counter is 2 - shared with array3)" << std::endl;
    array2[1] = 1000;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }
}
void test8() {
    CS225::Integer::noise = false;
    std::cout << "create empty array" << std::endl;
    CS225::Array array;

    for ( int i=0; i<6; ++i ) {
        array[i] = i+2;
    }

    CS225::Integer::noise = true;
    std::cout << "-------------------" << std::endl;
    std::cout << "create copy " << std::endl;
    CS225::Array array2( array );
    
    std::cout << "another copy" << std::endl;
    CS225::Array array3( array );

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }
    std::cout << "-------------------" << std::endl;
    
    std::cout << "modify original (should cause deep copy)" << std::endl;
    array[3] = -10;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }
    
    std::cout << "modify original again (NO deep copy this time )" << std::endl;
    array[2] = -10;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }

    std::cout << "modify copy (should cause deep copy, array2 ref counter is 2 - shared with array3)" << std::endl;
    array2[1] = 1000;

    std::cout << std::setw(5) << "pos" << std::setw(8) << "array" << std::setw(8) << "array2" << std::setw(8) << "array3" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << array[i] << std::setw(8) << array2[i] << std::setw(8) << array3[i] << std::endl;
    }
}
void test9() {
    CS225::Integer::noise = false;
    std::cout << "dynamically allocate empty array and initialize it" << std::endl;
    CS225::Array * p_array = new CS225::Array;

    for ( int i=0; i<6; ++i ) {
        (*p_array)[i] = i+2;
    }

    CS225::Integer::noise = true;
    std::cout << "-------------------" << std::endl;
    std::cout << "create copy on stack" << std::endl;
    CS225::Array array2( *p_array );

    std::cout << std::setw(5) << "pos" << std::setw(8) << "p_array" << std::setw(8) << "array2" << std::endl;
    for ( int i=0; i<6; ++i ) {
        std::cout << std::setw(5) << i << std::setw(8) << (*p_array)[i] << std::setw(8) << array2[i] << std::endl;
    }

    CS225::Integer::noise = true;
    std::cout << "delete dynamically allocated array" << std::endl;
    delete p_array;

    std::cout << "check stack array is good, modify and print" << std::endl;
    std::cout << std::setw(5) << "pos" << std::setw(8) << "array2" << std::endl;
    for ( int i=0; i<6; ++i ) {
        array2[i] = i+100;
        std::cout << std::setw(5) << i << std::setw(8) << array2[i] << std::endl;
    }
}
void test10() {
    // correctness self-assignment test in Array
    CS225::Integer::noise = false;
    std::cout << "create empty array" << std::endl;
    CS225::Array array;

    for ( int i=0; i<6; ++i ) {
        array[i] = i+2;
    }

    CS225::Integer::noise = true;
    std::cout << "-------------------" << std::endl;
    std::cout << "create copy " << std::endl;
    CS225::Array array2( array ); 

    CS225::Integer::noise = true;
    std::cout << "assign shallow copies" << std::endl;
    array = array2; // aren't they the same ?
}
void test11() {
    CS225::Integer::noise = false;
    std::cout << "create empty array" << std::endl;
    CS225::Array array;

    for ( int i=0; i<6; ++i ) {
        array[i] = i+2;
    }

    CS225::Integer::noise = true;
    std::cout << "create const copy array" << std::endl;
    CS225::Array const array_const( array );

    std::cout << "array_const[3] is " << array_const[3] << std::endl;
    std::cout << "array_const[5] is " << array_const[5] << std::endl;
    //array_const[5] = 6; // should not compile
}
void test12() {
    CS225::Integer::noise = false;
    std::cout << "create empty array" << std::endl;
    CS225::Array array;

    for ( int i=0; i<6; ++i ) {
        array[i] = i+2;
    }

    CS225::Integer::noise = true;
    std::cout << "create shallow copy array2" << std::endl;
    CS225::Array array2( array );
    
    std::cout << "access aroginal (read), no deep copy required" << std::endl;
    std::cout << "array[5] = " << array[5] << std::endl;
    //array_const[5] = 6; // should not compile
}
void test13();

void (*pTests[])() = { test0,test1,test2,test3,test4,test5,test6,test7,
	test8,test9,test10,test11,test12,test13
}; 

void test13() {
	for (size_t i = 0; i<sizeof(pTests)/sizeof(pTests[0])-1; ++i) 
		pTests[i]();
}

#include <cstdio> /* sscanf */
int main (int argc, char ** argv) {
    if (argc >1) {
        int test = 0;
        std::sscanf(argv[1],"%i",&test);
        try {
            pTests[test]();
        } catch( const char* msg) {
            std::cerr << msg << std::endl;
        }
    }
    return 0;
}
