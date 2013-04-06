/* 
 * File:   fir.h
 * Author: juanignaciobraun
 *
 * Created on April 3, 2013, 10:58 PM
 */

#define TAP_LENGTH 4
#define SIGNAL_LENGTH 10

typedef float sample_t;

void ini_fir (sample_t coefs[]);

sample_t fir(sample_t muestra);
