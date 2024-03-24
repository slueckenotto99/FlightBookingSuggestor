/*

    Flight Booking Suggestor object declarations header file

*/

#ifndef __FBS_OBJ__
#define __FBS_OBJ__

// System hookups
#include "tripgen_obj.h"

static class tripgen_obj_t * tripgen;

void    runtime_check( char override );
void    runtime_check( void );
void    user_tripgen_inputs( tripgen_inputs_t &inp);
void    init( void );
void    close( void );
int     main();

#endif