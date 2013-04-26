#define TAP_LENGTH 128 // Cantidad de coeficientes del filtro.
#define SIGNAL_LENGTH 1024 // Cantidad de muestras;
#define update_p(p){	             \
    if (p+1<0){                      \
        p = TAP_LENGTH + p + 1;      \
    } else if (p+1>TAP_LENGTH-1){    \
        p = p + 1 - TAP_LENGTH;      \
    } else {                         \
        p = p + 1;                   \
    }                                \
} 
 
typedef float sample_t;
 
void ini_fir(sample_t coefs[]);
 
sample_t fir(sample_t muestra);
 

