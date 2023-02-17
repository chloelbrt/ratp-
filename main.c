
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka.h"
#include <string.h>
#include "ratp.h"
#include "age.h"

/* A test case that does nothing and succeeds. */



static int setup(void **state) {
    (void) state;
    printf("setUp");
 return 0;
}
static int teardown(void **state) {
    (void) state;
    printf("tearDown");
     return 0;
}
static void null_test_success(void **state) {
    (void) state;
}

static void test_inf_12 (void **state){
    (void) state ;
    will_return(recupAge , 12);
    float prix;
    expect_function_calls(recupAge, 1);
    prix = computePrice(6);
    //assert_float_equal(0.74 , prix , 0.001);
    assert_true (0.74==prix);
}

//mock declaration
int getTemp(){return mock();}
static void Temp20(void **state){
    (void) state ;
    //define mock behavior
    will_return(getTemp,20);
    assert_int_equal(Heating(),1);
}

void recupAge( int * ageLimit){
    function_called();
    * ageLimit = (int) mock();
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test_setup(test_inf_12 , setup)
    };
 //   cmocka_set_message_output(CM_OUTPUT_XML);

    assert_float_equal( 1,1,1);
    return cmocka_run_group_tests_name("toto",tests, setup, teardown);
    

}
